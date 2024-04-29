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


# The v2.0
## Tasks for the last update
- Doxygen Documentation
- Unit Testing
- Github Editing

## Doxygen Documentation
>[!WARNING]
> In this document I will try to run through everything you need to know, but it would be lovely if you would go to YouTube and watch a tutorial video, because I do not specialize in this area

### Installation and Usage
1. Firstly, head up to the [official Doxygen website][https://www.doxygen.nl/manual/index.html]
2. Press the download button and install the program for the desired OS
3. Set everything up and start the DoxygenWiz
4. Now select the exact folder of your project, where all the files are shown
5. Name your project, write your synopsis and the version, if you really need - add thee logo
6. Head up to Run window and press the **Run doxygen** button
7. Once the process finishes, just go right to your project files -> hmtl -> index.html
8. Open it and vola, you have your whole documentation

### Inside the code
>[!NOTE]
>Since Doxygen documentation only needs comments from header files, save your time and

1. Open all your project's haeder files and get ready for this long and exhausting job
2. First up, we need a little intro about how the comments are made and what are the rules:
   - **Comment Format:** Use a specific format for comments recognized by Doxygen, typically starting with /** or /*! to indicate a special comment block.
   - **Documentation Tags:** Utilize special tags like @brief, @param, @return, @see, etc., to provide structured information about your code elements.
   - **Class Documentation:** Document classes using /** blocks above the class declaration, providing descriptions, usage notes, and any relevant information.
   - **Function Documentation:** Document functions and methods with /** blocks preceding their declarations, including details such as parameters, return values, and usage examples.
   - **Variable Documentation:** Document variables using /** blocks above their declarations, specifying their purpose, usage guidelines, and any additional details.
   - **Grouping and Organization:** Group related elements together using \defgroup and \addtogroup commands to create logical hierarchies in your documentation.
   - **File-level Documentation:** Include file-level documentation using /** blocks at the beginning of each source file, describing its purpose, contents, and usage.
   - **Consistency and Clarity:** Maintain consistency in your commenting style and ensure clarity in your descriptions, making it easier for users to understand and navigate your documentation.
3. Now once you are all set, start commenting everything in your header files

     

 
