# Specs
### To start this project's review, I need to give a little intro about my computer. I have a MacBook, with these specs:
    CPU: 2,3 GHz Quad-Core Intel Core i5 
    RAM: 6 GB 2133 MHz LPDDR3 
    SSD: Macintosh HD 
> [!IMPORTANT]
> All of the testing was done with the same files that contained 1000, 10000, 100000, 1000000, 10000000 students.

# Information about the project
## The rule of five
The "Rule of Five" is a programming guideline that outlines five essential C++ class members, which manipulate resources. If you define one of these operators, you should define the remaining four to ensure proper management of resources (such as memory) in your class.
## What does the rule of five contain?
### Destructor: 
Responsible for releasing resources allocated by the class. It's invoked when an object of the class is destroyed or goes out of scope.

     ~Studentas();
### Copy Constructor: 
Copies an object of the class, which uses the same resource(-es) as the original object. It's essential to ensure deep copying to avoid double deletion of the same resource.

    Studentas(const Studentas &other);
### Copy Assignment Operator: 
Corresponds to the " = " operator. It copies the given object into an existing object that already has the same or similar resources. It's crucial to ensure that existing resources are released before assigning new ones.

    Studentas &operator=(const Studentas &other);
### Move Constructor: 
Transfers resources from one object to another without copying them, simply transferring resource ownership. It's more efficient than deep copying because it doesn't copy resources but transfers them.

    Studentas(Studentas &&other) noexcept;
### Move Assignment Operator: 
Corresponds to the " = " operator but operates on moveable objects. Similar to the move constructor, it allows assigning another moveable object to an existing object, efficiently managing resources.

    Studentas &operator=(Studentas &&other) noexcept;

## Input/Output operator methods:
### Input and Output in the code:
#### Input: 
Input method let's us read the student data, which is a must.

    std::istream& operator>>(std::istream& is, Studentas& student)
#### Output: 
Output methods gives us the most crucial thing in our code - prints our results.

    std::ostream& operator<<(std::ostream& os, const Studentas& student)
>[!NOTE]
> These 2 parts are crucial for the code and without them they would simply not work

### Manual Usage: 
The operator >> method lets you manually input data from a stream (e.g., std::cin). With this method, you can directly input a student's name, surname, exam result, and homework grades from the terminal.

### Automatic Usage: 
The operator >> method can also automatically read data from another source, like a file. It enables reading from a file and populating a Student object with the data.



### To Screen: 
The operator << method allows you to display a Student object's data on the screen (e.g., std::cout). It outputs the student's name, surname, exam result, and homework grades to the terminal.

### To File: 
The operator << method can also be used to output data to a file. It lets you write a Student object's data to a file, which can later be read.

# The v1.5
## Structure
- `studentas.h` - Declaration of the Student class and its function descriptions.
- `zmogus.h` - Declaration of the abstract class Human and its function descriptions.
- `studentas.cpp` - Implementation of the Student class methods.

## Features
- Can create a new student and set their name, surname, homework, and exam results.
- Can calculate a student's average or median.
- Can calculate a student's final grade using either the average or median.
- Can generate random student data.

## Example usage

```
#include "studentas.h"
#include <iostream>

void testRuleOfFive()
{
    // Create an original student
    Studentas original("Mantas", "Globys");
    original.addNamuDarbas(8);
    original.addNamuDarbas(9);
    original.setEgzaminas(10);

    // Test copy constructor
    Studentas copy(original);
    cout << copy << endl;
    cout << original << endl;

    // Test copy assignment
    Studentas copyAssignment;
    copyAssignment = original;
    cout << copyAssignment << endl;
    cout << original << endl;

    // Test move constructor
    Studentas moved(std::move(original));
    cout << original << endl;
    cout << moved << endl;

    // Test move assignment
    Studentas moveAssignment;
    moveAssignment = std::move(moved);
    cout << moved << endl;
    cout << moveAssignment << endl;

    std::cout << "Rule of Five tests passed successfully!" << std::endl;

    int main(){
        testRuleOfFive();
}
```
## Timetable

| Number of Students | Time to Read Data (s) | Time to Sort Data (s) | Time to Divide Students (s) |
|--------------------|-----------------------|-----------------------|-----------------------------|
| 1000               | 0.034256341           | 0.000020692           | 0.000000411                 |
| 10000              | 0.247214881           | 0.000001050           | 0.000000340                 |
| 100000             | 2.334580174           | 0.000000970           | 0.000000178                 |
| 1000000            | 25.613205208          | 0.000000902           | 0.000000229                 |
| 10000000           | 237.982180909         | 0.000001003           | 0.000000174                 |

## Time comparison

    Comparing the two versions of the tables, it seems that v1.5 generally has slightly 
    lower times for reading data and dividing students across all student count categories. 
    However, v1.2 has slightly lower times for sorting data in some cases.

    In general, the differences between the two versions are relatively minor, so the choice 
    between them may not significantly impact the overall performance or interpretation of the data.
