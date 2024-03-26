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

#### Using flag 01
| Time taken to read data (s) | Time taken to sort data (s) | Time taken to divide students (s) |
|------------------------------|-----------------------------|-----------------------------------|
| 0.010067386                  | 0.000010172                 | 0.000000076                       |
| 0.070018473                  | 0.000028232                 | 0.000000055                       |
| 0.602062206                  | 0.000008321                 | 0.000000055                       |
| 5.935979336                  | 0.000009304                 | 0.000000054                       |
| 57.031392832                 | 0.000008972                 | 0.000000060                       |

#### Using flag 02
| Time taken to read data (s) | Time taken to sort data (s) | Time taken to divide students (s) |
|------------------------------|-----------------------------|-----------------------------------|
| 0.009378851                  | 0.000011912                 | 0.000000077                       |
| 0.067764390                  | 0.000012910                 | 0.000000079                       |
| 0.578626220                  | 0.000031495                 | 0.000000058                       |
| 5.733824103                  | 0.000009755                 | 0.000000055                       |
| 56.621991031                 | 0.000011455                 | 0.000000055                       |


#### Using flag 03
| Time taken to read data (s) | Time taken to sort data (s) | Time taken to divide students (s) |
|------------------------------|-----------------------------|-----------------------------------|
| 0.010082715                  | 0.000006497                 | 0.000000071                       |
| 0.067679755                  | 0.000026754                 | 0.000000056                       |
| 0.577418282                  | 0.000004985                 | 0.000000055                       |
| 5.632994167                  | 0.000004704                 | 0.000000055                       |
| 55.821169947                 | 0.000004734                 | 0.000000053                       |

### Summary of the second test
>[!NOTE]
>To determine which flag performed the best overall, we can analyze the average time taken for each operation across all measurements for each flag:

#### Flag 01:
    Average time to read data: ~12.32 seconds
    Average time to sort data: ~0.00001354 seconds
    Average time to divide students: ~0.000000064 seconds

#### Flag 02:
    Average time to read data: ~12.14 seconds
    Average time to sort data: ~0.000015216 seconds
    Average time to divide students: ~0.000000064 seconds

#### Flag 03:
    Average time to read data: ~12.22 seconds
    Average time to sort data: ~0.000009779 seconds
    Average time to divide students: ~0.000000058 seconds

#### Overall
- Flag 01 has the fastest average time for sorting data.
- Flag 02 has the fastest average time for reading data.
- Flag 03 has the fastest average time for dividing students.
- Overall, the choice of the "best" flag depends on the specific requirements of the system. If sorting data is a critical operation, Flag 01 might be preferred. If reading data quickly is more important, Flag 02 could be chosen. And if dividing students efficiently is the priority, Flag 03 might be the best option.

## Comparing flags with structures and classes

### Classes

#### The size:
![image](https://github.com/D4NSER/LaboratorinisNr2/assets/62251258/35654bf9-c8b2-40c3-9f1a-661e75ffca2d)

#### The speed:
    Listed above 😄

### Struct

#### The size:
![image](https://github.com/D4NSER/LaboratorinisNr2/assets/62251258/9e7475ed-8c78-43a9-8234-fe3c54429621)

#### The speed:

#### Using flag 01
| Time taken to read data (s) | Time taken to sort data (s) | Time taken to divide students (s) |
|------------------------------|-----------------------------|-----------------------------------|
| 0.0253237                    | 0.00542445                  | 0.00109304                        |
| 0.173463                     | 0.0564751                   | 0.00871953                        |
| 1.52148                      | 0.514224                    | 0.0886106                         |
| 15.0471                      | 5.47558                     | 0.903104                          |
| 156.591                      | 55.1543                     | 9.4095                            |

#### Using flag 02
| Time taken to read data (s) | Time taken to sort data (s) | Time taken to divide students (s) |
|------------------------------|-----------------------------|-----------------------------------|
| 0.0236589                    | 0.00591004                  | 0.000866724                       |
| 0.164244                     | 0.0568401                   | 0.00946841                        |
| 1.51731                      | 0.529778                    | 0.0858304                         |
| 16.3108                      | 5.46567                     | 0.903327                          |
| 150.355                      | 53.7382                     | 9.1933                            |

#### Using flag 03
| Time taken to read data (s) | Time taken to sort data (s) | Time taken to divide students (s) |
|------------------------------|-----------------------------|-----------------------------------|
| 0.0242589                    | 0.00667387                  | 0.00149997                        |
| 0.164944                     | 0.057452                    | 0.00904067                        |
| 1.61769                      | 0.550876                    | 0.0872779                         |
| 15.0963                      | 5.56724                     | 0.900621                          |
| 150.852                      | 55.0109                     | 9.95332                           |

### Comparison

#### Reading Data:
- The classes approach generally shows faster reading times compared to the structure approach for all flags.

#### Sorting Data:
- The structure approach seems to perform slightly better in terms of sorting data across all flags, although the difference is not significant.

#### Dividing Students:
- The classes approach appears to have slightly faster times for dividing students compared to the structure approach across all flags.

#### Overall
- Overall, the classes approach tends to have better performance in terms of reading data and dividing students, while the structure approach performs slightly better in sorting data. However, the differences in performance between the two approaches are relatively minor and may vary depending on specific implementations and system configurations.
