## Structures vs Classes
### The times using first strategy for vectors on my last project with structures

| Task                         | 1000 students | 10000 students | 100000 students | 1000000 students | 10000000 students |
|------------------------------|--------------|----------------|-----------------|------------------|-------------------|
| Time taken to read data      | 0.0228874s   | 0.166344s      | 1.59188s        | 15.4619s         | 165.159s          |
| Time taken to sort data      | 0.00589303s  | 0.0552494s     | 0.538313s       | 6.18915s         | 60.0473s          |
| Time taken to divide students| 0.000935161s | 0.00835907s    | 0.0876151s      | 1.10855s         | 11.3426s          |

### The times using first strategy for vectors on my new project with classes
| Task                         | 1000 students | 10000 students | 100000 students | 1000000 students | 10000000 students |
|------------------------------|--------------|----------------|-----------------|------------------|-------------------|
| Time taken to read data      | 0.029201059s | 0.236461103s   | 2.286535253s   | 23.812292017s   | 243.827573256s    |
| Time taken to sort data      | 0.000011250s | 0.000001052s   | 0.000000969s    | 0.000000979s    | 0.000000796s      |
| Time taken to divide students| 0.000000204s | 0.000000176s   | 0.000000179s    | 0.000000215s    | 0.000000179s      |

### Performance comparison:
>[!NOTE]
>I compared two ways of managing student data: using vectors with structures and vectors with classes. Across different dataset sizes, I measured how long it took to read data, sort it, and divide students.

- Generally, using vectors with structures was faster for all tasks compared to using vectors with classes. As the dataset size increased, the performance difference became more noticeable.

- For example, with a dataset of 10 million students, reading data took about 165 seconds with structures but around 244 seconds with classes. Sorting data for the same dataset took approximately 60 seconds with structures and just 0.000000796 seconds with classes.
### Final word
This test shows that using vectors with structures is more efficient for managing student data, especially for larger datasets.

## Test 2
>[!WARNING]
>To correectly do the project with my code, read the text below

### Running the code
- Firstly type:
  
      make optimize
- Then type this:

      ./programa_O1
      ./programa_O2
      ./programa_O3
- Then you just navigate through the menu and once you do the first project end the code.
- Then do the same once again 2 more times.

### The results of testing

01
Time taken to read data: 0.010067386s
Time taken to sort data: 0.000010172s
Time taken to divide students: 0.000000076s

Time taken to read data: 0.070018473s
Time taken to sort data: 0.000028232s
Time taken to divide students: 0.000000055s

Time taken to read data: 0.602062206s
Time taken to sort data: 0.000008321s
Time taken to divide students: 0.000000055s

Time taken to read data: 5.935979336s
Time taken to sort data: 0.000009304s
Time taken to divide students: 0.000000054s

Time taken to read data: 57.031392832s
Time taken to sort data: 0.000008972s
Time taken to divide students: 0.000000060s

02
Time taken to read data: 0.009378851s
Time taken to sort data: 0.000011912s
Time taken to divide students: 0.000000077s

Time taken to read data: 0.067764390s
Time taken to sort data: 0.000012910s
Time taken to divide students: 0.000000079s

Time taken to read data: 0.578626220s
Time taken to sort data: 0.000031495s
Time taken to divide students: 0.000000058s

Time taken to read data: 5.733824103s
Time taken to sort data: 0.000009755s
Time taken to divide students: 0.000000055s

Time taken to read data: 56.621991031s
Time taken to sort data: 0.000011455s
Time taken to divide students: 0.000000055s

03
Time taken to read data: 0.010082715s
Time taken to sort data: 0.000006497s
Time taken to divide students: 0.000000071s

Time taken to read data: 0.067679755s
Time taken to sort data: 0.000026754s
Time taken to divide students: 0.000000056s

Time taken to read data: 0.577418282s
Time taken to sort data: 0.000004985s
Time taken to divide students: 0.000000055s

Time taken to read data: 5.632994167s
Time taken to sort data: 0.000004704s
Time taken to divide students: 0.000000055s

Time taken to read data: 55.821169947s
Time taken to sort data: 0.000004734s
Time taken to divide students: 0.000000053s
