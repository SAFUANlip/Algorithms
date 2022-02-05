#include <iostream>
#include <vector>
#include <string>
using namespace std;

struct Data{
    Data() {}
    Data(string _name, vector<int> _fields)
        : name{_name}, fields{_fields} {}
    string name;
    vector<int> fields;
};

//   a > b
bool higher (const Data &a, const Data &b, const vector<int> &pr)
{
    for(size_t i = 0; i < pr.size(); ++i)
    {
        if(a.fields[ pr[i] ] > b.fields[ pr[i] ]) return 1;
        else if(a.fields[ pr[i] ] < b.fields[ pr[i] ]) return 0;
    }
    return 0;
}

void InsertionSort(vector<Data> &a, const vector<int> &priority)
{
    for(size_t i = 1; i < a.size(); ++i)
    {
        Data tmp = a[i];
        int j = i - 1;
        for(; j >= 0 && higher(tmp, a[j], priority) ; --j) {
            a[j+1] = a[j];
        }
        a[j+1] = tmp;
    }
}

int main()
{
    int N_RECORDS    = 0;
    int N_PARAMETERS = 0;

    cin >> N_RECORDS;
    cin >> N_PARAMETERS;

    vector<int> PRIORITY;

    for(int i = 0; i < N_PARAMETERS; ++i)
    {
        int a;
        cin >> a;
        PRIORITY.push_back(a-1);
    }

    vector<Data> tests;

    for(int i = 0; i < N_RECORDS; ++i)
    {
        string name;
        cin >> name;
        vector<int> fields;
        for(int j = 0; j < N_PARAMETERS; ++j)
        {
            int a;
            cin >> a;
            fields.push_back(a);
        }
        tests.push_back(  Data(name, fields) );
    }

    InsertionSort(tests, PRIORITY);

    for(size_t i = 0; i < tests.size(); ++i)
        cout << tests[i].name << endl;

    return 0;
}
