# Specs
**To start this project's review, I need to give a little intro about my computer. I have a MacBook, with these specs:**
    CPU: 2,3 GHz Quad-Core Intel Core i5 
    RAM: 6 GB 2133 MHz LPDDR3 
    SSD: Macintosh HD 
> [!IMPORTANT]
> All of the testing was done with the same files that contained 1000, 10000, 100000, 1000000, 10000000 students.

# Creating my own vector
>[!NOTE]
>Creating this vector was a really hard and long process, so I am very sorry if I have missed or haven't done something fully

## Overview
This repository contains an implementation of a dynamic array, similar to std::vector, written in C++. The Vector class template provides a flexible array that can grow dynamically as elements are added. It supports a wide range of functionalities, from basic operations to advanced features like sorting and benchmarking.

## Key Features
- **Dynamic resizing:** Automatically grows in size as elements are added.
- **Iterators:** Provides both regular and constant iterators for element access.
- **Element access:** Supports operator[], front(), back(), and other access methods.
- **Modifiers:** Includes push_back(), pop_back(), insert(), erase(), clear(), reserve(), and resize().
- **Algorithms:** Methods for sorting, reversing, and finding duplicates.
- **Utility functions:** Benchmarks for performance measurement and rotation of elements.

## Examples and testing
### Test 1: Basic Operations
**This test demonstrates basic operations such as adding, removing, and accessing elements.**

The Code:
```
#include "vector.h"
#include <iostream>

int main() {
    Vector<int> vec;
    vec.push_back(10);
    vec.push_back(20);
    vec.push_back(30);

    std::cout << "Vector: " << vec << std::endl;

    vec.pop_back();
    std::cout << "After pop_back: " << vec << std::endl;

    vec[0] = 15;
    std::cout << "After modifying first element: " << vec << std::endl;

    return 0;
}
```
The outcome we expect:

```
Vector: [10, 20, 30]
After pop_back: [10, 20]
After modifying first element: [15, 20]
```

### Test 2: Copy and Move Semantics
**This test illustrates the copy and move constructors and assignment operators.**

The Code:
```
#include "vector.h"
#include <iostream>

int main() {
    Vector<int> vec1;
    vec1.push_back(1);
    vec1.push_back(2);
    vec1.push_back(3);

    Vector<int> vec2 = vec1; // Copy constructor
    Vector<int> vec3 = std::move(vec1); // Move constructor

    std::cout << "vec2 (after copy): " << vec2 << std::endl;
    std::cout << "vec3 (after move): " << vec3 << std::endl;

    return 0;
}
```
The outcome we expect:
```
vec2 (after copy): [1, 2, 3]
vec3 (after move): [1, 2, 3]
```

### Test 3: Advanced Functionality
**This test showcases advanced functionalities like sorting, reversing, and finding duplicates.**

The Code:
```
#include "vector.h"
#include <iostream>

int main() {
    Vector<int> vec;
    vec.push_back(3);
    vec.push_back(1);
    vec.push_back(2);
    vec.push_back(2);

    vec.sort();
    std::cout << "After sorting: " << vec << std::endl;

    vec.reverse();
    std::cout << "After reversing: " << vec << std::endl;

    try {
        int duplicate = vec.first_duplicate();
        std::cout << "First duplicate: " << duplicate << std::endl;
    } catch (const std::logic_error &e) {
        std::cout << e.what() << std::endl;
    }

    return 0;
}
```

The outcome we expect:
```
After sorting: [1, 2, 2, 3]
After reversing: [3, 2, 2, 1]
First duplicate: 2
```
## Doxygen
>[!NOTE]
>The repository includes comprehensive Doxygen documentation. This documentation provides detailed descriptions of all classes, methods, and member variables.

### Installation and Usage
1. Firstly, head up to the [official Doxygen website](https://www.doxygen.nl/manual/index.html)
2. Press the download button and install the program for the desired OS
3. Set everything up and start the DoxygenWiz
4. Now select the exact folder of your project, where all the files are shown
5. Name your project, write your synopsis and the version, if you really need - add thee logo
6. Head up to Run window and press the **Run doxygen** button
7. Once the process finishes, just go right to your project files -> hmtl -> index.html
8. Open it and vola, you have your whole documentation

### Available Documentation Formats
**HTML:** Located in the `v3.0/html` directory. Open index.html to view.
**LaTeX:** Located in the `v3.0/latex` directory. Can be compiled to a PDF using a LaTeX editor.
**PDF:** A pre-generated PDF document is available in the repository for easy reference.
