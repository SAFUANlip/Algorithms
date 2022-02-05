# 1_1. Traversing the tree in in-order order

### Time limit 0.2 seconds

### 64Mb memory limit

### Input standard input or input.txt

### Output standard output or output.txt

Given a number N ≤ 10^4 and a sequence of integers from [-2^31..2^31] length N. It is required to build a binary tree specified by the naive insertion order. I.e., when adding the next number K to the tree with root root, if root→Key ≤ K, then node K is added to the right subtree root; otherwise, to the left subtree root. Output the elements in in-order order (from left to right).

Recursion is prohibited.

---

# 1_2. Traversing the tree in pre-order order

Given a number N < 10^6 and a sequence of integers from [-2^31..2^31] length N. It is required to build a binary tree specified by the naive insertion order. I.e., when adding the next number K to the tree with root root, if root→Key ≤ K, then node K is added to the right subtree root; otherwise, to the left subtree root. Output the elements in pre-order order (from top to bottom).

Recursion is prohibited.

---

# 1_3. Traversing the tree in post-order order

Given a number N ≤ 10^4 and a sequence of integers from [-2^31..2^31] length N. It is required to build a binary tree specified by the naive insertion order. I.e., when adding the next number K to the tree with root root, if root→Key ≤ K, then node K is added to the right subtree root; otherwise, to the left subtree root. Output the elements in the postorder order (from bottom to top).

Recursion is prohibited.

---

# 1_4. Traversing the tree in level-order order

Given a number N < 10^6 and a sequence of integers from [-2^31..2^31] length N.
It is required to build a binary search tree specified by the naive insertion order. I.e., when adding the next number K to the tree with root root, if root→Key ≤ K, then node K is added to the right subtree root; otherwise, to the left subtree root.
Output the elements in the order of level-order (by layers“ "in width”).

### Input format
The first line contains the number N.
The next N lines contain integers of the original sequence.

### Output format
N integers separated by a space.

---

# 2_1. Cartesian tree. Depth difference

### Time limit 1 second

### 64Mb memory limit

### Input standard input or input.txt

### Output standard output or output.txt

Given a number N < 10^6 and a sequence of pairs of integers from [-2^31, 2^31] of length N.
Construct a Cartesian tree of N nodes characterized by pairs of numbers (Xi, Yi). Each pair of numbers (Xi, Yi) defines the key Xi and the priority Yi in the Cartesian tree.
Add a node to the Cartesian tree as follows: When adding a node (x, y), perform a key descent to node P with a lower priority. Then split the found subtree by key x so that in the first subtree all keys are less than x, and in the second one they are greater than or equal to x. Make the resulting two trees children of the new node (x, y). Insert the new node into the place of node P.
Also build a naive key search tree Xi.
That is, when adding another number K to a naive tree with root root, if root→Key ≤ K, then node K is added to the right subtree of root; otherwise, to the left subtree of root.

Calculate the difference between the depths of a naive search tree and a Cartesian tree. The difference may be negative, it is necessary to output the difference modulus.

### Input format
The first line contains the number N — the number of nodes.
In each next line, two numbers Xi, Yi are written - the key and the priority of the node.

### Output format
A non-negative integer.

---

# 2_2. Cartesian tree. Width difference

### Time limit 1 second

### 64Mb memory limit

### Input standard input or input.txt

### Output standard output or output.txt

Given a number N < 10^6 and a sequence of pairs of integers from [-2^31, 2^31] of length N. Construct a Cartesian tree of N nodes characterized by pairs of numbers (Xi, Yi). Each pair of numbers (Xi, Yi) defines the key Xi and the priority Yi in the Cartesian tree. Adding a node to the Cartesian tree is performed by the second version of the algorithm described in the lecture: When adding a node (x, y), perform a key descent to node P with a lower priority. Then split the found subtree by key x so that in the first subtree all keys are less than x, and in the second one they are greater than or equal to x. Make the resulting two trees children of the new node (x, y). Insert the new node into the place of node P. Also build a naive key search tree Xi. Add equal keys to the right subtree. Calculate the number of nodes in the widest layer of the Cartesian tree and the number of nodes in the widest layer of the naive search tree. Output their difference. The difference may be negative.

---

# 3_1. Soldiers

### Time limit 1 second

### Memory limit 20Mb

### Input standard input or input.txt

### Output standard output or output.txt

In one military unit, they decided to build in one row according to height. Because the part was far from exemplary, the soldiers often came at the wrong time, or even they had to be kicked out of the line for poorly polished boots. However, the soldiers in the process of coming and going had to always be lined up according to height – first the tallest, and at the end - the lowest. An ensign was responsible for the placement of the soldiers, who noticed an interesting feature – all the soldiers were of different heights. Your task is to help the ensign to place the soldiers correctly, namely, for each incoming soldier to indicate which soldier in the ranks he should stand in front of. The required command execution speed is O(log n).

### Input format
The first line contains the number N – the number of commands (1 ≤ N ≤ 90,000). Each next line contains a description of the command: the number 1 and X if the soldier comes into service (X is the growth of the soldier, a natural number up to 100,000 inclusive) and the number 2 and Y if the soldier standing in the ranks in place of Y must be removed from the system. Soldiers in the ranks are numbered from scratch.

### Output format
For each command 1 (addition to the formation), you must output the number K – the number of the position to which this soldier should stand (all those behind him move back).

---

# 3_2. Порядковые статистики

### Ограничение времени	0.3 секунды

### Ограничение памяти	20Mb

### Ввод	стандартный ввод или input.txt

### Вывод	стандартный вывод или output.txt

Дано число N и N строк. Каждая строка содержащит команду добавления или удаления натуральных чисел, а также запрос на получение k-ой порядковой статистики. Команда добавления числа A задается положительным числом A, команда удаления числа A задается отрицательным числом “-A”. Запрос на получение k-ой порядковой статистики задается числом k. Требуемая скорость выполнения запроса - O(log n).

---

# 4. Алгоритм сжатия данных Хаффмана

### Ограничение времени	100 секунд

### Ограничение памяти 64 МБ

### Ввод стандартный ввод или input.txt

### Вывод стандартный вывод output.txt или 

Напишите две функции для создания архива из одного файла и извлечения файла из архива.

Метод архивирует данные из потока исходное
кодирование void(IInputStream и оригинал, IOutputStream и сжатый);
Метод восстанавливает оригинальные данные
недействительное декодирование (входной поток и сжатый, выходной поток и оригинал);
где:
байт символа typedef;

интерфейс IInputStream {
// Возвращает ложь, если поток закончился
чтение виртуального буфера обмена (байт и значение) = 0;
};

интерфейс IOutputStream {
запись виртуальной пустоты (байтовое значение) = 0;
};
В архиве сохраняйте дерево Хаффмана и код Хаффмана от исходных данных. Дерево Хаффмана требуется хранить эффективно - не более 10 бит на каждый 8-битный символ.

В контест необходимо отправить .cpp файл содержащий функции Кодировать, декодировать, а также включающий файл Хаффман.ч. Тестирующая программа выводит размер сжатого файла в процентах от исходного.

Пример минимального решения:
#включить "Хаффман.ч"

статический пустой поток копирования(IInputStream и ввод, IOutputStream и вывод) {
значение байта;
в то время как(ввод.Считывание(значение)) { вывод.Запись(значение); }
}

недействительное кодирование (IInputStream и оригинал, IOutputStream и сжатый) {
Поток копий (оригинал, сжатый);
}

недействительное декодирование(IInputStream& сжатый, IOutputStream& оригинал) {
CopyStream(сжатый, оригинал);
}
