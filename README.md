# Specs
### To start this project's review, I need to give a little intro about my computer. I have a MacBook, with these specs:
    CPU: 2,3 GHz Quad-Core Intel Core i5 
    RAM: 6 GB 2133 MHz LPDDR3 
    SSD: Macintosh HD 
> [!IMPORTANT]
> All of the testing was done with the same files that contained 1000, 10000, 100000, 1000000, 10000000 students.

# Test 1
### Vector

| Operation                  | 1000 students | 10000 students | 100000 students | 1000000 students | 10000000 students |
|----------------------------|---------------|----------------|-----------------|------------------|-------------------|
| Time to read data          | 0.0225548s    | 0.161925s      | 1.53185s        | 15.0604s         | 157.078s          |
| Time to sort data          | 0.0060379s    | 0.0560185s     | 0.54057s        | 5.98002s         | 56.9632s          |
| Time to divide students    | 0.000925204s  | 0.00864535s    | 0.0870169s      | 0.923641s        | 10.0699s          |

### List

| Operation                  | 1000 students | 10000 students | 100000 students | 1000000 students | 10000000 students |
|----------------------------|---------------|----------------|-----------------|------------------|-------------------|
| Time to read data          | 0.0230061s    | 0.163591s      | 1.51784s        | 16.9385s         | 154.424s          |
| Time to sort data          | 0.00428305s   | 0.0587323s     | 0.727277s       | 10.051s          | 117.749s          |
| Time to divide students    | 0.00102186s   | 0.00875401s    | 0.0931033s      | 1.01632s         | 9.35735s          |

### Deque

| Operation                  | 1000 students | 10000 students | 100000 students | 1000000 students | 10000000 students |
|----------------------------|---------------|----------------|-----------------|------------------|-------------------|
| Time to read data          | 0.021631s     | 0.162111s      | 1.50907s        | 15.497s          | 162.153s          |
| Time to sort data          | 0.00597704s   | 0.0568725s     | 0.541957s       | 5.85342s         | 60.6313s          |
| Time to divide students    | 0.000888919s  | 0.00879198s    | 0.0869602s      | 1.08464s         | 9.41827s          |


> [!NOTE]
> P.S. Changing structure's type from vector into list or deque, programs speed would actually change.

**DATA READING**: The impact on reading might not be significant and caught by a human eye, but if we change **_vector_** into either **_list_** or **_deque_** the time would be a little bit smaller 

**SORTING DATA**: 
- **_Vector_** provides the fastest sorting because it allows random access (RA), which is super good for _quicksort_ algorithm used in _sort_.
- **_List_** has it's own _sort_ method which is optimized for list operations. It is **slower** than **_vector_** because it cannot access random access (RA). It is quite fast because it is designed for quick and efficient insertions and deletions.
- **_Deque_** is the slowest from these 3 because it doesn't support access to random access (RA) and is not designed for it, making it the **slowest** one.

**DIVIDING STUDENTS**: 
- Using **_vector_** dividing might involve a lot of element shifting, especially if you're erasing elements from the middle.
- **_List_** should be more efficient than a **_vector_** for dividing because it can insert and remove elements without shifting others.
- **_Deque_** is better than a vector for middle insertions/removals but not as efficient as a list because of it's design.

In summary, if the structure of Studentas is changed from a **_vector_** to a **_list_** or **_deque_**, you might see improved performance in certain operations (like dividing students) due to the **_list's_** and **_deque's_** efficient insertion and deletion capabilities. However, sorting might be slower, especially for **_deque_**. The exact impact would depend on the specific operations and how they are implemented.

> [!WARNING]
> When doing these tests try to do as many as you can, because from the first sight, the differences may not be seen because of the varying time all of the actions take 

# Test 2
### Strategy 1

##### Vector
| Task                         | 1000 students | 10000 students | 100000 students | 1000000 students | 10000000 students |
|------------------------------|--------------|----------------|-----------------|------------------|-------------------|
| Time taken to read data      | 0.0228874s   | 0.166344s      | 1.59188s        | 15.4619s         | 165.159s          |
| Time taken to sort data      | 0.00589303s  | 0.0552494s     | 0.538313s       | 6.18915s         | 60.0473s          |
| Time taken to divide students| 0.000935161s | 0.00835907s    | 0.0876151s      | 1.10855s         | 11.3426s          |

