#include <iostream>
#include <cmath>
using namespace std;

struct Dot{
    Dot() {}
    Dot(int _x, int _y): x{_x}, y{_y} {}
    int x,y;
    double corner;
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
        for(; j >= 0 && tmp.corner <= a[j].corner; --j) {
            a[j+1] = a[j];
        }
        a[j+1] = tmp;
    }
}

void give_corners(Dot* a, int n)
{
    for(int i = 0; i < n - 1; ++i)
    {
        double arg = (a[i].x - a[n - 1].x)/
            sqrt( pow(a[i].x - a[n - 1].x, 2) + pow(a[i].y - a[n - 1].y, 2) );

        a[i].corner = acos(arg);
        if(a[i].y - a[n - 1].y < 0)
            a[i].corner = 0 - acos(arg);
    }

}

int main()
{
    int n = 0;
    cin >> n;
    Dot* line = new Dot [n];
    unsigned int min = 0;
    for(int i = 0; i < n; ++i)
    {
        int x,y;
        cin >> x >> y;
        line[i] = Dot(x,y);
        if(line[i] < line[min]) min = i;
    }
    Dot a = line[min];
    line[min] = line[n-1];
    line[n-1] = a;
    give_corners(line, n);

    InsertionSort(line, n-1);

    for(int i = n-1; i >= 0; --i)
        cout << line[i].x << " " << line[i].y << endl;

    delete [] line;
    return 0;
}
