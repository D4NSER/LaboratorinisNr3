# Specs
### To start this project's review, I need to give a little intro about my computer. I have a MacBook, with these specs:
    CPU: 2,3 GHz Quad-Core Intel Core i5 
    RAM: 6 GB 2133 MHz LPDDR3 
    SSD: Macintosh HD 
> [!IMPORTANT]
> All of the testing was done with the same files that contained 1000, 10000, 100000, 1000000, 10000000 students.

# The v3.0
## Creating my own vector
>[!NOTE]
>Creating this vector was a really hard and long process, so I am very sorry if I have missed or haven't done something fully

### Overview
This repository contains an implementation of a dynamic array, similar to std::vector, written in C++. The Vector class template provides a flexible array that can grow dynamically as elements are added. It supports a wide range of functionalities, from basic operations to advanced features like sorting and benchmarking.

### Key Features
- Dynamic resizing
- Copy and move semantics
- Range-based operations
- Sorting and reversing
- Element access and manipulation
- Performance benchmarking

### Examples and testing
#### Test 1: Basic Operations
**This test demonstrates basic operations such as adding, removing, and accessing elements.**

The code:
```
#include "Vector.h"
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

#### Test 2: Copy and Move Semantics
**This test illustrates the copy and move constructors and assignment operators.**

The Code:
```
#include "Vector.h"
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

