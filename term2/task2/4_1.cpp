#include <vector>
#include <iostream>
using namespace std;

void merge(vector <int>& arr, int start, int end)
{
    int left = start;
    int middle = start + (end - start) / 2;
    int right = middle + 1;
    int Inbuff = 0;

    //временный вектор для отсортированных
    vector < int > buff(end - start + 1);

    while (left <= middle && right <= end)
    {
        if (arr[left] < arr[right])
            buff[Inbuff++] = arr[left++]; //сначала присваиваем элемент, потом сдигаем указатели
        else
            buff[Inbuff++] = arr[right++];
    }
    //заполняем элементами, которые ещё не поместили в буфер
    while (left <= middle)
        buff[Inbuff++] = arr[left++];
    while (right <= end)
        buff[Inbuff++] = arr[right++];

    //заполняется каждый раз часть массива исходного
    //заполнение существующего вектора отсортированными 
    for (int i = start; i <= end; i++)
        arr[i] = buff[i - start];
}

void sort(vector <int>& arr, int start, int end)
{
    if (end <= start)
        return;
    int middle = start + (end - start) / 2;
    //разделение вектора на два, чтобы отсортировать каждый отдельно
    sort(arr, start, middle);
    sort(arr, middle + 1, end);
    merge(arr, start, end);
}

int main()
{
    int n,k,a;
    cin >> n >> k;
    vector<int> arr1;
    for (int i = 0; i < n; ++i)
    {
        cin >> a;
        arr1.push_back(a);
    }
    sort(arr1, 0, arr1.size() - 1);
    for (int i = 0; i < k; i++)
        cout << arr1[i] << " ";
    return 0;
}
