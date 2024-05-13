#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <vector>
#include <string>
#include "studentas.h"
#include "funkcijos.h"

/**
 * @brief Enumeracija ContainerType apibrėžia konteinerio tipus.
 */
enum class ContainerType { None, Vector };

/**
 * @brief Enumeracija Action apibrėžia veiksmus.
 */
enum class Action { None, Generate, Sort };

/**
 * @brief Gauti konteinerio pasirinkimą iš vartotojo.
 * 
 * @return Konteinerio pasirinkimas.
 */
ContainerType getContainerChoice();

/**
 * @brief Gauti veiksmo pasirinkimą iš vartotojo.
 * 
 * @return Veiksmo pasirinkimas.
 */
Action getActionChoice();

/**
 * @brief Atlikti veiksmą, priklausomai nuo konteinerio ir veiksmo pasirinkimo.
 * 
 * @param containerChoice Konteinerio pasirinkimas.
 * @param actionChoice Veiksmo pasirinkimas.
 * @param sizes Studentų failų dydžių vektorius.
 */
void performAction(ContainerType containerChoice, Action actionChoice, const std::vector<int>& sizes);

/**
 * @brief Paleisti programą.
 */
void runApp();

#endif // FUNCTIONS_H
