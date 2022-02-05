#include <iostream>
#include <vector>
using namespace std;

unsigned int byte(unsigned int n, int k) {//возвращает k-й справа байт числа
	return (n >> 8 * k) & 0xFF; // сначала получаем k число, потом берём значение по байту 0xFF берёт байт числа
}


void LSD_sort(vector<unsigned int>& vec) {//поразрядная сортировка с наименьших разрядов
	for (int r = 0; r <= 3; ++r) {
		vector<int> counter(256); //массив подсчета встречаемости значений разряда
		vector<int> position(256); //массив, в котором хранится, на какое место должен встать элемент со значением разряда i

		for (int i = 0; i < vec.size(); ++i) {
			++counter[byte(vec[i], r)]; //какое число встретилось в r байте числа, то увеличиваем счётчик этого числа
		}

		for (int i = 1; i < 256; ++i) {
			position[i] = position[i - 1] + counter[i - 1]; //на какое место поставить число в новом массиве
		} //считаем скоько позиций учли до этого + сколько было чисел i-1.

		vector<unsigned int> new_vec(vec.size());
		for (int i = 0; i < vec.size(); ++i) {
			new_vec[position[byte(vec[i], r)]] = vec[i]; //элемент помещается в позицию для его r-ого байта,
			++position[byte(vec[i], r)];                 //т.е если у нас было 5 чисел 10, то позиция 11 будет учитывать,
															 //что у нас есть ещё 5 чисел 10
			//сдвигаем position чтобы следующие такие же элементы вставали в следующую ячейку
		}
		vec = new_vec;
	}
}

int main()
{
    int n,k,l;

    unsigned long long m, sum;
	sum = 0;
    cin >> n >> k >> m >> l;
    vector<unsigned int> v;
    v.push_back(k);
    for (int i = 1; i < n; ++i)
        v.push_back((unsigned int)((v[i-1] * (unsigned long long)m) & 0xFFFFFFFFU)%l);
	LSD_sort(v);
	/*for (auto i : v)
		cout << i<<" ";
	cout << endl;*/
	for (int i = 0; i < n; i += 2)
		sum += v[i];
	cout << sum%l;
    return 0;
}
