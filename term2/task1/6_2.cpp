#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>
#include <functional>
using namespace std;
/*
 * A[0] - first
 * A[i] - father
 * A[(i-1)/2] - grandfather
 * A[2*i + 1] and A[2*i + 2] children
*/
template <typename T>
class Heap{
    typedef function <bool(T,T)> C; // компаратор
public:
    Heap(C _c = less<int>()): c{_c} {} //если у конструктор не будет аргументов, автоматом less
    //иначе наш аргумент
    Heap(int n, C _c = less<int>()) : c{_c} { vec.reserve(n); }
    Heap(const vector<T> &v, C _c = less<int>()) : c{_c}, vec{v} { heapify(); }
    Heap(initializer_list<T> L, C _c = less<int>()) :  c(_c), vec(L) { heapify(); }
    Heap(const Heap& h) : vec(h.vec), c(h.c) {}

    T ExtractTop();
    T GetTop() { return vec[0]; }

    void add(T element);            //O(logN) если без выделения памяти
    void print() { for(T x : vec) cout<<x<<" "; cout<<endl; }

    bool is_empty() { return vec.size() == 0; }

    size_t size() { return vec.size();}

private:
    C c;
    vector<T> vec;
    void SiftDown(size_t i);           //O(logN)
    void SiftUp(size_t i);             //O(logN)
    void heapify();
};

template <typename T>
void Heap<T>::heapify()
{
    //создание упорядоченной из вектора O(n)
    for(int i = vec.size()/2 - 1; i>=0; --i)
    {
        SiftDown(i);
    }
}

template <typename T>
void Heap<T>::SiftDown(size_t i)
{
    size_t left = 2 * i + 1;
    size_t right = 2 * i + 2;
    size_t largest = i;
    //ищем больший из предков
    if( (left < vec.size()) && c(vec[largest], vec[left]) )
        largest = left;
    if( (right < vec.size()) && c(vec[largest], vec[right]) )
        largest = right;
    // если такой есть меняем местами со старшим, и проталкиваем дальше
    if(largest != i)
    {
        swap(vec[largest], vec[i]);
        SiftDown(largest);
    }
}

template <typename T>
void Heap<T>::SiftUp(size_t i)
{
    while(i > 0)
    {
        int parent = (i-1)/2;
        if (!c(vec[parent], vec[i]))
            return;
        swap(vec[i], vec[parent]);
        i = parent;
    }
}

template <typename T>
void Heap<T>::add(T element)
{
    // добовляем в конец и поднимаем
    vec.push_back(element);
    SiftUp(vec.size() - 1);
}

template <typename T>
T Heap<T>::ExtractTop()
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

    int n = 0, totaly_time = 0;
    cin >> n;
    Heap<int> expr(n, greater<int>());
    for(int i = 0; i < n; ++i){
        int a;
        cin >> a;
        expr.add(a);
    }
    while(expr.size() > 1)
    {
        int a = expr.ExtractTop();
        int b = expr.ExtractTop();
        totaly_time += a + b;
        expr.add(a + b);
    }
    cout << totaly_time;
    return 0;
}
