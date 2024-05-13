#ifndef VECTOR_H
#define VECTOR_H

#include <iostream>
#include <algorithm> // Įtraukti std::swap

/**
 * @brief Dinaminio masyvo realizacija, panaši į std::vector.
 * 
 * @tparam T Saugomų elementų tipas vektoriuje.
 */
template <typename T>
class Vector {
private:
    T *m_data; ///< Rodiklis į dinamiškai priskirtą masyvą.
    size_t capacity_; ///< Dabartinis vektoriaus talpumas.
    size_t length; ///< Dabartinis elementų skaičius vektoriuje.

public:
    // Narių tipai
    typedef T value_type; ///< Saugomų elementų tipas vektoriuje.
    typedef T& reference; ///< Nuoroda į vektoriaus elementą.
    typedef const T& const_reference; ///< Konstantinė nuoroda į vektoriaus elementą.
    typedef T* iterator; ///< Iteratorius, skirtas peržiūrėti vektoriaus elementus.
    typedef const T* const_iterator; ///< Konstantinė iteratoriaus versija, skirta peržiūrėti vektoriaus elementus.
    typedef std::ptrdiff_t difference_type; ///< Ženklintas sveikasis skaičius, kuris nurodo skirtumą tarp dviejų iteratorių.
    typedef size_t size_type; ///< Nenulinis sveikasis skaičius, nurodantis vektoriaus dydį.

    // Konstruktorius
    /**
     * @brief Sukuria tuščią vektorių.
     */
    Vector() : m_data(nullptr), capacity_(0), length(0) {}

    // Dekstruktorius
    /**
     * @brief Sunaikina vektorių, atlaisvindamas dinamiškai priskirtą atmintį.
     */
    ~Vector() {
        delete[] m_data;
    }

    // Kopijavimo konstruktorius
    /**
     * @brief Sukuria vektorių su kitų vektoriaus turiniu.
     * 
     * @param other Kopijuojamas vektorius.
     */
    Vector(const Vector &other) : m_data(nullptr), capacity_(0), length(0) {
        *this = other;
    }

    // Kopijavimo priskyrimo operatorius
    /**
     * @brief Priskiria kito vektoriaus turinį šiam vektoriui.
     * 
     * @param other Kopijuojamas vektorius.
     * @return Vector& Nuoroda į šį vektorių po priskyrimo.
     */
    Vector &operator=(const Vector &other) {
        if (this != &other) {
            clear();
            reserve(other.size());
            for (size_t i = 0; i < other.size(); ++i) {
                push_back(other.m_data[i]);
            }
        }
        return *this;
    }

    // Perkėlimo konstruktorius
    /**
     * @brief Sukuria vektorių perkeliant kitų vektoriaus turinį.
     * 
     * @param other Perkeliamas vektorius.
     */
    Vector(Vector &&other) noexcept : m_data(nullptr), capacity_(0), length(0) {
        *this = std::move(other);
    }

    // Perkėlimo priskyrimo operatorius
    /**
     * @brief Priskiria kito vektoriaus turinį šiam vektoriui perkeliant.
     * 
     * @param other Perkeliamas vektorius.
     * @return Vector& Nuoroda į šį vektorių po perkelimo priskyrimo.
     */
    Vector &operator=(Vector &&other) noexcept {
        if (this != &other) {
            clear();
            m_data = other.m_data;
            capacity_ = other.capacity_;
            length = other.length;
            other.m_data = nullptr;
            other.capacity_ = 0;
            other.length = 0;
        }
        return *this;
    }

    // Pridėti elementą į galą
    /**
     * @brief Prideda elementą į vektoriaus galą.
     * 
     * Jei vektorius pilnas, jo talpumas padidinamas dvigubai prieš pridedant elementą.
     * 
     * @param value Pridedamas elemento vertė.
     */
    void push_back(const T &value) {
        if (length >= capacity_) {
            reserve(capacity_ == 0 ? 1 : capacity_ * 2);
        }
        m_data[length++] = value;
    }

    // Išimti elementą iš galo
    /**
     * @brief Išima elementą iš vektoriaus galo.
     * 
     * Elementas yra tik pašalinamas iš vektoriaus, bet ne atlaisvinama jo užimta atmintis.
     */
    void pop_back() {
        if (length > 0) {
            --length;
        }
    }

    // Išvalyti vektorių
    /**
     * @brief Išvalo vektorių, pašalindamas visus jo elementus.
     */
    void clear() {
        length = 0;
    }

    // Rezervuoti vietą elementams
    /**
     * @brief Rezervuoja vietą vektoriuje tam tikram elemento skaičiui.
     * 
     * @param new_capacity Naujas vektorius talpumas.
     */
    void reserve(size_t new_capacity) {
        if (new_capacity > capacity_) {
            T *new_data = new T[new_capacity];
            for (size_t i = 0; i < length; ++i) {
                new_data[i] = std::move(m_data[i]);
            }
            delete[] m_data;
            m_data = new_data;
            capacity_ = new_capacity;
        }
    }

    // Gauk vektoriaus talpumą
    /**
     * @brief Gražina vektoriaus talpumą.
     * 
     * @return size_t Vektoriaus talpumas.
     */
    size_t capacity() const {
        return capacity_;
    }

    // Pakeisti vektoriaus dydį
    /**
     * @brief Keičia vektoriaus dydį.
     * 
     * @param new_size Naujas vektoriaus dydis.
     */
    void resize(size_t new_size) {
        reserve(new_size);
        length = new_size;
    }

