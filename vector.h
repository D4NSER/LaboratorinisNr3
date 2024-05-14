#ifndef VECTOR_H
#define VECTOR_H

#include <iostream>
#include <algorithm> // Include std::swap, std::sort, std::find, std::reverse
#include <sstream>
#include <cassert>
#include <chrono>  // Include for time measurement
#include <iomanip> // Include for output formatting

/**
 * @brief Dinaminio masyvo realizacija, panaši į std::vector.
 *
 * @tparam T Saugomų elementų tipas vektoriuje.
 */
template <typename T>
class Vector
{
private:
    T *m_data;        ///< Rodiklis į dinamiškai priskirtą masyvą.
    size_t capacity_; ///< Dabartinis vektoriaus talpumas.
    size_t length;    ///< Dabartinis elementų skaičius vektoriuje.

public:
    // Narių tipai
    typedef T value_type;                   ///< Saugomų elementų tipas vektoriuje.
    typedef T &reference;                   ///< Nuoroda į vektoriaus elementą.
    typedef const T &const_reference;       ///< Konstantinė nuoroda į vektoriaus elementą.
    typedef T *iterator;                    ///< Iteratorius, skirtas peržiūrėti vektoriaus elementus.
    typedef const T *const_iterator;        ///< Konstantinė iteratoriaus versija, skirta peržiūrėti vektoriaus elementus.
    typedef std::ptrdiff_t difference_type; ///< Ženklintas sveikasis skaičius, kuris nurodo skirtumą tarp dviejų iteratorių.
    typedef size_t size_type;               ///< Nenulinis sveikasis skaičius, nurodantis vektoriaus dydį.

    // Konstruktorius
    /**
     * @brief Sukuria tuščią vektorių.
     */
    Vector() : m_data(nullptr), capacity_(0), length(0) {}

    // Dekstruktorius
    /**
     * @brief Sunaikina vektorių, atlaisvindamas dinamiškai priskirtą atmintį.
     */
    ~Vector()
    {
        delete[] m_data;
    }

    // Kopijavimo konstruktorius
    /**
     * @brief Sukuria vektorių su kitų vektoriaus turiniu.
     *
     * @param other Kopijuojamas vektorius.
     */
    Vector(const Vector &other) : m_data(nullptr), capacity_(0), length(0)
    {
        *this = other;
    }

