# 1_1. Factorial zeros
Find how many zeros n ends with! = 1 * 2 * 3 * ... * n. n ≤ 1000.

---

# 1_2. Decomposition into simple
Print the decomposition of a natural number n into prime factors. The prime factors should be ordered in ascending order and separated by spaces. 2 ≤ n ≤ 10^6.

---

# 1_3. Сумма дробей
Four non-negative numbers a, b, c and d are given. Add two rational fractions a/b and c/d, and present their result as an irreducible fraction m/n. Print the numbers m and n. a, b, c, d ≤ 1000.

---

# 1_4. Сумма с большим делителем
Given a natural number N. Represent N as A + B, so that the NODE(A, B) is maximal, 1 ≤ A ≤ B. Output A and B. If multiple answers are possible, output the answer with the minimum A. 1 < n ≤ 10 000 000.

---

# 1_5. Squares
Print the squares of natural numbers from 1 to n using only O(n) addition and subtraction operations (multiplication cannot be used). n ≤ 1000.

---

# 1_6. Reverse order
Given an array of integers A[0..n). Without using other arrays, rearrange the elements of array A in reverse order for O(n). n ≤ 10000.

---

# 2_1. Maximum amount
Given two arrays of integers of the same length A[0..n-1] and B[0..n-1]. It is necessary to find the first pair of indices i0 and j0, , such that A[i 0] + B[j 0] = max {A[i] + B[j], where 0 <= i < n, 0 <= j < n, i <= j}.

The working time is O(n). n ≤ 100000.

---

# 2_2. The area of the n-gon
Calculate the area of a convex n-gon given by the coordinates of its vertices. First, the number of vertices is entered, then sequentially the integer coordinates of all vertices in clockwise order.

n < 1000, coordinates < 10000.

Indication. To calculate the area of the n-gon, you can calculate the sum of the oriented areas of the trapezoids under each side of the polygon.

---

# 2_3. Required amount
Two strictly increasing arrays of integers A[0..n) and B[0..m) and the number k are given. Find the number of such index pairs (i, j) that A[i] + B[j] = k. The operating time is O(n + m). n, m ≤ 100000.

Indication. Traverse the array B from the end to the beginning.

### Input format
In the first and second lines, the number of elements and the elements of the array A are entered.

In the third and fourth lines, the number of elements and the elements of array B are entered.

In the fifth line is the number k.

### Output format
Output the required number of pairs.

---

# 2_4. Counting
There are N people lined up in a circle, numbered from 1 to N. We will exclude every k-th until only one person survives.

For example, if N=10, k=3, then the 3rd will die first, then the 6th, then the 9th, then the 2nd, then the 7th, then the 1st, then the 8th, followed by the 5th, and then the 10th. Thus, the 4th will survive.

It is necessary to determine the survivor's number.

N, k ≤ 10000.

---

# 3_1. The next element
Given a sorted array of integers A[0..n-1] and an array of integers B[0..m-1]. For each element of array B[i], find the minimum index k of the minimum element of array A equal to or greater than B[i]: A[k] >= B[i]. If there is no such element, output n. The running time of the search k for each element B[i]: O(log(k)). n, m ≤ 10000.

### Input format
The first line contains the numbers n and m. In the second and third arrays A and B, respectively.

---

# 3_2. Unimodal sequence
Given an array of integers A[0..n-1]. It is known that on the interval [0, m] the values of the array strictly increase, and on the interval [m, n-1] they strictly decrease. Find m for O( log m ).
2 ≤ n ≤ 10000.

---

# 3_3. Intersection of sets
Two arrays of non-repeating integers are given, ordered in ascending order. A[0..n-1] and B[0..m-1]. n " m. Find their intersection. Required running time: O(m * log k), where k is the position of element B[m-1] in array A.. In the process of searching for the next element B[i] in the array A, use the result of the search for the element B[i-1]. n, k ≤ 10000.

---

# 3_4. Search for a twin
Given a sorted array of various integers A[0..n-1] and an array of integers B[0..m-1]. For each element of the array B[i], find the minimum index of the element of the array A[k] closest in value to B[i]. n ≤ 110000, m ≤ 1000. The running time of the search for each element B[i]: O(log(k)).

---

# 4_1. Queue with dynamic buffer
Implement a queue with a dynamic looped buffer.

Handle push back and pop front commands.

### Input format
In the first line, the number of commands is n. n ≤ 1000000.

Each command is given as 2 integers: a b.

a = 2 - pop front
a = 3 - push back

If the pop front command is given, then the number b is the expected value. If the pop front command is called for an empty data structure, then “-1” is expected.

### Output format
It is required to print YES - if all the expected values match. Otherwise, if at least one expectation was not met, then print NO.

---

# 4_2. Dec with dynamic buffer
Implement a deck with a dynamic looped buffer.

Handle push* and pop* commands.

### Input format
In the first line, the number of commands is n. n ≤ 1000000.

Each command is given as 2 integers: a b.

a = 1 - push front
a = 2 - pop front
a = 3 - push back
a = 4 - pop back
If the pop * command is given, then the number b is the expected value. If the pop * command is called for an empty data structure, “-1" is expected.

---

# 4_3. Queue using stack
Implement a queue using two stacks. Use a stack implemented with a dynamic buffer.

