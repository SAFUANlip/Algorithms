#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>
#include <queue>
using namespace std;
/*
 * A[0] - first
 * A[i] - father
 * A[(i-1)/2] - grandfather
 * A[2*i + 1] and A[2*i + 2] children
*/
template <typename T>
class Heap{
public:
    Heap(int n) { vec.reserve(n); }
    Heap(const vector<T> &v);       //O(n)

    T ExtractMax();
    T GetMAx() { return vec[0]; }
    void add(T element);            //O(logN) если без выделения памяти
    bool is_empty() { return vec.size() == 0; }
    void print() { for(T x : vec) cout<<x<<" "; cout<<endl; }
private:
    vector<T> vec;
    void SiftDown(int i);           //O(logN)
    void SiftUp(int i);             //O(logN)
};

template <typename T>
Heap<T>::Heap(const vector<T> &v)
{
    //создание упорядоченной из вектора
    vec = v;
    for(int i = v.size()/2 - 1; i>=0;--i)
    {
        SiftDown(i);
    }
}

template <typename T>
void Heap<T>::SiftDown(int i)
{
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    int largest = i;
    //ищем больший из предков
    if( (left < vec.size()) && (vec[left] > vec[largest]) )
        largest = left;
    if( (right < vec.size()) && (vec[right] > vec[largest]) )
        largest = right;
    // если такой есть меняем местами со старшим, и проталкиваем дальше
    if(largest != i)
    {
        swap(vec[largest], vec[i]);
        SiftDown(largest);
    }
}

template <typename T>
void Heap<T>::SiftUp(int i)
{
    while(i > 0)
    {
        int parent = (i-1)/2;
        if(vec[i] <= vec[parent])
            return;
        swap(vec[i], vec[parent]);
        i = parent;
    }
}

template <typename T>
void Heap<T>::add(T element)
{
    // добавляем в конец и поднимаем
    vec.push_back(element);
    SiftUp(vec.size() - 1);
}

template <typename T>
T Heap<T>::ExtractMax()
{
    //исключение если значение 0
    assert(!vec.empty());
    //запоминаем значение корня
    T rezult = vec[0];
    //переносим ласт в корень и удаляем его
    vec[0] = vec.back();
    vec.pop_back();
    //если непустой опускаем корень
    if (!vec.empty()) SiftDown(0);
    return rezult;

}

int main()
{

    int n = 0, m = 0, K = 0, weight = 0, count = 0;

    cin >> n;

    Heap<int> basket(n);
    for(int i = 0; i < n; ++i)
    {
        cin >> m;
        basket.add(m);
    }

    cin >> K;

    queue<int> eat;

    while(basket.GetMAx() != 0)
    {
        weight = 0;
        while((!basket.is_empty()) && (K - weight >= basket.GetMAx())){
            int a = basket.ExtractMax();
            weight += a;
            a = a - a/2 - a%2;
            eat.push(a);
        }
        while(!eat.empty()){
            basket.add(eat.front());
            eat.pop();
        }
        ++count;
    }
    cout << count;
    return 0;
}
