#include <functional>
#include <queue>
#include <iostream>
using namespace std;

template <typename T>
class mavlset
{
    //Компоратор...
    typedef function <bool(T, T)> C;
    struct Node
    {
        Node(T _d, Node* _l, Node* _r, Node* _p)
            :d{ _d }, l{ _l }, r{ _r }, p{ _p } {}
        T d;
        Node* l, * r, * p;
        int h = 1; //высота
        int ch = 0; //Количество детей (children)

        int dh() const {
            return (l == 0 ? 0 : l->h) - (r == 0 ? 0 : r->h);
        }

        void update_h() {
            h = max((l == 0 ? 0 : l->h), (r == 0 ? 0 : r->h)) + 1;
        }

        /*~Node() {
            delete r;
            r = nullptr;
            delete l;
            l = nullptr;
        }*/
    };

    class miterator {
        mutable Node* n;
    public:
        miterator(Node* n) : n{ n } {}

        const T& operator *() const
        {
            return n->d;
        }

        const miterator& operator --() const
        {
            if (n == 0)
                return *this;
            if (n->l)
            {
                n = n->l;
                while (n->r)
                    n = n->r;
                return *this;
            }
            while (n->p)
            {
                if (n->p->r == n)
                {
                    n = n->p;
                    return *this;
                }
                n = n->p;
            }
            return *this;
        }

        const miterator& operator ++() const
        {
            if (n == 0)
                return *this;
            if (n->r)
            {
                n = n->r;
                while (n->l)
                    n = n->l;
                return *this;
            }
            while (n->p)
            {
                if (n->p->l == n)
                {
                    n = n->p;
                    return *this;
                }
                n = n->p;
            }
            n = 0;
            return *this;
        }

        const T* operator ->() const
        {
            return &(n->d);
        }


        bool operator !=(const miterator& mt)const
        {
            return n != mt.n;
        }

        bool operator ==(const miterator& mt)const
        {
            return n == mt.n;
        }
    };

public:
    mavlset(C c = less<T>()) :c(c) {} //less функция

    mavlset(initializer_list<T> list, C c = less<T>()) : c{ c } {
        for (auto e : list) {
            insert(e);
        }
    }
    mavlset(const mavlset& m) : c{ m.c } {
        for (auto e : m) {
            insert(e);
        }
    };

    mavlset& operator=(const mavlset& m) {
        delete_tree(root);

        for (auto e : m) {
            insert(e);
        }
    }

    ~mavlset()
    {
        delete_tree(root);
    }

    void clear()
    {
        delete_tree(root);
    }

    bool empty() const //Проверка на пустоту
    {
        return(root == 0);
    }

    void insert(const T& val) //Делаем так чтобы было проще понимать что делает программа (удобство для пользователя)
    {
        insert_key(root, val, 0, 0); //Последний ноль для подсчёта позиции (детей, больших ключа)
    }

    void remove(const T& val) //удвление элемента по значению
    {
        delete_key(root, val);
    }

    void remove_i(int val) //удаление элемента по индексу
    {
        delete_i(root, val);
    }


    bool contains(const T& val) const
    {
        bool ok;
        contains(root, val, ok);
        return ok;
    }

    //Для проверки глубины
    int depth() const {
        return depth(root, 0);
    }

    //количество элементов
    int size() const {
        return size(root);
    }

    miterator begin() const
    {
        Node* n = root;
        while (n->l)
            n = n->l;
        return miterator(n);
    }

    miterator end() const
    {
        return miterator(0);
    }

private:
    Node* root = 0;
    C c;

    /*void BFS(Node* root) {
        queue<Node*> q;
        q.push(root);
        while (!q.empty()) {
            Node* node = q.front();
            q.pop();
            cout << node->d << endl;
            if (node->l) q.push(node->l);
            if (node->r) q.push(node->r);
        }
    }*/

    void delete_tree(Node*& node) {
        if (!node) return;
        delete_tree(node->l); delete_tree(node->r);
        delete node;
        node = nullptr;
    }

