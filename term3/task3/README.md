# A. MST-1 (2 points)

### Time limit 1 second

### Memory limit 256Mb

### Input standard input or input.txt

### Output standard output or output.txt

It is required to find a minimum weight spanning tree in a connected graph.

##### Use the Prim algorithm.

### Input format
The first line of the input file contains two natural numbers n and m — the number of vertices and edges of the graph, respectively. The next m lines contain a description of the edges, one per line. Edge number i is described by three natural numbers bi, ei and wi - the numbers of the ends of the edge and its weight, respectively (1 ≤ bi, ei ≤ n, 0 ≤ wi ≤ 100,000). n ≤ 5 000, m ≤ 100 000.

The graph is connected.

### Output format
The first line of the output file must contain one natural number — the weight of the minimum spanning tree.


---
# B. MST-2 (3 points)

### Time limit 1 second

### Memory limit 256Mb

### Input standard input or input.txt

### Output standard output or output.txt


It is required to find a minimum weight spanning tree in a connected graph.

##### Use the Kruskal algorithm.

### Input format
The first line of the input file contains two natural numbers n and m — the number of vertices and edges of the graph, respectively. The next m lines contain a description of the edges, one per line. Edge number i is described by three natural numbers bi, ei and wi - the numbers of the ends of the edge and its weight, respectively (1 ≤ bi, ei ≤ n, 0 ≤ wi ≤ 100,000). n ≤ 20 000, m ≤ 100 000.

The graph is connected.

### Output format
The first line of the output file must contain one natural number — the weight of the minimum spanning tree.


---
# C. Make me connected (4 points)

### Time limit 2 seconds

### Memory limit 256Mb

### Input standard input or input.txt

### Output standard output or output.txt

You are given an undirected graph consisting of n vertices. There is a number written on each vertex; the number written on vertex i is ai. Initially, there are no edges in the graph.

You can add edges to the graph for a certain cost. For adding an edge between vertices x and y, you have to pay ax + ay coins. There are also m special offers, each of which is characterized by three numbers x, y and w, and means that you can add an edge between the vertices x and y for w coins. You don't have to use these special offers: if there is such a pair of vertices x and y, such that there is a special offer for it, you can still add an edge between them for ax + ay coins.

How many coins will you need minimally to make the graph connected? A graph is connected if it is possible to get from each vertex to any other vertex

### Input format
The first line contains two integers n and m (1 ≤ n ≤ 2 105 105, 0 ≤ m ≤ 2 ⋅ 105) — the number of vertices in the graph and special offers, respectively.

The second line contains n integers (1 ≤ ai ≤ 10^12) — the numbers written on the vertices.

Then follow m lines, each of which contains three integers x, y and w (1 ≤ x, y ≤ n, 1 ≤ w ≤ 10^12, x ≠ y), denoting a special offer: you can add an edge between the vertices x and y for w coins.

### Output format
Print a single integer — the minimum number of coins that must be spent to make the graph connected.

---
