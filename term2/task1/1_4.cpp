#include <iostream>
#include <cmath>
using namespace std;

int main()
{

    int d, n;
    bool isfound = false;
    cin >> n;
    for (int q = 2; q <= int(sqrt(n)) + 1; ++q)
    {
        if (n % q == 0) {
            d = n / q;
            cout << d << " " << n - d;
            isfound = true;
            break;
        }
    }
    if (isfound == false)
        cout << 1 << " " << n - 1;
    return 0;
}
