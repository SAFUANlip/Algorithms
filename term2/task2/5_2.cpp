/*
Дан массив неотрицательных целых 64-битных чисел.
Количество чисел не больше 1000000.
Отсортировать массив методом поразрядной сортировки LSD по байтам.
*/
//   111000101010001101
//>>8
//   000000001110001010
//&  000000000011111111
//   000000000010001010

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int byte(long long n, int k) {//возвращает k-й справа байт числа
	return (n >> 8 * k) & 0xFF; // сначала получаем k число, потом берём значение по байту 0xFF берёт байт числа
}

void LSD_sort(vector<long long>& vec) {//поразрядная сортировка с наименьших разрядов

	vector<long long> vec1(vec.size());
	for (int r = 0; r < 8; ++r) {
		int counter[256] = {0};
		int position[256] = {0};
		//vector<int> counter(256); //массив подсчета встречаемости значений разряда
		//vector<int> position(256); //массив, в котором хранится, на какое место должен встать элемент со значением разряда i

		for (int i = 0; i < vec.size(); ++i) {
			++counter[byte(vec[i], r)]; //какое число встретилось в r байте числа, то увеличиваем счётчик этого числа
		}

		for (int i = 1; i < 256; ++i) {
			position[i] = position[i - 1] + counter[i - 1]; //на какое место поставить число в новом массиве
		} //считаем скоько позиций учли до этого + сколько было чисел i-1.

		
		for (int i = 0; i < vec.size(); ++i) {
			vec1[position[byte(vec[i], r)]] = vec[i]; //элемент помещается в позицию для его r-ого байта,
			++position[byte(vec[i], r)];                 //т.е если у нас было 5 чисел 10, то позиция 11 будет учитывать,
			                                                 //что у нас есть ещё 5 чисел 10
			//сдвигаем position чтобы следующие такие же элементы вставали в следующую ячейку
		}
		vec.swap(vec1);
	}
}

int main() {
	long long n;
	cin >> n;
	//int m = n >> 0;
	//cout << m << endl;
	//cout << (m & 0xFF);
	vector<long long> vec;
	long long x;
	for (int i = 0; i < n; ++i) {
		cin >> x;
		vec.push_back(x);
	}

	LSD_sort(vec);

	for (int i = 0; i < n; ++i) {
		cout << vec[i] << " ";
	}

	return 0;
}
