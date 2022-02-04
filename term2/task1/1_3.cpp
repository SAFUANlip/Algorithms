#include <iostream>

using namespace std;

int gcd(int a, int b) {
    int t;
    while (b != 0) {
        t = b;
        b = a % b;
        a = t;
    }
    return a;
}

void reduction(int &a, int &b) //сокращение дроби
{
    int nod = abs(gcd(a, b) );
    a /= nod, b /= nod;
}

int main()
{
    int a, b, c, d, n, m;
    cin >> a >> b >> c >> d;
    m = a * d + c * b;
    n = b * d;
    reduction(m, n);
    cout << m <<" "<< n;
    return 0;
}