##### List
| Task                         | 1000 students | 10000 students | 100000 students | 1000000 students | 10000000 students |
|------------------------------|--------------|----------------|-----------------|------------------|-------------------|
| Time taken to read data      | 0.0202555s   | 0.166206s      | 1.56521s        | 15.9532s         | 166.259s          |
| Time taken to sort data      | 0.00403285s  | 0.0604099s     | 0.799202s       | 10.1229s         | 114.698s          |
| Time taken to divide students| 0.000769389s | 0.0074186s     | 0.0936631s      | 0.969208s        | 9.71874s          |

##### Deque
| Task                         | 1000 students | 10000 students | 100000 students | 1000000 students | 10000000 students |
|------------------------------|--------------|----------------|-----------------|------------------|-------------------|
| Time taken to read data      | 0.0232768s   | 0.163882s      | 1.56918s        | 16.0526s         | 164.046s          |
| Time taken to sort data      | 0.00670575s  | 0.0587848s     | 0.616905s       | 6.67419s         | 59.6123s          |
| Time taken to divide students| 0.000968202s | 0.00842794s    | 0.09097s        | 0.964875s        | 10.6465s          |

### Implementing this strategy:
- **_Vector_**: May have some problems when splitting students into 2 containers because of the need for additional memory.
- **_List_**: They don't require any additional memory when splitting students into 2 dfferent containers, but they are slower than vectors because of slower random acccess (RA).
- **_Deque_**: They are much more efficient when it comes to splitting compared to others. They support insertion and deletion from all ends. They offer quite a fast reading and insertion but are still slower than vectors due to no access to random access (RA).

>[!NOTE]
>In comparison, vectors excel in reading speed but suffer in sorting time compared to lists and deques. Lists offer quicker sorting but slower reading compared to vectors. Deques provide an intermediary performance, particularly when splitting occurs infrequently but still aren't very fast.

### Strategy 2

##### Vector
| Task                         | 1000 students | 10000 students | 100000 students | 1000000 students | 10000000 students |
|------------------------------|--------------|----------------|-----------------|------------------|-------------------|
| Time taken to read data      | 0.0209572s   | 0.163544s      | 1.6192s         | 15.753s          | 165.401s          |
| Time taken to sort data      | 0.00586344s  | 0.0549243s     | 0.591112s       | 5.76212s         | 56.8978s          |
| Time taken to divide students| 0.000764175s | 0.00705321s    | 0.0999966s      | 0.880787s        | 9.8865s           |

##### List
| Task                         | 1000 students | 10000 students | 100000 students | 1000000 students | 10000000 students |
|------------------------------|--------------|----------------|-----------------|------------------|-------------------|
| Time taken to read data      | 0.0234302s   | 0.163621s      | 1.61604s        | 16.6939s         | 156.007s          |
| Time taken to sort data      | 0.00382998s  | 0.0571905s     | 0.777995s       | 10.065s          | 111.851s          |
| Time taken to divide students| 0.000549503s | 0.00595599s    | 0.0938836s      | 1.04645s         | 10.5176s          |

##### Deque
| Task                         | 1000 students | 10000 students | 100000 students | 1000000 students | 10000000 students |
|------------------------------|--------------|----------------|-----------------|------------------|-------------------|
| Time taken to read data      | 0.0203225s   | 0.162119s      | 1.59787s        | 16.8757s         | 156.693s          |
| Time taken to sort data      | 0.00546757s  | 0.0559585s     | 0.588068s       | 6.6712s          | 58.1088s          |
| Time taken to divide students| 0.00081878s  | 0.00721679s    | 0.0840498s      | 0.953856s        | 9.93604s          |

### Implementing this strategy:
- **_Vector_**: Using it, time increases with the number of students because of slower element removal even though reading and sorting are pretty much not affected due to fast random access (RA). Performance differentiates because of file sizes.
- **_List_**: Allos quick ellement removal and efficient classification. However, when it comes to sorting, list times get much longer due to random access (RA) issues, especially with large files.
- **_Deque_**: Student classification and sorting times are pretty fast but reading data is tragicly slow.