    // Kopijavimo priskyrimo operatorius
    /**
     * @brief Priskiria kito vektoriaus turinį šiam vektoriui.
     *
     * @param other Kopijuojamas vektorius.
     * @return Vector& Nuoroda į šį vektorių po priskyrimo.
     */
    Vector &operator=(const Vector &other)
    {
        if (this != &other)
        {
            clear();
            reserve(other.size());
            for (size_t i = 0; i < other.size(); ++i)
            {
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
    Vector(Vector &&other) noexcept : m_data(nullptr), capacity_(0), length(0)
    {
        *this = std::move(other);
    }

    // Perkėlimo priskyrimo operatorius
    /**
     * @brief Priskiria kito vektoriaus turinį šiam vektoriui perkeliant.
     *
     * @param other Perkeliamas vektorius.
     * @return Vector& Nuoroda į šį vektorių po perkelimo priskyrimo.
     */
    Vector &operator=(Vector &&other) noexcept
    {
        if (this != &other)
        {
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
    void push_back(const T &value)
    {
        if (length >= capacity_)
        {
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
    void pop_back()
    {
        if (length > 0)
        {
            --length;
        }
    }

    // Išvalyti vektorių
    /**
     * @brief Išvalo vektorių, pašalindamas visus jo elementus.
     */
    void clear()
    {
        length = 0;
    }

    // Rezervuoti vietą elementams
    /**
     * @brief Rezervuoja vietą vektoriuje tam tikram elemento skaičiui.
     *
     * @param new_capacity Naujas vektorius talpumas.
     */
    void reserve(size_t new_capacity)
    {
        if (new_capacity > capacity_)
        {
            T *new_data = new T[new_capacity];
            for (size_t i = 0; i < length; ++i)
            {
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
    size_t capacity() const
    {
        return capacity_;
    }

    // Pakeisti vektoriaus dydį
    /**
     * @brief Keičia vektoriaus dydį.
     *
     * @param new_size Naujas vektoriaus dydis.
     */
    void resize(size_t new_size)
    {
        reserve(new_size);
        length = new_size;
    }

    // Gauk vektoriaus dydį
    /**
     * @brief Gražina vektoriaus dydį.
     *
     * @return size_t Vektoriaus dydis.
     */
    size_t size() const
    {
        return length;
    }

    // Patikrink, ar vektorius yra tuščias
    /**
     * @brief Patikrina, ar vektorius yra tuščias.
     *
     * @return true, jei vektorius tuščias, false, jei vektorius netuščias.
     */
    bool empty() const
    {
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
    T &operator[](size_t index)
    {
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
    const T &operator[](size_t index) const
    {
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
    T *begin()
    {
        return m_data;
    }

    // Gauk konstantinį iteratorių į vektoriaus pradžią
    /**
     * @brief Gražina konstantinį iteratorių į vektoriaus pradžią.
     *
     * @return const T* Konstantinis iteratorius į vektoriaus pradžią.
     */
    const T *begin() const
    {
        return m_data;
    }

    // Gauk iteratorių į vektoriaus pabaigą
    /**
     * @brief Gražina iteratorių į vektoriaus pabaigą.
     *
     * @return T* Iteratorius į vektoriaus pabaigą.
     */
    T *end()
    {
        return m_data + length;
    }

    // Gauk konstantinį iteratorių į vektoriaus pabaigą
    /**
     * @brief Gražina konstantinį iteratorių į vektoriaus pabaigą.
     *
     * @return const T* Konstantinis iteratorius į vektoriaus pabaigą.
     */
    const T *end() const
    {
        return m_data + length;
    }

    // Pasiekite pirmąjį elementą
    /**
     * @brief Pasiekia vektoriaus pirmąjį elementą.
     *
     * @return T& Nuoroda į vektoriaus pirmąjį elementą.
     * @throw std::out_of_range Jei vektorius yra tuščias.
     */
    T &front()
    {
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
    const T &front() const
    {
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
    T &back()
    {
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
    const T &back() const
    {
        if (length == 0)
            throw std::out_of_range("Vektorius yra tuščias");
        return m_data[length - 1];
    }

    // Iterpkite elementą į vektorių
    /**
     * @brief Iterpkite elementą į vektorių.
     *
     * @param pos Iteratorius, rodantis į vietą, į kurią norima įterpti elementą.
     * @param value Įterpiamas elementas.
     * @return T* Iteratorius, rodantis į įterpto elemento poziciją.
     */
    T *insert(iterator pos, const T &value)
    {
        size_t index = pos - begin();
        if (length >= capacity_)
        {
            size_t new_capacity = capacity_ == 0 ? 1 : capacity_ * 2;
            reserve(new_capacity);
        }
        std::move_backward(begin() + index, end(), end() + 1);
        m_data[index] = value;
        ++length;
        return begin() + index;
    }

    // Pašalinkite elementą iš vektoriaus
    /**
     * @brief Pašalinkite elementą iš vektoriaus.
     *
     * @param pos Iteratorius, rodantis į vietą, iš kurios norima pašalinti elementą.
     * @return T* Iteratorius, rodantis į vietą, į kurią buvo perkeltas iteratorius.
     */
    T *erase(iterator pos)
    {
        size_t index = pos - begin();
        std::move(begin() + index + 1, end(), begin() + index);
        --length;
        return begin() + index;
    }

    // Pašalinkite elementus iš vektoriaus
    /**
     * @brief Pašalinkite elementus iš vektoriaus.
     *
     * @param first Iteratorius, rodantis į pirmąjį ištrinamą elementą.
     * @param last Iteratorius, rodantis į vieną elementą už paskutinio ištrinamojo.
     * @return T* Iteratorius, rodantis į vietą, į kurią buvo perkeltas iteratorius.
     */
    T *erase(iterator first, iterator last)
    {
        size_t start = first - begin();
        size_t end = last - begin();
        std::move(begin() + end, end, begin() + start);
        length -= end - start;
        return begin() + start;
    }

    // Surikiuokite vektorių
    /**
     * @brief Surikiuokite vektorių.
     */
    void sort()
    {
        std::sort(begin(), end());
    }

    // Surikiuokite vektorių naudodami palyginimo funkciją
    /**
     * @brief Surikiuokite vektorių naudodami palyginimo funkciją.
     *
     * @param comp Funkcija, naudojama lyginant elementus.
     */
    template <typename Compare>
    void sort(Compare comp)
    {
        std::sort(begin(), end(), comp);
    }

    // Atvirkštinė tvarka vektoriuje
    /**
     * @brief Atvirkštinė tvarka vektoriuje.
     */
    void reverse()
    {
        std::reverse(begin(), end());
    }

    // Pirmas pasikartojantis elementas vektoriuje
    /**
     * @brief Pirmas pasikartojantis elementas vektoriuje.
     *
     * @return T& Nuoroda į pirmą pasikartojantį elementą vektoriuje.
     * @throw std::logic_error Jei vektorius neturi pasikartojančių elementų.
     */
    T &first_duplicate()
    {
        for (size_t i = 0; i < length; ++i)
        {
            for (size_t j = i + 1; j < length; ++j)
            {
                if (m_data[i] == m_data[j])
                {
                    return m_data[i];
                }
            }
        }
        throw std::logic_error("Vektorius neturi pasikartojančių elementų");
    }

    // Gauk skaičių elementų, kurie atitinka sąlygą
    /**
     * @brief Gražina skaičių elementų, kurie atitinka sąlygą.
     *
     * @param pred Sąlygos funkcija.
     * @return size_t Skaičius elementų, kurie atitinka sąlygą.
     */
    template <typename Predicate>
    size_t count_if(Predicate pred)
    {
        size_t count = 0;
        for (const auto &element : *this)
        {
            if (pred(element))
            {
                ++count;
            }
        }
        return count;
    }

    // Gauti pirmą pasikartojantį elementą, kuris atitinka sąlygą
    /**
     * @brief Gražina pirmą pasikartojantį elementą, kuris atitinka sąlygą.
     *
     * @param pred Sąlygos funkcija.
     * @return T& Nuoroda į pirmą pasikartojantį elementą, kuris atitinka sąlygą.
     * @throw std::logic_error Jei vektorius neturi pasikartojančio elemento, kuris atitinka sąlygą.
     */
    template <typename Predicate>
    T &first_duplicate_if(Predicate pred)
    {
        for (size_t i = 0; i < length; ++i)
        {
            for (size_t j = i + 1; j < length; ++j)
            {
                if (m_data[i] == m_data[j] && pred(m_data[i]))
                {
                    return m_data[i];
                }
            }
        }
        throw std::logic_error("Vektorius neturi pasikartojančio elemento, kuris atitinka sąlygą");
    }

    // Surikiuoti vektorių pagal funkcijos rezultatą
    /**
     * @brief Surikiuoti vektorių pagal funkcijos rezultatą.
     *
     * @tparam Func Funkcijos tipas, kuris priima vektoriaus elemento tipą ir grąžina bool reikšmę.
     * @param func Funkcija, kurios rezultatas naudojamas rikiuojant elementus.
     */
    template <typename Func>
    void sort_by(Func func)
    {
        std::sort(begin(), end(), [&](const T &a, const T &b)
                  { return func(a) < func(b); });
    }

    // Gauti laiką, reikalingą funkcijos vykdymui
    /**
     * @brief Gauti laiką, reikalingą funkcijos vykdymui.
     *
     * @tparam Func Funkcijos tipas.
     * @tparam Args Funkcijos parametrų tipų aibė.
     * @param func Funkcija, kurios vykdymo laikas yra matuojamas.
     * @param args Funkcijos parametrai.
     * @return double Funkcijos vykdymo laikas sekundėmis.
     */
    template <typename Func, typename... Args>
    double benchmark(Func func, Args &&...args)
    {
        auto start = std::chrono::high_resolution_clock::now();
        func(std::forward<Args>(args)...);
        auto end = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> duration = end - start;
        return duration.count();
    }

    // Spausdinti vektorių į srautą
    /**
     * @brief Spausdinti vektorių į srautą.
     *
     * @param out Srautas, į kurį spausdinamas vektorius.
     * @param vec Spausdinamas vektorius.
     * @return std::ostream& Nuoroda į srautą, į kurį spausdinama.
     */
    friend std::ostream &operator<<(std::ostream &out, const Vector &vec)
    {
        out << "[";
        if (!vec.empty())
        {
            out << vec[0];
            for (size_t i = 1; i < vec.size(); ++i)
            {
                out << ", " << vec[i];
            }
        }
        out << "]";
        return out;
    }

    // Sukurti funkciją, kuri sukeičia vektoriaus elementų tvarką tarp nurodytų indeksų
    /**
     * @brief Sukeičia vektoriaus elementų tvarką tarp nurodytų indeksų.
     *
     * @param start Pradinis indeksas.
     * @param middle Vidurinis indeksas.
     * @param end Paskutinis indeksas.
     */
    void rotate(iterator start, iterator middle, iterator end)
    {
        size_t leftLength = middle - start;
        size_t rightLength = end - middle;
        Vector<T> temp(leftLength + rightLength); // Temporary vector to store rotated elements

        // Copy elements from the left side to temporary vector
        for (size_t i = 0; i < leftLength; ++i)
        {
            temp[i] = std::move(start[i]);
        }

        // Move elements from the right side to the original vector's left side
        for (size_t i = 0; i < rightLength; ++i)
        {
            start[i] = std::move(middle[i]);
        }

        // Move elements from the temporary vector to the original vector's right side
        for (size_t i = 0; i < leftLength; ++i)
        {
            start[rightLength + i] = std::move(temp[i]);
        }
    }
};

#endif // VECTOR_H