    // Gauk vektoriaus dydį
    /**
     * @brief Gražina vektoriaus dydį.
     * 
     * @return size_t Vektoriaus dydis.
     */
    size_t size() const {
        return length;
    }

    // Patikrink, ar vektorius yra tuščias
    /**
     * @brief Patikrina, ar vektorius yra tuščias.
     * 
     * @return true, jei vektorius tuščias, false, jei vektorius netuščias.
     */
    bool empty() const {
        return length == 0;
    }

    // Pasiekite elementą pagal indeksą naudodami []
    /**
     * @brief Pasiekia elementą pagal indeksą naudodami [] operatorių.
     * 
     * @param index Indeksas, pagal kurį norima pasiekti elementą.
     * @return T& Nuoroda į elementą pagal nurodytą indeksą.
     * @throw std::out_of_range Jei indeksas nepatenka į ribas.
     */
    T &operator[](size_t index) {
        if (index >= length)
            throw std::out_of_range("Indeksas už ribų");
        return m_data[index];
    }

    // Pasiekite elementą pagal indeksą naudodami [] operatorių (konstantinė versija)
    /**
     * @brief Pasiekia elementą pagal indeksą naudodami [] operatorių (konstantinė versija).
     * 
     * @param index Indeksas, pagal kurį norima pasiekti elementą.
     * @return const T& Konstantinė nuoroda į elementą pagal nurodytą indeksą.
     * @throw std::out_of_range Jei indeksas nepatenka į ribas.
     */
    const T &operator[](size_t index) const {
        if (index >= length)
            throw std::out_of_range("Indeksas už ribų");
        return m_data[index];
    }

    // Gauk iteratorių į vektoriaus pradžią
    /**
     * @brief Gražina iteratorių į vektoriaus pradžią.
     * 
     * @return T* Iteratorius į vektoriaus pradžią.
     */
    T *begin() {
        return m_data;
    }

    // Gauk konstantinį iteratorių į vektoriaus pradžią
    /**
     * @brief Gražina konstantinį iteratorių į vektoriaus pradžią.
     * 
     * @return const T* Konstantinis iteratorius į vektoriaus pradžią.
     */
    const T *begin() const {
        return m_data;
    }

    // Gauk iteratorių į vektoriaus pabaigą
    /**
     * @brief Gražina iteratorių į vektoriaus pabaigą.
     * 
     * @return T* Iteratorius į vektoriaus pabaigą.
     */
    T *end() {
        return m_data + length;
    }

    // Gauk konstantinį iteratorių į vektoriaus pabaigą
    /**
     * @brief Gražina konstantinį iteratorių į vektoriaus pabaigą.
     * 
     * @return const T* Konstantinis iteratorius į vektoriaus pabaigą.
     */
    const T *end() const {
        return m_data + length;
    }

    // Pasiekite pirmąjį elementą
    /**
     * @brief Pasiekia vektoriaus pirmąjį elementą.
     * 
     * @return T& Nuoroda į vektoriaus pirmąjį elementą.
     * @throw std::out_of_range Jei vektorius yra tuščias.
     */
    T &front() {
        if (length == 0)
            throw std::out_of_range("Vektorius yra tuščias");
        return m_data[0];
    }

    // Pasiekite pirmąjį elementą (konstantinė versija)
    /**
     * @brief Pasiekia vektoriaus pirmąjį elementą (konstantinė versija).
     * 
     * @return const T& Konstantinė nuoroda į vektoriaus pirmąjį elementą.
     * @throw std::out_of_range Jei vektorius yra tuščias.
     */
    const T &front() const {
        if (length == 0)
            throw std::out_of_range("Vektorius yra tuščias");
        return m_data[0];
    }

    // Pasiekite paskutinį elementą
    /**
     * @brief Pasiekia vektoriaus paskutinį elementą.
     * 
     * @return T& Nuoroda į vektoriaus paskutinį elementą.
     * @throw std::out_of_range Jei vektorius yra tuščias.
     */
    T &back() {
        if (length == 0)
            throw std::out_of_range("Vektorius yra tuščias");
        return m_data[length - 1];
    }

    // Pasiekite paskutinį elementą (konstantinė versija)
    /**
     * @brief Pasiekia vektoriaus paskutinį elementą (konstantinė versija).
     * 
     * @return const T& Konstantinė nuoroda į vektoriaus paskutinį elementą.
     * @throw std::out_of_range Jei vektorius yra tuščias.
     */
    const T &back() const {
        if (length == 0)
            throw std::out_of_range("Vektorius yra tuščias");
        return m_data[length - 1];
    }

    // Tiesioginis prieiga prie pagrindinio saugaus laikymo
    /**
     * @brief Tiesiogiai pasiekia požymį į laikomą kontinuacinę atmintį.
     * 
     * @return T* Rodiklis į laikomą kontinuacinę atmintį.
     */
    T *data() {
        return m_data;
    }

    // Tiesioginis prieiga prie pagrindinio saugaus laikymo (konstantinė versija)
    /**
     * @brief Tiesiogiai pasiekia požymį į laikomą kontinuacinę atmintį (konstantinė versija).
     * 
     * @return const T* Rodiklis į laikomą kontinuacinę atmintį.
     */
    const T *data() const {
        return m_data;
    }

    // Keisti dviejų vektorių turinį
    /**
     * @brief Keičia dviejų vektorių turinį.
     * 
     * @param other Kitas vektorius, su kuriuo keičiamasi turiniu.
     */
    void swap(Vector &other) noexcept {
        std::swap(m_data, other.m_data);
        std::swap(capacity_, other.capacity_);
        std::swap(length, other.length);
    }
};

#endif // VECTOR_H