>[!NOTE]
>Considering all factors (reading time, sorting time, element removal time), the most effective strategy is to use the Vectors container. Despite potential slowdowns in element removal, vectors boast fast reading and sorting times due to their swift access capabilities. This makes them ideal for student classification tasks, especially when dealing with extensive files. Therefore, vectors emerge as the optimal choice, providing a balance between performance and efficiency in this scenario.

### Strategy 3
#### Vector
| Task                              | 1000 students | 10000 students | 100000 students | 1000000 students | 10000000 students |
|-----------------------------------|---------------|----------------|-----------------|------------------|-------------------|
| Time taken to read data           | 0.0234721s    | 0.16696s       | 1.63409s        | 15.7987s         | 170.903s          |
| Time taken to sort data           | 0.00544238s   | 0.0560425s     | 0.559435s       | 6.42106s         | 57.2009s          |
| Time taken to divide students     | 0.0011887s    | 0.00826525s    | 0.0977371s      | 1.02714s         | 11.0873s          |

#### List
| Task                              | 1000 students | 10000 students | 100000 students | 1000000 students | 10000000 students |
|-----------------------------------|---------------|----------------|-----------------|------------------|-------------------|
| Time taken to read data           | 0.0208152s    | 0.165998s      | 1.54981s        | 15.6058s         | 153.042s          |
| Time taken to sort data           | 0.00485212s   | 0.0577385s     | 0.730288s       | 10.3186s         | 111.985s          |
| Time taken to divide students     | 0.000438091s  | 0.00416862s    | 0.0714406s      | 0.814364s        | 8.21541s          |

#### Deque
| Task                              | 1000 students | 10000 students | 100000 students | 1000000 students | 10000000 students |
|-----------------------------------|---------------|----------------|-----------------|------------------|-------------------|
| Time taken to read data           | 0.0215544s    | 0.162368s      | 1.63176s        | 16.2804s         | 154.024s          |
| Time taken to sort data           | 0.00574811s   | 0.0559582s     | 0.577608s       | 6.46955s         | 58.3943s          |
| Time taken to divide students     | 0.00100723s   | 0.00996933s    | 0.117997s       | 1.33683s         | 13.8873s          |

## Overview
### Reading Time:
All containers exhibit similar reading times, which increase proportionally with the size of the data. This indicates that the reading time depends more on the size of the file and the complexity of the reading operations rather than the type of container used.

### Sorting Time:
In terms of sorting, the **Vector** performs the best, showing shorter times compared to **List** and **Deque**, especially with large data sizes. This could be due to the **Vector** efficiently managing memory and having better memory accessibility.

### Partitioning Time:
Deque slightly outperforms **Vector** and **List** in partitioning time. This might be because **Deque** can insert elements to the front and back much faster and can be more efficient in certain cases compared to **List**, which needs to go through all elements to insert them the desired position.

### Sorting and Partitioning Times in File:
Comparing sorting and partitioning times in the file, we observe that **Vector** performs the best, again due to efficient memory management and fast access to elements (RA).

### Most Efficient Container Usage:
Based on these results, **Vector** is the most efficient for sorting and partitioning operations. It exhibits the best sorting time both with small and large data quantities. Therefore, if fast sorting and partitioning are crucial, it is best to use the **Vector** container.

> [!NOTE]
> All of the tests were done once because of the time all of the tests require. To get much clearer results the tests should be repeated again and the average time would show a much betterr result. The data presented in all of these tests was from my own testing and all of the numbers are mine.

>[!CAUTION]
> These tests and the overview might contain some translating or timing mistakes, because it was done in a quite small amount of time to be perfected. Be careful of any mistakes that might occur.

# How to run the code?
## Makefile creation
>[!NOTE]
>The Makefile was designed to ensure successful linking of various files in the code. This tutorial will demonstrate a few different methods for setting up and using the Makefile builder to execute my code.

>[!WARNING]
>I did all of this on Mac, so the tutorial will be on both OS's just to make sure, you all are ready to go!


### First method (Windows Hard Method)
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

### Second method (MacBook Hard Method)
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

### Third method (The Smart One)
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
