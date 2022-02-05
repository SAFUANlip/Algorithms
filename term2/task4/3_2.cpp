#include <iostream>
#include <vector>
using namespace std;

long long count_pyramid(const int n)
{
	vector <vector <long long>> count(n+1, vector <long long>(n+1)); //инициализация двумерного вектора нулями
    //заполняем первый столбец единицами, чтобы следующие уровни брали нулевой за основу (чтобы пирамидки высотой один уже счтались за 1 вариант)
    for (int j = 0; j < count.size(); ++j)
        count[j][0] = 1;
    //представим в виде массива какой ширины могут быть пирамиды при заданном количестве кубиков
    //в столбцах (j) будет количество кубиков, в строках (i) ширина пирамидки 
    //количество пирамидок шириной не больше i, равно количеству, чья ширина меньше i count[i-1][j] и количеству
    //пирамидок у которых ширинa i, их количество это все пирамидки из j-i кубикови всех ширин меньших или равных i-1, т.е
    //count[i-1][j-i]
    //Если ширина больше чем количество кубиков, то заполняем массив количество пирамидок при максимальной ширине
    for (int j = 1; j <= n; ++j) {
        for (int i = 1; i <= j; ++i)
            count[i][j] = count[i-1][j] + count[i - 1][j - i];

        for (int i = j + 1; i <= n; ++i)
            count[i][j] = count[j][j];
    }
	/*for (int i = 0; i < count.size(); ++i) {
    for (int j = 0; j < count.size(); ++j)
        cout << count[i][j] << " ";
    cout << endl;
    }*/
    return count[n][n];
}

int main()
{
    int n;
    cin >> n;
    cout << count_pyramid(n);
    return 0;
}
