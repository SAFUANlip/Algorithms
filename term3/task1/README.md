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


---
# C. Districts, blocks, residential areas

### Time limit 1 second

### Memory limit 256Mb

### Input standard input or input.txt

### Output standard output or output.txt


Frank got a new order again. However, this time the city is playing by very strange rules: all roads in the city are one-way and connect only the offices of the employers of the carrier. A set of offices, between any two of which there is a path, form a block if no others can be added so that the condition is met. Frank is wondering what is the minimum number of one-way roads still need to be built so that the whole city becomes a quarter.

### Input format
The first line contains a pair of integers n and m (1 ≤ n ≤ 105, 0 ≤ m ≤ 105) — the number of vertices and edges of a given directed graph.

The next m lines contain descriptions of edges, one per line. Each of the lines contains two integers a and b (1 ≤ a, b ≤ n) — the beginning and end of the edge.

### Output format
Print one number — the number of roads that need to be added so that the whole city becomes one block.

---
# D. "Touch of Death" or a five-point strike

### Time limit 1 second

### 64Mb memory limit

### Input standard input or input.txt

### Output standard output or output.txt


Beatrix Kiddo was a mercenary in her youth and loved to make graphs of connections between her goals. She hung needles on the wall and tied them with threads. But since she is half Japanese, she especially liked when the goals could be arranged so that the threads did not intersect. You know the scheme that Beatrix wants to draw. Find out if she might like the scheme this time?

### Input format
v:number of Beatrix goals (max. 1000), n: number of links between goals (max. 3000), n pairs of links.

### Output format
YES, if Kiddo can draw a scheme that she likes, NO - if she can't.
