# Specs
**To start this project's review, I need to give a little intro about my computer. I have a MacBook, with these specs:**
    CPU: 2,3 GHz Quad-Core Intel Core i5 
    RAM: 6 GB 2133 MHz LPDDR3 
    SSD: Macintosh HD 
> [!IMPORTANT]
> All of the testing was done with the same files that contained 1000, 10000, 100000, 1000000, 10000000 students.

# Creating my own vector

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
### More tests
1. Test `push_back` and `size`:
```
Vector<int> vec;
vec.push_back(1);
vec.push_back(2);
assert(vec.size() == 2);
```
2. Test `pop_back` and `empty`:
```
Vector<int> vec;
vec.push_back(1);
vec.pop_back();
assert(vec.empty());
```
3. Test element access with `operator[]`:
```
Vector<int> vec;
vec.push_back(10);
assert(vec[0] == 10);
```
4. Test `sort` method:
```
Vector<int> vec;
vec.push_back(3);
vec.push_back(1);
vec.push_back(2);
vec.sort();
assert(vec[0] == 1 && vec[1] == 2 && vec[2] == 3);
```

## Its efficiency and speed and reallocations
>[!IMPORTANT]
>The performance of the Vector class is benchmarked against std::vector to ensure it is efficient in terms of time complexity and memory reallocations.

| Element Count  | `std::vector` Time (s) | `Vector` Time (s) | `std::vector` Reallocs | `Vector` Reallocs |
|----------------|------------------------|-------------------|------------------------|-------------------|
| 10,000         | 0.001619               | 0.000305          | 14                     | 14                |
| 100,000        | 0.009946               | 0.001816          | 17                     | 17                |
| 1,000,000      | 0.064191               | 0.014089          | 20                     | 20                |
| 10,000,000     | 0.752756               | 0.156575          | 24                     | 24                |
| 100,000,000    | 7.036739               | 1.725960          | 27                     | 27                |

The table above shows the time taken to perform operations on vectors of increasing sizes for both std::vector my our custom Vector class. The number of reallocations is also compared, demonstrating the efficiency and performance of the Vector class.

# Doxygen documentation
>[!NOTE]
>The repository includes comprehensive Doxygen[^1] documentation. This documentation provides detailed descriptions of all classes, methods, and member variables.

