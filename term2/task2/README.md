# 1_1. Boxes

### Time limit 2 seconds

### Memory limit 52Mb

### Input standard input or input.txt

### Output standard output or output.txt

A lot of empty boxes were brought to the warehouse. All boxes are numbered in the order of receipt from 0.
It is known that they can all be stacked one into one (that is, so that each next one fits into the previous one). One box can be nested in another if it can be turned over so that the dimensions of one box on all axes become strictly smaller than the dimensions of the other box on the corresponding axes.
It is required to determine in what order they will be nested into each other. Output the mailbox numbers.
The maximum number is 10000.

---

# 1_2. Polyline 1

### Time limit 2 seconds

### 64Mb memory limit

### Input standard input or input.txt

### Output standard output or output.txt

Given N points on the plane. Specify the (N − 1)-link non-self-intersecting open polyline passing through all these points.
Note: Construct the polyline in ascending order of the x-coordinate. If there are two points with the same x-coordinate, then place the point whose y-coordinate is smaller earlier.

---

# 1_3. Closed polyline

### Time limit 3 seconds

### 64Mb memory limit

### Input standard input or input.txt

### Output standard output or output.txt

Given N points on the plane. Specify the (N-1)-link non-self-intersecting closed polyline passing through all these points.
It is assumed that no three points lie on the same straight line.
Construct a polyline from the point having the smallest x coordinate. If there are several such points, then use the point with the smallest y coordinate. Arrange the points on the polyline in descending order of the angles of the rays from the starting point to all other points.
To sort the points, implement an insertion sorting algorithm.

### Input format
The first line contains a singular number — the number of points N. N ≤ 10000. The next N lines contain the coordinates of the points xi, yi. All coordinates are integers xi, yi ≤ 100000.

### Output format
The dots are in the required order.

---

# 1_4. Lines

### Time limit 1 second

### Memory limit 19Mb

### Input standard input or input.txt

### Output standard output or output.txt

Write a program that prints a set of strings in lexicographic order.
The lines are separated by the newline character ’∖n’. If the last character in the input stream is ’∖n’, assume that there is no empty line after it. It is known that either n<100, or n≤1000, but the number of inversions in this set of rows is less than 100. The maximum string length is 255 characters. Write your own string comparison function. Sort by inserts.

---

# 1_5. Database

### Time limit 1 second

### 64Mb memory limit

### Input standard input or input.txt

### Output standard output or output.txt

The database stores N records of the type (Name, a1, a2, ... , ak) — all records have the same number of parameters. The priority of the fields is given to the input of the task — a permutation on the numbers 1,...,k - records must be output in accordance with this priority. If the priority of the fields is as follows: 3 4 2 1, then it should be perceived as follows: it should be read as: the priority of values from column 3 is the highest, the priority of values from column 4 is lower, the priority of values from column 2 is even lower, and the priority of values from column 1 is the lowest.

### Input format
N (1⩽N⩽1000) k (1⩽k;⩽10) p1 p2 ... pk (permutation on k numbers, space separator) N lines of the form Name a1 a2 ... ak (space delimiter)

### Output format
N rows with names according to priority

---

# 2_1. Advertising

### Time limit 0.05 seconds

### 64Mb memory limit

### Input standard input or input.txt

### Output standard output or output.txt

The supermarket decided to optimize the display of advertising. The schedule of arrival and departure of buyers (two integers) is known. Each buyer needs to show at least 2 ads. Ads can only be broadcast at integer points in time. The buyer can see the advertisement from the moment of arrival to the moment of leaving the store. Only one ad can be displayed at a time. It is believed that ads are displayed instantly. If an advertisement is shown at the time of departure or arrival, it is considered that the visitor has had time to watch it.
It is required to determine the minimum number of ad impressions.

---

# 2_2. Contemporaries

### Time limit 0.05 seconds

### 64Mb memory limit

### Input standard input or input.txt

### Output standard output or output.txt
A group of people is called contemporaries if there was a moment when they could get together. To do this, at this moment, each of them should have already turned 18 years old, but not yet 80 years old. A list of the Lives of Great People is given. It is necessary to get the maximum number of contemporaries. On the day of the 18th anniversary, a person can already take part in meetings, but on the day of the 80th anniversary and on the day of death, he can no longer.
Remark. A person could not live to his 18th birthday, or die on the day of his 18th birthday. In these cases, he could not take part in meetings.

---

# 2_3. Painting a straight line

### Time limit 0.05 seconds

### 64Mb memory limit

### Input standard input or input.txt

### Output standard output or output.txt

N segments were colored on the numerical line.
The coordinates of the left and right ends of each segment are known [Li, Ri]. Find the length of the colored part of the numeric line.
N ≤ 10000. Li, Ri are integers in the range [0, 10^9].

### Input format
The first line contains the number of segments.
The coordinates of the left and right ends of the segment are written in each subsequent line separated by a space.

### Output format
Print an integer — the length of the colored part.

---

# 2_4. Painting a straight line in one layer

N segments were colored on the numerical line.
The coordinates of the left and right ends of each segment are known [Li, Ri]. Find the sum of the lengths of the parts of the numerical line painted in exactly one layer.
N ≤ 10000. Li, Ri are integers in the range [0, 10^9].

### Input format
The first line contains the number of segments.
The coordinates of the left and right ends of the segment are written in each subsequent line separated by a space.