    void insert_key(Node*& n, const T& v, Node* p = 0, int sum = 0)
    {
        if (n == 0)
        {
            cout << sum << endl;
            n = new Node{ v, 0, 0, p };
        }
        else if (c(v, n->d)) {
            n->ch++;
            if (n->r)
                sum += 1 + n->r->ch;
            sum += 1;
            insert_key(n->l, v, n, sum);//если значение меньше родителя, то суём его влево
        }
        else if (c(n->d, v)) { //эта проверка, чтобы не было копий
            n->ch++;
            insert_key(n->r, v, n, sum); //если значение больше родителя, то суём его вправо
        }
        balance(n);
    }

    void delete_i(Node*& n, int k)
    {
        int children = 0;
        if (n->r)
            children = n->r->ch + 1;

        if (k == children) 
            delete_key(n, n->d);
        
        else if (k > children) {
            n->ch--;
            delete_i(n->l, k = k - children - 1);
        }
        else if (k < children) {
            n->ch--;
            delete_i(n->r, k);
        }
    }

    void delete_key(Node*& n, const T& v)
    {
        if (n == 0)
            return;
        if (c(v, n->d)) {
            n->ch--;
            delete_key(n->l, v);
        }
        else if (c(n->d, v)) {
            n->ch--;
            delete_key(n->r, v);
        }
        else if (n->l == 0)
        {
            Node* x = n->r;
            if (x)
                n->r->p = n->p;
            delete n;
            n = x;
        }
        else if (n->r == 0)
        {
            Node* x = n->l;
            n->l->p = n->p;
            delete n;
            n = x;
        }
        else
        {
            n->ch--;
            Node* x = n->l;
            while (x->r) {
                x->ch--;
                x = x->r;
            }
            n->d = x->d;

            (x->p->r == x ? x->p->r : x->p->l) = x->l;
            if (x->l)
                x->l->p = x->p;

            Node* p = x->p;
            delete x;

            while (p != n) {
                Node* p1 = p->p;
                balance(p1->l == p ? p1->l : p1->r);
                p = p1;
            }
        }

        if (n != 0)
            balance(n);
    }
    

    //Из константного метода нельзя вызывать неконстантный, поэтому как и в public мы мишем const
    void contains(Node* n, const T& v, bool& ok) const
    {
        if (n == 0)
            ok = false;
        else if (c(v, n->d))
            contains(n->l, v, ok);
        else if (c(n->d, v))
            contains(n->r, v, ok);
        else
            ok = true;
    }

    void rot_left(Node*& a) //Малое левое вращение
    {
        Node* b = a->r;
        if (b->r)
            a->ch = a->ch - b->r->ch - 1;
        a->ch--;
        if (a->l)
            b->ch = b->ch + a->l->ch + 1;
        b->ch++;

        a->r = b->l;
        if (a->r)
            a->r->p = a;

        b->l = a;
        b->p = a->p;
        a->p = b;

        a->update_h();
        b->update_h();

        a = b;

        //        if(a->l){
        //        b=a->l;
        //        if(a->r)
        //            b->ch=b->ch-a->r->ch;
        //        if(b->l)
        //            b->ch=b->ch+b->l->ch;
        //        }
    }

    //Малое правое вращение
    void rot_right(Node*& a) {
        Node* b = a->l;
        if (b->l)
            a->ch = a->ch - b->l->ch - 1;
        a->ch--;
        if (a->r)
            b->ch = b->ch + a->r->ch + 1;
        b->ch++;

        a->l = b->r;
        if (a->l)
            a->l->p = a;

        b->r = a;
        b->p = a->p;
        a->p = b;

        a->update_h();
        b->update_h();

        a = b;
    }

    void balance(Node*& n) {
        n->update_h();
        if (n->dh() <= -2) {
            if (n->r->dh() > 0)
                rot_right(n->r);
            rot_left(n);
        }
        else if (n->dh() >= 2) {
            if (n->l->dh() < 0)
                rot_left(n->l);
            rot_right(n);
        }
    }

    //Если n==0, то вернуть d, иначе максимум от самого глубокого корня
    int depth(Node* n, int d) const {
        return n == 0 ? d : max(depth(n->l, d + 1), depth(n->r, d + 1));
    }

    int size(Node* n) const {
        return n == 0 ? 0 : size(n->l) + size(n->r) + 1;
    }
};

int main()
{
    mavlset<int> l;
    int n, f, s;
    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        cin >> f >> s;
        if (f == 1) {
            l.insert(s);
        }
        else
            l.remove_i(s);
    }
    return 0;
}
