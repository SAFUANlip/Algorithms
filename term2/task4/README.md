# 1. Hash table

### Time limit 0.2 seconds

### Memory limit 15Mb

### Input standard input or input.txt

### Output standard output or output.txt

Implement a data structure of the “set of rows" type based on a dynamic hash table with open addressing. Stored strings are non-empty and consist of lowercase Latin letters. The hash function of the string should be implemented by calculating the value of the polynomial by the Horner method. The initial size of the table should be equal to 8. Perform hashing when adding elements in the case when the table's fill factor reaches 3/4. The data structure must support the operations of adding a row to the set, deleting a row from the set and checking whether this row belongs to the set. 1_1. To resolve collisions, use quadratic probing. i-th sample g(k, i)=g(k, i-1) + i (mod m). m is the power of two. 1_2. To resolve collisions, use double hashing.

### Input format
Each row of input data specifies one operation on the set. An operation record consists of the type of operation and the line following it, separated by a space, on which the operation is performed. The type of operation is one of three characters: + means adding this string to the set; - means removing a string from the set; ? means checking whether a given string belongs to a set. When adding an element to a set, it is NOT GUARANTEED that it is missing from this set. When an element is removed from a set, it is NOT GUARANTEED that it is present in this set.

### Output format
The program should output one of two OK or FAIL lines for each operation.

For the operation '?': OK if the element is present in the set. FAIL otherwise.

For the '+' operation: FAIL if the element being added is already present in the set and therefore cannot be added. OK otherwise.

For the '-' operation: OK, if the element was present in the set and was successfully deleted. FAIL otherwise.

---

# 2_1. Athletes

### Time limit 0.1 second

### Memory limit 5Mb

### Input standard input or input.txt

### Output standard output or output.txt

A circus with a team of athletes arrived in the city of N. They want to surprise the citizens of the city of N — to build a tower of maximum height from their bodies. The tower is a chain of athletes, the first stands on the ground, the second stands on his shoulders, the third stands on the shoulders of the second, etc. Each athlete is characterized by strength si (kg) and mass mi (kg). Strength is the maximum mass that an athlete is able to hold on his shoulders. Unfortunately, none of the athletes can program, since they have been engaged in physical training all their lives, and they did not have time to learn programming languages. Help them, write a program that will determine the maximum height of the tower that they can make. It is known that if an athlete is heavier, then he is stronger: if mi > mj, then si > sj. Athletes of equal weight can have different strength.

### Input format
The input contains only pairs of integers — the mass and strength of athletes. The number of athletes is 1 ≤ n ≤ 100000. Mass and force are positive integers less than 2000000.

### Output format
The output must contain a natural number — the maximum height of the tower.

---

# 2_2. Requests for negotiations

### Time limit 0.1 second

### Memory limit 5Mb

### Input standard input or input.txt

### Output standard output or output.txt

A large IT firm has only one meeting room. Those who wish to confer fill out applications with the desired start and end time. Your task is to determine the maximum number of applications that can be satisfied. The number of applications is less than 100000.

### Input format
The input contains only pairs of integers — the beginnings and ends of applications.

### Output format
The output must contain a natural number — the maximum number of applications.

---

# 3_1. High Pyramid

### Time limit 0.1 second

### Memory limit 5Mb

### Input standard input or input.txt

### Output standard output or output.txt

Given N cubes. It is required to determine how many ways you can build a pyramid from these cubes. Each overlying layer of the pyramid should be no larger than the underlying one.

### Input format
The number of cubes N is fed to the input .

### Output format
Print the number of different pyramids from N cubes.

---

# 3_2. Wide pyramid

### Time limit 0.1 second

### Memory limit 5Mb

### Input standard input or input.txt

### Output standard output or output.txt

Given N cubes. It is required to determine how many ways you can build a pyramid from these cubes. Each overlying layer of the pyramid must be strictly smaller than the underlying one.

### Input format
The number of cubes N is fed to the input .

### Output format
Print the number of different pyramids from N cubes.

---

# 4_1. The farthest vertex

### Time limit 0.1 second

### Memory limit 5Mb

### Input standard input or input.txt

### Output standard output or output.txt

An unweighted tree is given. The distance between two vertices will be called the number of edges in the path connecting these two vertices. For each vertex, determine the distance to the farthest vertex from it.

### Input format
The first line contains the number of vertices n ≤ 10000. This is followed by an n - 1 line describing the edges of the tree.
Each edge is two different integers - the indices of vertices in the range [0, n-1].
The root index is 0. In each edge, the parent vertex is the one whose number is smaller.

### Output format
The output must contain n lines. The i-th line displays the distance from the i-th vertex to the furthest from it.

---

# 4_2. The sum of the lengths to the rest

### of the time limit is 0.1 seconds

### Memory limit 5Mb

### Input standard input or input.txt

### Output standard output or output.txt

An unweighted tree is given. The distance between two vertices will be called the number of edges in the path connecting these two vertices. For each vertex, determine the sum of the distances to all other vertices. The operating time should be O(n).

### Input format
The first line contains the number of vertices n ≤ 10000. This is followed by an n - 1 line describing the edges of the tree. Each edge is two different integers - the indices of vertices in the range [0, n-1]. The root index is 0. In each edge, the parent vertex is the one whose number is smaller.

### Output format
The output must contain n lines. The i-th line displays the sum of the distances from the i-th vertex to all the others.
