#include <functional>
#include <queue>
#include <iostream>
using namespace std;

template <typename T>
class bintree
{
    struct Node
    {
        T d;
        Node* l, * r, * p;
    };

public:
    
    bintree() : root(0) {};

    bintree(initializer_list<T> list) {
        for (auto e : list) {
            insert(e);
        }
    }
    bintree(const bintree& m) {
        for (auto e : m) {
            insert(e);
        }
    };

    bintree& operator=(const bintree& m) {
        delete_tree(root);

        for (auto e : m) {
            insert(e);
        }
    }

    ~bintree()
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
        insert_tree(root, val, 0);
    }

    void remove(const T& val) //удвление элемента по значению
    {
        delete_from_tree(root, val);
    }

    int depth() const {
        return depth(root, 0);
    }

    void bfs() const
    {
        BFS(root);
    }

    void preorder() const
    {
        preorder(root);
    }

    void inorder() const
    {
        inorder(root);
    }

    void postorder() const
    {
        postorder(root);
    }

    //сколько узлов в данном слое дерева
    int many(int i) const {
        if (i < levels.size())
            return levels[i];
    }

    int level() {
        count_level(root, 0);
        return levels.size();
    }

private:
    Node* root = 0;
    vector<int> levels{ 0 }; //уровни дерева, начинаются с первого, на котором один элемент - корень

    void count_level(Node* n, int lev)
    {
        if (!n)
            return;
        if (levels.size() <= lev)
            levels.push_back(0);
        levels[lev]++;
        count_level(n->l, lev + 1);
        count_level(n->r, lev + 1);
    }


    void preorder(Node* n) const {
        if (!n) return;
        cout << n->d << " ";
        preorder(n->l);
        preorder(n->r);
    }

    void inorder(Node* n) const {
        if (!n) return;
        inorder(n->l);
        cout << n->d << " ";
        inorder(n->r);
    }

    void postorder(Node* n) const {
        if (!n) return;
        postorder(n->l);
        postorder(n->r);
        cout << n->d << " ";
    }

    void BFS(Node* root) const {
        queue<Node*> q;
        q.push(root);
        while (!q.empty()) {
            Node* node = q.front();
            q.pop();
            cout << node->d << " ";
            if (node->l)
                q.push(node->l);
            if (node->r)
                q.push(node->r);
        }
    }

    void delete_tree(Node*& node) {
        if (!node) return;
        delete_tree(node->l); delete_tree(node->r);
        delete node;
        node = nullptr;
    }

    void insert_tree(Node*& n, T v, Node* p = 0)
    {
        if (n == 0)
            n = new Node{ v,0,0,p };
        else if (v < n->d)
            insert_tree(n->l, v, n); //если значение меньше родителя, то суём его влево
        else if (n->d < v) //эта проверка, чтобы не было копий
            insert_tree(n->r, v, n); //если значение больше родителя, то суём его вправо
    }

    void delete_from_tree(Node*& n, const T& v)
    {
        if (n == 0)
            return;
        if (v < n->d)
            delete_from_tree(n->l, v);
        else if (v > n->d)
            delete_from_tree(n->r, v);
        else if (n->l == 0 && n->r == 0)
        {
            if (n->p->d > n->d)
                n->p->l = nullptr;
            else
                n->p->r = nullptr;
            delete n;
        }
        else if (n->l == 0 && n->l != 0)
        {
            Node* x = n;
            if (x)
                n->r->p = n->p;
            delete n;
            n = x;
        }
        else if (n->r == 0 && n->l != 0)
        {
            Node* x = n;
            n->l->p = n->p;
            delete n;
            n = x;
        }
        else
        {
            Node* x = n->l;
            while (x->r)
                x = x->r;
            n->d = x->d;

            (x->p->r == x ? x->p->r : x->p->l) = x->l;
            if (x->l)
                x->l->p = x->p;

            Node* p = x->p;

            delete x;
        }
    }

    int depth(Node* n, int d) const {
        return n == 0 ? d : max(depth(n->l, d + 1), depth(n->r, d + 1));
    }
};

class dtree
{
	struct Node
	{
		Node* l, * r;

		int k;
		int p;

		int h; //высота

	};

public:

	dtree() {}
	~dtree() {};

	void insert(int val, int pr) {
		insert(val, pr, root);
	}

	void remove(int val) {
		remove(val, root);
	}

	int depth() const {
		return depth(root, 0);
	}

