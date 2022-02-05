#include <iostream>
using namespace std;

struct Dot{
    Dot() {}
    Dot(int _x, int _y): x{_x}, y{_y} {}
    int x,y;
};

bool operator < (const Dot &a, const Dot &b)
{
    if(a.x < b.x) return 1;
    else if(a.x == b.x) return a.y < b.y;
    return 0;
}

void InsertionSort(Dot* a, size_t n)
{
    for(size_t i = 1; i < n; ++i)
    {
        Dot tmp = a[i];
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
    Dot* line = new Dot [n];
    for(int i = 0; i < n; ++i)
    {
        int x,y;
        cin >> x >> y;
        line[i] = Dot(x,y);
    }

    InsertionSort(line, n);

    for(int i = 0; i < n; ++i)
        cout << line[i].x << " " << line[i].y << endl;

    delete [] line;
    return 0;
}
