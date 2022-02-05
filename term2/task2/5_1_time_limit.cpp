#include <iostream>
#include <string>
#include <vector>
using namespace std;

bool operator > (const string& s1, const string& s2)
{
    for (int i = 0; i < s1.size() && i < s2.size(); ++i)
    {
        if (s1[i] > s2[i])
            return true;
        else if (s1[i] < s2[i])
            return false;
    }
    return (s1.size() > s2.size());
}


int main()
{
    
    string a;
    
    vector<string> vec;
    while (cin>>a)
    {
        vec.push_back(a);
    }
    /*if (vec[0] > vec[1])
        cout << "bigger";*/
        //Сортировка вставками
    for (int i = 1; i < vec.size(); i++) {
        int j = i;
        while (j > 0 && vec[j - 1] > vec[j])
        {
            swap(vec[j - 1], vec[j]);
            --j;
        }
    }
    for (auto i : vec)
        cout << i << endl;
}