## Installation and Usage
1. Firstly, head up to the [official Doxygen website](https://www.doxygen.nl/manual/index.html)
2. Press the download button and install the program for the desired OS
3. Set everything up and start the DoxygenWiz
4. Now select the exact folder of your project, where all the files are shown
5. Name your project, write your synopsis and the version, if you really need - add thee logo
6. Head up to Run window and press the **Run doxygen** button
7. Once the process finishes, just go right to your project files -> hmtl -> index.html
8. Open it and vola, you have your whole documentation

## Available Documentation Formats
- **HTML:** Located in the `v3.0/html` directory. Open index.html to view.
- **LaTeX:** Located in the `v3.0/latex` directory. Can be compiled to a PDF using a LaTeX editor.
- **PDF:** A pre-generated PDF document is available in the repository for easy reference.
  
# Unit testing
The container created has been thoroughly tested using the Native Unit Testing[^2] via Visual Studio. The tests cover various functionalities of the Vector class, ensuring its correctness and reliability.

## About the Tests:

- **InitiallyEmpty:** Checks if the vector is initially empty.
- **PushBack:** Validates the push_back method.
- **PopBack:** Verifies the pop_back method.
- **Clear:** Ensures the clear method functions correctly.
- **Capacity:** Validates the capacity method.
- **Iterators:** Checks the functionality of iterators.
- **Sort:** Validates the sort method.
- **Reverse:** Ensures the reverse method works as expected.
- **AccessByIndex:** Verifies element access by index.
- **AccessByIndexOutOfRange:** Checks element access beyond boundaries.
- **CopyConstructor:** Validates the copy constructor.
- **CopyAssignmentOperator:** Ensures the copy assignment operator functions correctly.
- **MoveConstructor:** Verifies the move constructor.
- **MoveAssignmentOperator:** Validates the move assignment operator.
- **Insert:** Checks the insert method.
- **Erase:** Verifies the erase method.
- **IsSorted:** Ensures the is_sorted method functions correctly.
- **AccessInvalidIndex:** Checks access to elements using invalid indices.
- **SortPerformance:** Validates the performance of the sort method.
- **InsertAtDifferentPositions:** Checks insertion at different positions.
    
![image](![image](https://github.com/D4NSER/LaboratorinisNr3/assets/62251258/565f9d4f-7553-4e22-812a-5d7b019b95ca)

An interesting aspect is that using the C++ Unit Testing platform (CppUnitTest.h), tests can be easily created and executed directly from C++ code, allowing all tests to be compiled together with the main program. This simplifies the creation and execution of tests, eliminating the need for separate tools or environments, and provides immediate feedback on successful and failed tests.

# Creating a downloadable and installable setup wizard

## Preparing for the setup file creation

To be able to create my own setup installer I had to download a certain program because doing it on Visual Studio is a very long and hard way. To fasten the progress I downloaded [Inno Setup Compiler](https://inno-setup-compiler.en.lo4d.com/windows). Now once everything is setup we can begin.

## Creating the setup

- To begin creating the setup file we need to launch the program and press on the _Create new Inno Setup Script wizard_ button
- Then on the first page, you can  change everything how you like (Application name, its version, publisher and website)
- On the second screen we do nothing and press next
- On the third window, we need to locate the .exe file of the poject and provide it's location
- Then we need to add a whole folder of our project, which contains all of the files and press _Next_
- On the fourth window we ought to press next
- Now on the fifth window, we need to check 'Allow user to create a desktop shorcut' box, because this was listed in the task
- On the _Application Documentation_ window we do nothing and go further
- Same with the other window
- On the next window we also skip everything and press _Next_
- On the _Compiler settings_ window, we need to create a new folder, where the installed project's output will be going and put it's location
- Then optionally you can put the icon's file location if you have one and then press _Next_
- Now on the last window we press _Next_ and then _Finish_

## Running the setup

Once we've created the setup file, we need to firstly run the code to create the setup.exe file:

- Once created press _Yes_ twice and select the loccation of your project setup file
- Then press _Run_ button and wait for the code to finish. If you did everything correctly, this should be the screen after the code has finished creating the setup file:
![image](https://github.com/D4NSER/LaboratorinisNr3/assets/62251258/d9d2e4b5-8e8f-437d-a7f4-e5b43c87cd1a)
- Once everything is finished head up to the location you provided and run the .exe file that was created there. It should look like this:
![image](https://github.com/D4NSER/LaboratorinisNr3/assets/62251258/efd2d7ee-09d0-452e-9c29-f6ea4d9531b3)
- Once you've ran it, simply select what you need and give your administrative permissions, because the code needs it
- To check if the project has successfully been installed into your ccomputer, you can simply go to the location you provided for the project to be downloaded and all of these files should be there like this:
  ![image](https://github.com/D4NSER/LaboratorinisNr3/assets/62251258/b9fee2c7-cdd4-4881-ba3f-99cca00358d2)
![image](https://github.com/D4NSER/LaboratorinisNr3/assets/62251258/e7b0007e-f0c4-472b-bbb7-21b468fbe7c4)
- Once you've done everything there should've appeared a desktop shorcut file for the project, which once ran, should simply run thee project's code and if you did everything as listed it should work properly without any errors. The screen should be something like this:
![image](https://github.com/D4NSER/LaboratorinisNr3/assets/62251258/3e7320c3-b2ef-49ef-8c6e-2ab4a7c33c85)

# Preparing, creating, setuping and running your files
## Doxygen
>[!NOTE]
>Since Doxygen documentation only needs comments from header files, save your time and:

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

# Unit Testing

## IDE
    Well, for starters, I used Visual Studio 2022 for Unit testing as it is one of the best IDE's 
    for this kind of job. You can also use JetBrains as it is even better.
     
## Setting everything up
>[!NOTE]
>Unit Testing, overviewed in this documentation is called Native Unit Testing

### Preparing the project file
1. Firstly open **Visual Studio**
2. Press **Create New Project**
3. Select **Native Unit Testing** because VS will do all the job by creating and editing your properties you will need here
4. Now once the project is created head up to Project -> {name of the file} properties -> C/C++ -> All functions -> Precompiled Header and change it's value to **Not Using Precompiled Headers**
5. Now press **Apply** and **OK**
6. Now press Project button and add existing files that you will want to test
   
### Making last changes to code
1. Once you do this, just write new functions that test whatever you need
2. Once it is all done, go to **Test** and open the **Test Explorer**
3. Now just press **Run all test** and you have it
4. If any of the builds fail, you will know that something is not working and if it does work, you are set

# How to run the code?
## Makefile creation
>[!NOTE]
>The Makefile was designed to ensure successful linking of various files in the code. This tutorial will demonstrate a few different methods for setting up and using the Makefile builder to execute my code.

>[!WARNING]
>Please be discrete when following these steps and after installing the compiler - configure it, because it will not work :) 

## First method (Windows Hard Method)
1. **Go** to [this](https://sourceforge.net/projects/gnuwin32/files/make/3.81/) website, which navigates you into the compilator download link (the original site).
2. **Download** the latest version of it.
3. **Setup** the whole thing. It has quite clear intruction, but if you ever struggle, here's a [video](https://www.youtube.com/watch?v=taCJhnBXG_w) to help you!
4. Now, once you have this, head up to you **project** on File Explorer.
5. **Copy** the path of your project with all of the files (**INCLUDING THE MAKEFILE!**)
6. **Open** CMD (Command Prompt).
7. Type '**cd** ' and **paste** the path.
8. Now press enter and just to make sure, that you're in the right place, type '**ls**' and **check** if all the files are there.
9. Now just **type** 'make' and **wait**!
10. Once everything is done, simply **type** 'programa.exe' as it is my target in the makefile (the main file that all of other files got compiled to)
11. If **nothing** happends, you can add 'run' before the path.
12. **Have fun!**

## Second method (MacBook Hard Method)
1. **Go** to the app store or into the internet and download [Xcode](https://developer.apple.com/xcode/) because you will need a compilator.
2. **Start** the Xcode after installing and configuring it.
3. **Go** to _Xcode/Preferences_.
4. Head up to the "_Downloads_" tab.
5. Click on "_Components_".
6. Press "_Install_" on the **command line tools line**.
7. Once all of this is done, head up the Finder and **locate** your project with all of the files (**INCLUDING THE MAKEFILE!**)
8. Now open up the **terminal** and type '**cd** '.
9. Head back to the finder and press on the **name** of you **project**. A file with a plus should've appeared by now.
10. **Drag** that file with a plus right **into the terminal** and press enter.
11. To make sure, you are in the right project **type** '**ls**' and **check** if all of the files are there.
12. Now **type** './' and the name of the file (in my case it's **programa**)
13. **Enjoy your time!**

## Third method (The Smart One)
1. **Download** either Xcode or MinGW compilator (see above for both Windows and Mac).
2. Once the compilator is **installed** and set up. **Open** [VisualStudio Code](https://code.visualstudio.com/download).
3. Now open the **project**.
4. Go to the **extensions** tab and search for "**Makefile Tools**" By _Microsoft_.
5. **Download** it and then restart VSCode for it to actually get installed into your **IDE**.
6. Once this is done, press on the **extension** on the left side of the toolbar and you'll see 6 different paths, that the extension needs.
7. For **Windows**:
    - Edit the "**Make**" configuration to use mingw32-make.exe.
    - Edit the "**Makefile**" configuration and paste the project path.
8. For **MacBook**:
    - Edit the "**Make**" configuration to use /usr/bin/make.
    - Edit the "**Makefile**" configuration and paste the project path.
9. Now just press the "**Build**" button (top left one) which will build the project.
10. Then press the "**Run code**" button which will start it.
11. **Have fun!**


# References:
[^1]: Doxygen is a tool designed to automatically generate documentation from source code, primarily written in C++, but also supporting other programming languages. Its operation is based on specially written comment tags adjacent to the code. These tags, typically starting with the symbol /**, allow for writing structured and detailed documentation about code functions, class members, modules, and variables.
[^2]: Unit tests are intended to test individual parts (units) of a program to ensure they function correctly. This helps ensure that each part of the program performs the intended functions and behaves as expected.
