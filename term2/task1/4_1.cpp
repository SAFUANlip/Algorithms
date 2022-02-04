#include <iostream>
using namespace std;


template<class T>
class mqueue {
    struct node {
        T data;
        node* prev;
        node* next;

        node(const T& data, node* p, node* n) :data{ data }, prev{ p }, next{ n }{}
    };

private:
    node* h{ nullptr };
    node* t{ nullptr };

public:
    mqueue() {}

    ~mqueue() {
        //delete h->next;
        clear();
    }

    void clear() {
        while (h) {
            node* tmp = h->next;
            delete h;
            h = tmp;
        }
        h = nullptr;
        t = nullptr;
    }

    void push_back(const T& data) {
        if (t) {
            t->next = new node(data, t, nullptr);
            t = t->next;
        }
        
        else {
            t = new node(data, nullptr, nullptr);
            h = t;
        }
    }

   
    bool pop_front(const T& val) {
        if (h == nullptr && t == nullptr && val != -1)
            return false;

        else if (h == nullptr && t == nullptr && val == -1)
            return true;

        else if (val == h->data) {
            if (h->next) {
                h = h->next;
                delete h->prev;
                h->prev = nullptr;
            }
            else {
                delete h;
                h = nullptr;
                t = nullptr;
            }
            return true;
        }
        else
            return false;

    }
};


int main()
{
    bool flag = true;
    mqueue<int> ml;
    int n,a,b;
    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        cin >> a >> b;

        if (a == 2)
        {
            if (!ml.pop_front(b))
            {
                cout << "NO";
                flag = false;
                break;
            }
        }
        if (a == 3)
            ml.push_back(b);
    }

    if (flag)
        cout << "YES";

    return 0;
}
