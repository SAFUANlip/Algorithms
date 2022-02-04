# A. For milk

### Time limit 2 seconds

### Memory limit 256Mb

### Input standard input or input.txt

### Output standard output or output.txt


Leon and Matilda were going to go to the store for milk. Stansfield wants to catch them, so our comrades need to do it as soon as possible. What is the minimum number of streets that at least one of the guys will pass through (either Matilda, or Leon, or both together). We believe that both friends need to get to the store necessarily.

### Input format
The first line contains the number of vertices n (1 ≤ n ≤ 105), the number of edges m (0 ≤ m ≤ 105) and the vertex numbers of the graph leon, matilda, milk, in which Leon, Matilda and the milk store are located, respectively.

The next m lines contain the edges of the graph. Each line contains two numbers separated by a space if there is an edge between i and j. It is guaranteed that there are no loops and multi-edges in the graph.

### Output format
One number is the number of edges.


---
# B. Secret materials

### Time limit 1 second

### Memory limit 256Mb

### Input standard input or input.txt

### Output standard output or output.txt


John McClain radioed new information about the terrorists to the department with n police officers. He calls several employees and asks them to spread information around the department, knowing that each police officer has a connection with certain colleagues. John McClain wants the operation to be successful. But if a policeman calls a colleague from whom (perhaps not directly) I got the information myself, the terrorists will be able to track this call and interfere with the operation. If two employees notify one, nothing bad will happen. Help John McClain. Output NO if one of the policemen makes a mistake making a call. If everything goes well, print YES and the order in which the police will receive information, assuming that the police notify colleagues in ascending order of their numbers, and at the beginning John gives information to those who none of his colleagues can call.

### Input format
The first line contains a pair of integers n and m (1 ≤ n, m ≤ 105) — the number of vertices and edges of a given directed graph.

The next m lines contain descriptions of edges, one per line. Each of the rows contains two integers a and b (0 ≤ a, b < n) — the beginning and end of the edge.

### Output format
If there is no such order, then print "NO" (without quotes).

Otherwise, print "YES" to the first of the lines. In the second line, output a permutation of the vertex indices (integers from 0 to n - 1), such that for each edge its starting vertex is strictly to the left of its ending vertex.
