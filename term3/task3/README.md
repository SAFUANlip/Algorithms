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
The first line contains two integers n and m (1 ≤ n ≤ 2 ⋅ 10^5, 0 ≤ m ≤ 2 ⋅ 10^5) — the number of vertices in the graph and special offers, respectively.

The second line contains n integers a1, a2, a3, ... an (1 ≤ ai ≤ 10^12) — the numbers written on the vertices.

Then follow m lines, each of which contains three integers x, y and w (1 ≤ x, y ≤ n, 1 ≤ w ≤ 10^12, x ≠ y), denoting a special offer: you can add an edge between the vertices x and y for w coins.

### Output format
Print a single integer — the minimum number of coins that must be spent to make the graph connected.

---

# D. Broken Bridge (4 points)

### Time limit 1 second

### Memory limit 256Mb

### Input standard input or input.txt

### Output standard output or output.txt


Shrek needs to get into the tower to save the beautiful Princess Fiona. And now his path lies through an old dilapidated bridge. The donkey is very afraid of falling from this bridge into the lava river below it and refuses to go further until the bridge is completely repaired. Shrek can't go without a friend and decided to repair it.

The bridge is a field of n × m cells, with some cells still intact. Shrek has only 1 × 2 tablets, the installation of which takes him a seconds, and 1 × 1, the installation of which takes b seconds. He needs to close all the empty cells, and only them, without putting the plates on top of each other.

Determine the minimum number of seconds after which Shrek and the Donkey will be able to continue their journey further.

### Input format
The first line of the input file contains 4 integers n, m, a, b (1 ≤ n, m ≤ 100, |a/ ≤ 1,000, |b| ≤ 1,000). Each of the following n lines contains m characters: the symbol "." (dot) denotes the whole cell of the bridge, and the symbol "*" (asterisk) is empty.

### Output format
Output one number to the output file — the minimum number of seconds after which our heroes will be able to continue their journey by closing the empty cells of the bridge (them and only them).


---
# E. Stupid quarrel (4 points)

### Time limit 1 second

### Memory limit 256Mb

### Input standard input or input.txt

### Output standard output or output.txt
Shrek and the Donkey were already on their way home. They had only to overcome the forest that separated them from the swamp. But they quarreled, so they don't want to go together.

The forest consists of edges numbered from 1 to n and connected by m paths (there may be several paths connecting two edges, there may be paths connecting the edge with themselves). Because of a quarrel, if one of the friends walked along the path, then the second one can no longer walk along the same path. Now friends are at the edge with the number s, and Shrek's swamp is at the edge with the number t. Help Shrek and the Donkey get to the swamp.

### Input format
The first line of the file contains four integers - n, m, s and t (2 ≤ n ≤ 105, 0 ≤ m ≤ 105, s ≠ t). The next m lines contain pairs of numbers. A pair of numbers (x, y) means that there is a path from the edge of x to the edge of y (due to the terrain features, the paths are one-sided).

### Output format
If there is a solution, then print YES and on two separate lines, first the sequence of edges for Shrek, then the path for the Donkey.

If there is no solution, print NO.

If there are several solutions, output any one.


---

# F. Seating of guests (3 points)

### Time limit 1 second

### Memory limit 256Mb

### Input standard input or input.txt

### Output standard output or output.txt


Shrek and Fiona invited all their friends to their wedding. At the ceremony, they want to seat them all into two non-empty parts so that the number of acquaintances between the two parts is minimal. There are n people invited to the wedding, and each acquaintance is mutual.

You are given a graph in which an edge means acquaintance between people. Help Shrek and Fiona divide the guests into two non-empty parts.

### Input format
The first line of the input file contains an integer n (2 ≤ n ≤ 50) — the number of guests. Each of the following n lines contains n characters. the ith character of the jth of these lines is "1" if there is an edge between the vertices i and j, and "0" otherwise. The adjacency matrix defined in this way is antireflexive (there are zeros on the main diagonal) and symmetric (relative to the main diagonal).

### Output format
Output two lines to the output file. On the first one, print the numbers of the vertices that fell into the left part, separated by a space, and on the second - the numbers of the vertices that fell into the right part, also separated by a space. The vertex numbers can be output in any order.
