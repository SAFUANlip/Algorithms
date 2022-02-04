#include <iostream>
using namespace std;

int main()
{
    int a;
    cin >> a;
    int i = 2;
    while (a != 1)
    {
        if (a % i == 0)
        {
            cout << i << " ";
            a /= i;
        }
        else
            i += 1;
    }
    return 0;
}
