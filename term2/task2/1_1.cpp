#include <iostream>
using namespace std;


struct Box{
    Box() {}
    Box(unsigned int w, unsigned int l, unsigned int h,unsigned int _num)
        :num{_num}
    {
        arr[0] = w;
        arr[1] = l;
        arr[2] = h;
        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < 2 - i ; j++) {
                if (arr[j] > arr[j + 1]) {
                    unsigned int temp = arr[j];
                    arr[j] = arr[j + 1];
                    arr[j + 1] = temp;
                }
            }
        }
    }
    unsigned int arr[3];
    unsigned int num;
};

bool operator < (const Box &a, const Box &b)
{
    for(int i = 0; i < 3; ++i)
        if(a.arr[i] >= b.arr[i])
            return 0;
    return 1;
}

void InsertionSort(Box* a, size_t n)
{
    for(size_t i = 1; i < n; ++i)
    {
        Box tmp = a[i];
        int j = i - 1;
        for(; j >= 0 && tmp < a[j]; --j) {
            a[j+1] = a[j];
        }
        a[j+1] = tmp;
    }
}

int main()
{
    int n = 0;
    cin >> n;
    Box* m = new Box [n];
    for(int i = 0; i < n; ++i)
    {
        unsigned int w, l, h;
        cin >> w >> l >> h;
        m[i] = Box(w, l, h, i);
    }

    InsertionSort(m, n);

    for(int i = 0; i < n; ++i)
        cout << m[i].num << " ";

    delete [] m;
    return 0;
}
