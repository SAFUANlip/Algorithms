#include<iostream>
#include<vector>
using namespace std;

class List{
public:
    List(int n): head{0}, tail{0}, count{0} { v.resize(n); }

    void PushBack(int d);
    void PushFront(int d);
    int PopBack();
    int PopFront();
    
    bool is_empty() { return count == 0; }
private:
    vector<int> v;
    int head, tail;
    unsigned int count;
};

void List :: PushBack(int d)
{
    if(!is_empty()) ++tail;
    if(tail >= v.size()) tail = 0;
    v[tail] = d;
    ++count;
}

void List :: PushFront(int d)
{
    if(!is_empty())--head;
    if(head < 0) head = v.size() - 1;
    v[head] = d;
    ++count;
}

int List :: PopFront()
{
    if(is_empty()) return -1;
    int a = v[head];
    ++head;
    if(head >= v.size()) head = 0;
    --count;
    if(is_empty()){
        tail = 0;
        head = 0;
    }
    return a;
}

int List :: PopBack()
{
    if(is_empty()) return -1;
    int a = v[tail];
    --tail;
    if(tail < 0) tail = v.size() - 1;
    --count;
    if(is_empty()){
        tail = 0;
        head = 0;
    }
    return a;
}

int main()
{
    int n, a, b;
    cin >> n;
    List qu(n);
    for(int i = 1; i <= n; ++i)
    {
        cin >> a >> b;
        switch (a) {
            case 1:
                qu.PushFront(b);
                break;
            case 2:
            {
                if(b != qu.PopFront()){
                    cout<<"NO";
                    return 0;
                }
                break;
            }
            case 3:
                qu.PushBack(b);
                break;
            case 4:
            {
                if(b != qu.PopBack()){
                    cout<<"NO";
                    return 0;
                }
                break;
            }
        }
    }
    cout<<"YES";

    return 0;
}