	bool contains(int val) const {
		bool ok;
		contains(root, val, ok);
		return ok;
	}

	//сколько узлов в данном слое дерева
	int many(int i) const {
		if (i < levels.size())
			return levels[i];
	}

	int level() {
		count_level(root, 0);
		return levels.size();
	}

private:
	Node* root = nullptr;
	vector<int> levels{ 0 }; //уровни дерева, начинаются с первого, на котором один элемент - корень

	void count_level(Node* n, int lev)
	{
		if (!n)
			return;
		if (levels.size() <= lev)
			levels.push_back(0);
		levels[lev]++;
		count_level(n->l, lev + 1);
		count_level(n->r, lev + 1);
	}

	void insert(int val, int pr, Node*& n)
	{
		if (!n) //n==0
			n = new Node{ 0,0,val,pr }; //указатели левый и правый обнуляются
		else if (n->p < pr)
		{
			Node* n1 = new Node{ 0,0,val,pr };
			split(val, n, n1->l, n1->r);
			n = n1;
		}
		else if (val < n->k)
			insert(val, pr, n->l);
		else
			insert(val, pr, n->r);
	}

	//удаление
	void remove(int val, Node*& n)
	{
		if (!n) //n==0
			return;
		else if (val == n->k)
		{
			Node* n1 = n;
			n = merge(n1->l, n1->r);
			delete n1;
		}
		else if (val < n->k)
			remove(val, n->l);
		else
			remove(val, n->r);
	}

	void split(int val, Node* n, Node*& l, Node*& r) //два последних по ссылке потому что они будут меняться в функции
	{
		if (!n)
		{
			l = 0;
			r = 0;
		}
		else if (val < n->k)
		{
			split(val, n->l, l, n->l);
			r = n;
		}
		else
		{
			//Если значение больше чем ключ у n, то мы должны делить правое поддерево. Новым корнем будет вершина правого поддерева
			//r - не поменяется, т.к. к нему добавляются элементы >= val. Левое становится n->r т.к. к нему будут дальше прикрепляться
			// элементы меньшие val

			//(не меняем ключ, т.к слева у него меньшие, а справа большие элементы) 
			//val

			//(если ключ больше, то дальше режем по правому)   
			//n->r   

			//(всё что окажется меньше var потом прикрепится к начальному корню, по которому резали, поэтому несём с собой n->r)
			//n->r
			split(val, n->r, n->r, r);
			l = n;
		}
	}

	//Слияние
	Node* merge(Node* l, Node* r)
	{
		if (!l)
			return r;
		if (!r)
			return l;
		if (r->p < l->p)
		{
			l->r = merge(l->r, r);
			return l;
		}
		r->l = merge(l, r->l);
		return r;
	}

	//Поиск по ключу
	void contains(Node* n, int v, bool& ok) const
	{
		if (n == 0)
			ok = false;
		else if (v > n->k)
			contains(n->l, v, ok);
		else if (n->k > v)
			contains(n->r, v, ok);
		else
			ok = true;
	}

	int depth(Node* n, int d) const {
		return n == 0 ? d : max(depth(n->l, d + 1), depth(n->r, d + 1));
	}
};


template<typename T>
int count(T& tree)
{
    int l = tree.level();
    int max = 0;
    for (int i = 0; i < l; ++i)
    {
        //cout << btr.many(i)<<" ";
        if (tree.many(i) > max)
            max = tree.many(i);
    }
    return max;
}

int main()
{
    bintree<int> btr;
    dtree tr;
    int n,a,b;
    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        cin >> a >> b;
        btr.insert(a);
        tr.insert(a, b);
    }
    //int max = count_level(btr);
    //int max2 = count_level(tr);
    //cout << abs(tr.depth()-btr.depth());
    //int l = btr.level();
    //int max = 0;
    //for (int i = 0; i < l; ++i)
    //{
    //    //cout << btr.many(i)<<" ";
    //    if (btr.many(i) > max)
    //        max = btr.many(i);
    //}
    ////cout << endl << max << endl;

    //int l2 = tr.level();
    //int max2 = 0;
    //for (int i = 0; i < l2; ++i)
    //{
    //    //cout << tr.many(i) << " ";
    //    if (tr.many(i) > max2)
    //        max2 = tr.many(i);
    //}
    //cout << endl << max2;
    cout << count(tr) - count(btr);//max2 - max;
    return 0;
}
