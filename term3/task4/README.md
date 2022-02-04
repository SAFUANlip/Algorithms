# A. Second statistics

### Time limit 1 second

### 64Mb memory limit

### Input standard input or input.txt

### Output standard output or output.txt

Given a number N and a sequence of N integers. Find the second ordinal statistics on the given ranges.

To solve the problem, use the Sparse Table data structure. The required processing time for each range is O(1). Time to prepare the data structure O(nlogn).

### Input format
- The first line contains 2 numbers: the size of the sequence N and the number of ranges M.
- The next N integers define the sequence. Next, M pairs of numbers are introduced - the boundaries of the ranges.
- It is guaranteed that each range contains at least 2 elements.
### Output format
For each of the M ranges, print an element of the sequence - the 2nd ordinal statistics. One number per line.
