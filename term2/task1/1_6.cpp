#include <iostream>
using namespace std;

int main()
{
    int n,buf;
    cin >> n;
    int* m = new int[n];
    for (int i = 0; i < n; ++i)
    {
        cin >> m[i];
    }
    for (int i = 0; i < int(n / 2); ++i)
    {
        buf = m[i];
        m[i] = m[n - i-1];
        m[n - i-1] = buf;
    }
    for (int i = 0; i < n; ++i)
    {
        cout << m[i] << " ";
    }
    delete []m;
}
