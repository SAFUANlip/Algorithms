#include <iostream>
using namespace std;

int main()
{
    int n,k,plus;
    plus = 3;
    cin >> n;
    k = 1;
    for (int i = 0; i < n; ++i)
    {
        cout << k << " ";
        k += plus;
        plus += 2;
    }
}
