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



# B. Секретные материалы

### Ограничение времени	1 секунда

### Ограничение памяти	256Mb

### Ввод	стандартный ввод или input.txt

### Вывод	стандартный вывод или output.txt

Джон Макклейн сообщает по рации новую информацию о террористах в отдел с n полицейскими. Он звонит нескольким сотрудникам и просит распространить информацию по отделу, зная, что у каждого полицейского есть связь с определёнными коллегами. Джон Макклейн хочет, чтобы операция прошла успешно. Но если полицейский позвонит коллеге, от которого(возможно, не напрямую) сам получил информацию, террористы смогут отследить этот звонок и помешать операции. Если же двое сотрудников оповестят одного, ничего плохого не произойдёт. Помогите Джону Макклейну. Выведите NO, если кто-то из полицейских ошибётся, делая звонок. Если всё пройдёт хорошо, выведите YES и порядок, в котором полицейские получат информацию, считая, что полицейские оповещают коллег по возрастанию их номеров, а в начале Джон даёт информацию тем, кому не может позвонить никто из коллег.

### Формат ввода
Первая строка содержит пару целых чисел n и m (1 ≤ n, m ≤ 105) — количество вершин и рёбер заданного ориентированного графа.

Следующие m строк содержат описания рёбер, по одному в строке. Каждая из строк содержит по два целых числа a и b (0 ≤ a, b < n) — начало и конец ребра.

### Формат вывода
Если такого порядка не существует, то выведите «NO» (без кавычек).

В противном случае, выведите «YES» в первую из строк. Во вторую строку выведите перестановку индексов вершин (целые числа от 0 до n - 1), такую, что для каждого ребра его стартовая вершина находится строго левее его конечной вершины.
