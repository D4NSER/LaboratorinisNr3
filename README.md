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