### Output format
Print an integer — the length of the part painted in one layer.

---

# 3. Порядковая статистика

### Ограничение времени	1 секунда

### Ограничение памяти	16Mb

### Ввод	стандартный ввод или input.txt

### Вывод	стандартный вывод или output.txt

Даны неотрицательные целые числа n, k и массив целых чисел из диапазона [0..10^9] размера n.
Требуется найти k-ю порядковую статистику. т.е. напечатать число, которое бы стояло на позиции с индексом k ∈[0..n-1] в отсортированном массиве.
Напишите нерекурсивный алгоритм.
Требования к дополнительной памяти: O(n).
Требуемое среднее время работы: O(n).
Функцию Partition следует реализовывать методом прохода двумя итераторами в одном направлении.
Описание для случая прохода от начала массива к концу:
Выбирается опорный элемент.
Опорный элемент меняется с последним элементом массива.
Во время работы Partition в начале массива содержатся элементы, не бОльшие опорного. Затем располагаются элементы, строго бОльшие опорного. В конце массива лежат нерассмотренные элементы. Последним элементом лежит опорный.
Итератор (индекс) i указывает на начало группы элементов, строго бОльших опорного.
Итератор j больше i, итератор j указывает на первый нерассмотренный элемент.
Шаг алгоритма. Рассматривается элемент, на который указывает j. Если он больше опорного, то сдвигаем j. Если он не больше опорного, то меняем a[i] и a[j] местами, сдвигаем i и сдвигаем j.
В конце работы алгоритма меняем опорный и элемент, на который указывает итератор i.

---

# 4_1. The first k elements of a long sequence

### Time limit 0.1 seconds

### 64 MB memory limit

### Input standard input or input.txt

### Output standard output or output.txt

A very long sequence of integers of length n is given. It is required to output its smallest k elements in sorted form. The sequence may not fit in memory. The operating time is O(n * log(k)). Additional memory O(k). Use merge.

---

# 4_2. Sorting an almost ordered sequence

### Time limit 2 seconds

### Memory limit 1Mb

### Input standard input or input.txt

### Output standard output or output.txt

A sequence of integers a1 is given...an and a natural number k such that for any i, j: if j >= i + k, then a[i] <= a[j]. It is required to sort the sequence. The sequence can be very long. Operating time O(n * log(k)). Additional memory O(k). Use merge.

---

# 4_3. Number of inversions

### Time limit 1 second

### 64Mb memory limit

### Input standard input or input.txt

### Output standard output or output.txt

A sequence of integers from the range (-1000000000 .. 1000000000). The length of the sequence is not more than 1000000. The numbers are written one per line. The number of numbers is not specified. Let the number of elements be n, and the numbers are written in the array a = a[i]: i of [0..n-1]. It is required to print the number of such index pairs (i,j) from [0..n-1] that (i < j and a[i] > a[j]). Note: the number of inversions can be more than 4*1000000000 - use int64_t.

---

# 5_1. MSD for strings

### Time limit 1 second

### Memory limit 50Mb

### Input standard input or input.txt

### Output standard output or output.txt

An array of strings is given. The number of rows is not more than 100,000. Sort the array by the MSD bitwise sorting method by characters. The size of the alphabet is 256 characters. The last character of the string = '0'.

---

# 5_2. LSD for long long

### Time limit 1 second

### Memory limit 20Mb

### Input standard input or input.txt

### Output standard output or output.txt

An array of non-negative 64-bit integers is given. The number of numbers is not more than 1000000. Sort the array by the bitwise sorting method LSD by bytes.

---

# 5_3. Binary MSD for long long

### Time limit 1 second

### Memory limit 10Mb

### Input standard input or input.txt

### Output standard output or output.txt

An array of non-negative 64-bit integers is given. The number of numbers is not more than 1000000. Sort the array using the MSD method by bits (binary QuickSort).

---

# 5_4. Very fast sorting

### Time limit is 6 seconds

### Memory limit 1Gb

### Input standard input or input.txt

### Output standard output or output.txt

There is a recurrent sequence A1, A2, ..., AN, constructed according to the following rule: A1 = K Ai+1 = (Ai * M) & 0xFFFFFFFFu mod L It is required to find the sum of all elements odd in order in a non-decreasing sorted sequence modulo L. For input data 5 7 13 100, the sequence will be as follows: (7, 7*13mod100=91, 91*13mod100=83, 83*13mod100=79, 79*13mod100=27), that is, (10, 91, 83, 79, 27) Sorted sequence (7, 27, 79, 83, 91) Sum of elements in odd places = (10 + 79 + 91 ) mod 100 = 77 To represent the elements of the sequence, you must use the unsigned int data type. To get an array, use a loop

### Input format
N K M L

---

# 6. The fastest sorting

### The time limit is 20 seconds

### Memory limit 300Mb

### Input standard input or input.txt

### Output standard output or output.txt

An array of integers in the range [0..10^9] is given. The size of the array is a multiple of 10 and is limited from above by the value of 2.5 * 107 elements. All array values are elements of a pseudo-random sequence. It is necessary to sort the array elements in the shortest time and output every tenth element of the sorted sequence.
Implement sorting based on QuickSort.
The minimum set of optimizations to be implemented:
1. I/O optimization
2. Optimization of the selection of the reference element
3. Partition Optimization
4. Recursion optimization
5. Optimization of terminal recursion
