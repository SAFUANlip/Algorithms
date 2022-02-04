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


---
# B. Booking system (4 points)

### Time limit 1 second

### 64Mb memory limit

### Input standard input or input.txt

### Output standard output or output.txt
LLC "New Railways" has instructed you to develop a ticket booking system for a new long-distance train route. The route passes through N stations numbered from 0 to N-1. The train capacity is limited.
The booking system consistently receives requests from passengers indicating the number of the starting and ending stations, as well as the number of tickets that the passenger wants to purchase.
The required processing speed for each request is O(nlogn).

### Input format
The first line contains the number N -- the number of stations (1 ≤ N ≤ 50,000).

The second line contains the initial number of tickets sold.
In the example, one ticket was sold on stages 0->1 and 4->5.

The third line shows the capacity of the train. In the fourth — the number of booking requests.
Then there are direct requests in the form of: the number of the starting station, the number of the final station, the number of tickets requested.

### Output format
It is necessary to output the numbers of requests that could not be completed due to lack of available seats.

---
# C. Artist and photographer (4 points)
### Time limit 1 second

### 64Mb memory limit

### Input standard input or input.txt

### Output standard output or output.txt
The avant-garde artist has a strip of multicolored canvas. At one time, he repaints a certain segment of the strip in a certain color. After each repainting, a specially trained photographer takes a picture of part of the resulting creation for the Museum of Modern Art. For proper exposure, you need to know the brightness of the darkest color on the segment selected by the photographer. Write a program to determine the brightness of the darkest color on the segment.

The required brightness detection rate is O(log N).
The color is given by three numbers R, G and B (0 ≤ R, G, B ≤ 255), its brightness = R + G + B.
The color (R1, G1, B1) is darker than the color (R2, G2, B2) if R1 + G1 + B1 < R2 + G2 + B2.

### Input format
The first line contains the number N -- the length of the segment (coordinates [0...N-1]).
This is followed by N lines of 3 numbers each -- the colors of the segment.
The next line contains the number K -- the number of repaints and photographs.
Then K lines are given describing the repainting and photographing.
In each such line there are 7 natural numbers: C, D, R, G, B, E, F, where [C, D] are the coordinates of the segment being repainted, (R, G, B) is the color of the painting, [E, F] is the segment being photographed.

### Output format
It is required to output K integers. Each number is the brightness of the darkest color on the segment [E, F] after the corresponding coloring.

---
# D. LCA (4 points)

### Time limit of 5 seconds

### 64Mb memory limit

### Input standard input or input.txt

### Output standard output or output.txt
Given a tree with a root containing (1 ≤ n ≤ 100,000) vertices numbered from 0 to n-1.
It is required to answer m (1 ≤ m ≤ 10,000,000) queries about the smallest common ancestor for a pair of vertices.
Requests are generated as follows. The numbers a1, a2 and the numbers x, y and z are given.
The numbers a3, ..., a2m are generated as follows: ai = (x a ai-2 + y ⋅ ai-1 + z) mod n.
The first query has the form (a1, a2). If the answer to the i-1st query is v, then the i-th query has the form ((a2i-1 + v) mod n, a2i).

To solve the problem, you can use the binary lifting method.

### Input format
The first line contains two numbers: n and m.
The root of the tree has the number 0.
The second line contains n-1 integers, the ith of these numbers is equal to the number of the parent of vertex i.
The third line contains two integers in the range from 0 to n-1: a1 and a2.
The fourth line contains three integers: x, y and z, these numbers are non-negative and do not exceed 109.

### Output format
Output to the output file the sum of the vertex numbers - responses to all queries.

---
# E. Super array of strings (4 points)

### Time limit 0.005 seconds

### Memory limit 500Kb

### Input standard input or input.txt

### Output standard output or output.txt
Implement the data structure “array of strings" based on a Cartesian tree by an implicit key with the following methods:
    // Adding a line to the position.\\
// All subsequent lines are shifted one position forward.\\
void InsertAt( int position, const std::string& value );\\
// Deleting a string from position.\\
// All subsequent lines are shifted one position back.\\  
    void DeleteAt( int position );\\
// Getting a string from position.\\  
    std::string GetAt( int position );
All methods should work in O(log n) on average, where n is the current number of rows in the array.

### Input format
The first line contains the number of commands
k ≤ 10^6.

The next k lines contain descriptions of commands:
The command "+ 10 hello"
means adding the hello string to position 10.
The command "- 14 16"
means deleting a line from position 14 to position 16.
The team“? 33"
means a request to output a string from the array at position 33.

### Output format
Output all the lines requested by the “?" commands.
