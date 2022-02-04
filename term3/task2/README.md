# A. Who let the Rock out?

### Time limit 1 second

### Memory limit 256Mb

### Input standard input or input.txt

### Output standard output or output.txt


Rick and Morty are again plowing the expanses of universes, but decided to limit themselves only to those whose numbers are less than M. They can teleport from the universe numbered z to the universe (z+1) mod M for a bottles of lemonade or to the universe (z2+1) mod M for b bottles of lemonade. Rick and Morty want to get from the universe with number x to the universe with number y. How many bottles of lemonade will Rick give for such a trip if he wants to spend them as little as possible?

### Input format
In a row, the number of bottles a for the first type of teleportation, the number of bottles b for the second type of teleportation, the number of universes M, the number of the starting universe x, the number of the final universe y (0 ≤ a, b ≤ 100, 1 ≤ M ≤ 106, 0 ≤ x, y < M) are given in a row.

### Output format
Print one number — the number of bottles of lemonade that Rick will give for such a trip.

---
# B. Rick for the Weekend

### Time limit 0.3 seconds

### Memory limit 256Mb

### Input standard input or input.txt

### Output standard output or output.txt


Rick needs to get to the interuniverse conference. He pays for each teleportation with bottles of lemonade, so he wants to spend them on the road as little as possible (he's going to the conference after all!). However, after K consecutive flights, Rick begins to feel very sick, and he goes to bed for the day. He knows all the existing teleportations. Now Rick wants to find a way (the lowest cost in bottles of lemonade), given that teleportation does not take time, and there are 10 minutes left before the conference (that is, he can make no more than K flights)!

### Input format
The first line contains the number of universes N, the number of existing teleportations M, the number of consecutive flights K, the number of Rick's universe S, the number of the conference universe F (2 ≤ N ≤ 300, 1 ≤ M ≤ 105, 1 ≤ K ≤ 300, 1 ≤ S ≤ N, 1 ≤ F ≤ N).

Next comes M lines specifying teleportations. The i-th line contains three natural numbers: Si, Fi and Pi, where Si is the number of the universe from which the i-th teleportation leads, Fi is the number of the universe to which the i-th teleportation leads, Pi is the cost of the i-th teleportation. 1 ≤ Si ≤ N, 1 ≤ Fi ≤ N, 1 ≤ Pi ≤ 106.

### Output format
Print one number - the minimum cost of the path suitable for the professor. If the professor cannot get to the conference in K nights, print the number -1.

---
# C. Wake Me Up When Rickember Ends

### Time limit 0.25 seconds

### Memory limit 256Mb

### Input standard input or input.txt

### Output standard output or output.txt


Now Rick needs to get from the universe with the number S to the universe with the number F. He knows all the existing teleports, and it would seem there is no problem. But, it's no secret that during his long life Rick quarreled with a lot of people. From his personal experience, he knows that when teleporting, there is a chance that he will be forced to answer for his words.

If Rick knows the probabilities of being pushed to the wall on all existing teleportations, help him calculate the minimum probability that he will still run into trouble.

### Input format
The first line contains the number of universes N (2 ≤ N ≤ 100), the number of existing teleportations M (1 ≤ M ≤ N ⋅ (N - 1) / 2), the starting universe S (1 ≤ S ≤ N) and the finite universe F (1 ≤ F ≤ N).

Next, in M lines, a description of teleportations is given in the format Si, Fi, Pi, where Si and Fi are the numbers of universes connected by the i-th teleportation (bidirectional teleports, 1 ≤ Si, Fi ≤ N), Pi is the probability of being beaten on the i-th teleportation as a percentage (0 ≤ Pi ≤ 100).

### Output format
The probability of being beaten with an accuracy of 10-6.

---
# D. Look What You Made Rick Do

### Time limit 1 second

### Memory limit 256Mb

### Input standard input or input.txt

### Output standard output or output.txt


Rick sends Morty on a journey through N universes. He has a list of all existing unidirectional teleports. In order for Morty not to get lost, Rick needs to find out between which universes there are paths, and between which there are not. Help him with this!

### Input format
The first line contains the number of universes N (1 ≤ N ≤ 1000). The next N lines are of length N, consist of zeros and ones, and define an adjacency matrix of universes. The unit in the i-th row of the j-th column denotes a teleport from the i-th universe to the j-th.

### Output format
Print a matrix where one in the i-th row of the j-th column denotes the existence of a path from the i-th universe to the j-th and zero - its absence.


---
# E. Ricked out (4 points)

### Time limit 1 second

### Memory limit 256Mb

### Input standard input or input.txt

### Output standard output or output.txt


Rick decided to feel like a businessman for a day!

There are several currency exchangers in the city. As part of this task, we believe that each exchanger specializes in only two currencies and can only perform operations with them. Perhaps there are exchangers specializing in the same currency pairs. Each exchanger has its own exchange rate: the exchange rate of A to B is the number of units of currency B issued for 1 unit of currency A. Also, each exchanger has a commission — the amount that you have to pay to perform the operation. The commission is charged in the currency that the client changes.

For example, if you want to exchange 100 US dollars for Russian rubles in an exchanger where the exchange rate is 29.75 and the commission is 0.39, you will receive (100 - 0.39) ⋅ 29.75 = 2963.3975 rubles (eh, there were times).

You know for sure that only N currencies are used in the city. We number them with the numbers 1, 2, ..., N. Then each exchanger represents 6 numbers: integers A and B are the numbers of the exchanged currencies, as well as real RAB, CAB, RBA and CBA - exchange rates and commissions when transferring from A to B and from B to A, respectively.

Rick has some amount in S currency. He wonders if it is possible, after several exchange operations, to increase his capital. Of course, he wants his money to be in S currency again at the end. Help him answer his question. Rick should always have a non-negative amount of money.

### Input format
The first line contains four numbers: N is the number of currencies, M is the number of exchangers, S is the currency that the Rik has, and V is the number of units of this currency. The next M lines contain 6 numbers each, which specify the description of the corresponding exchangers in the format described above. The numbers are separated by one or more spaces. The constraints are met 1<=S<=N<=100, V is a real number, .

In each exchanger, exchange rates and commissions are real numbers specified with an accuracy of no more than two decimal places in decimal representation, and .

Let's call the sequence of exchange operations simple if each exchanger is used in it no more than once. You can assume that the ratio of Rick's total sum to the original one will not exceed 104 for any simple sequence of operations.

### Output format
If Rick can increase his capital, output YES, otherwise output NO.