Handle push back and pop front commands.

### Input format
In the first line, the number of commands is n. n ≤ 1000000.

Each command is given as 2 integers: a b.

a = 2 - pop front
a = 3 - push back

If the pop front command is given, then the number b is the expected value. If the pop front command is called for an empty data structure, then “-1” is expected.

### Output format
It is required to print YES - if all the expected values match. Otherwise, if at least one expectation was not met, then print NO.

---

# 5_1. Bracket sequence
A fragment of a sequence of brackets consisting of the characters (){}[] is given. It is necessary to determine whether it is possible to continue the fragment in both directions, having received the correct sequence. The length of the original sequence is ≤ 800000.

### Input format
A string containing the characters (){}[] and possibly a line feed.

### Output format
If possible, output the minimum correct sequence, otherwise print "IMPOSSIBLE".

---

# 5_2. Stack anagrams
### Attention! To solve this problem, you need to use the stack data structure!

A pair of words is called a stack anagram if one word can be obtained from another by performing a sequence of stack operations with its letters (take the next letter of the source word and put it on the stack; take a letter from the stack and add it to the end of the output word). For a given pair of words, it is required to determine whether it is possible to perform a sequence of stack operations that translates the first word into the second. All the letters in the word are different. The length of the anagram is less than 10000.

### Input format
A couple of words that are an anagram.

### Output format
YES if a sequence of stack operations exists and NO otherwise.

---
# 5_3. Rectangles
A sequence of N rectangles of different widths and heights (wi, hi) is given. The rectangles are located, starting from the point (0, 0), on the axis OX close to each other (to the right).
It is required to find the M - area of the maximum rectangle (parallel to the coordinate axes) that can be cut from this figure.

The working time is O(n).

### Input format
The first line contains the number N (1 ≤ N ≤ 10000).
Next comes N lines. Each row contains two numbers width and height: the width and height of the i-th rectangle.
(0 < width ≤ 10000, 0 ≤ height ≤ 10000)

### Output format
Print the number M. (0 ≤ M ≤ 109)

---

# 5_4. Calculation of the expression
The expression is given in the infix entry. Calculate it using the translation of the expression into a postfix entry. The expression does not contain negative numbers. The number of operations is less than 100.

### Input format
A string consisting of their characters “0123456789-+*/ ()" It is guaranteed that the input expression is correct, there is no division by 0, it is computable in integers. Integer division.

### Output format
The meaning of the expression.

---

# 6_1. Greedy
Vovochka eats fruit from her grandmother's basket.
There are fruits of different weights in the basket. Vovochka can lift no more than K grams. Each fruit weighs no more than K grams. At a time, he selects several of the heaviest fruits that he can lift at the same time, bites off half of each and puts the cores back in the basket. If the fruit weighs an odd number of grams, it bites off the larger half. The fruit of the mass of 1gr he eats completely.

Determine how many approaches Vovochka will eat all the fruits in the basket.

### Input format
First, enter n - the number of fruits and n rows with the masses of fruits. n ≤ 50000.
Then K is "load capacity". K ≤ 1000.

### Output format
A non-negative number is the number of approaches to the basket.

---

# 6_2. Old computer
An old computer is used to add numbers. The time it takes to find the sum of two numbers is equal to their sum. Thus, it may take different time to find the sum of the numbers 1,2,3, depending on the order of calculations. ((1+2)+3) -> 1+2 + 3+3 = 9 ((1+3)+2) -> 1+3 + 4+2 = 10 ((2+3)+1) -> 2+3 + 5+1 = 11 It is required to write a program that determines the minimum time sufficient to calculate the sum of a given set of numbers. The required operating time is O(n*log(n)).

### Input format
First, enter n (n < 100) - the number of numbers. Then n rows are entered - the values of the numbers (the value of each number does not exceed 1,000,000,000, the sum of all the numbers does not exceed 2 * 1 000 000 000 ).

### Output format
The natural number is the minimum time.

---

# 6_3. Dead Ends
At the station there are a number of dead ends where trains arrive. This train station is their final station. The schedule of trains is given, in which the time of its arrival is indicated for each train, as well as the time of departure for the next flight. The trains in the schedule are ordered by arrival time. When the train arrives, it is put in a free dead end with a minimum number. At the same time, if the train from some dead end went at time X, then the train that arrives at time X cannot be put into this dead end, and the train arriving at time X +1 can be. At the moment, there are enough dead ends at the station to work according to the schedule. Write a program that, according to this schedule, determines the minimum number of dead ends required for the operation of the station.

### Input format
First, enter n - the number of commuter trains in the schedule. 1 ≤ n ≤ 100000. Then n lines are entered for each train, in the line - arrival time and departure time. Time is a natural number from 0 to 1,000,000,000. The lines in the schedule are ordered by arrival time.

### Output format
A natural number is the minimum number of dead ends.

# 6_4. Moving maximum
Given an array of integers A[0..n), n does not exceed 100,000. The size of some window (sequentially arranged array elements) in this array is also set to k, k<=n. It is required for each window position (from 0 to n-k) to output the maximum value in the window. The operating speed is O(n log n), the memory is O(n).

### Input format
First, enter n - the number of array elements. Then n lines are entered with the value of each element. Then the k-size of the window is entered.

### Output format
Space-separated maxima values for each window position.
