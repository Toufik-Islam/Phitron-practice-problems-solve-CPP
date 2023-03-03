#include<bits/stdc++.h>
using namespace std;

template<class T>
class min_heap
{
public:
    vector<T> Nodes;

    min_heap()
    {

    }

    void up_heapify(int idx)
    {
        int parent = (idx-1)/2;

        while(parent>=0 && Nodes[parent]>Nodes[idx])
        {
            swap(Nodes[parent],Nodes[idx]);
            idx = parent;
            parent = (idx-1)/2;
        }
    }

    void Insert(T val)
    {
        Nodes.push_back(val);
        up_heapify(Nodes.size()-1);
    }

    void down_heapify(int idx)
    {
        while(1)
        {
            int Left = 2*idx+1;
            int Right = 2*idx+2;
            int minn = idx;

            if(Left<Nodes.size() && Nodes[Left]<Nodes[idx])
                minn = Left;
            if(Right<Nodes.size() && Nodes[Right]<Nodes[minn])
                minn = Right;

            if(idx==minn)
                break;
            swap(Nodes[idx],Nodes[minn]);
            idx = minn;
        }
    }

    void Delete(int idx)
    {
        if(idx>=Nodes.size())
        {
            cout << "Heap is Empty..\n";
            return;
        }
        swap(Nodes[idx], Nodes[Nodes.size()-1]);
        Nodes.pop_back();
        down_heapify(idx);
    }

    T getMin()
    {
        if(Nodes.empty())
        {
            cout << "Heap is Empty..\n";
            T x;
            return x;
        }
        return Nodes[0];
    }
    T extractMin()
    {
        if(Nodes.empty())
        {
            cout << "Heap is Empty..\n";
            T x;
            return x;
        }
        int minn = Nodes[0];
        Delete(0);
        return minn;
    }

    void Traverse()
    {
        for(auto it: Nodes)
            cout << it << ' ';
        cout << '\n';
    }
};

int main()
{
    min_heap<char> h;
    h.Insert('a');
    h.Insert('b');
    h.Insert('c');
    h.Insert('d');
    h.Insert('e');
    h.Insert('f');
    h.Insert('g');

    h.Traverse();
//
//    cout << h.getMin() << endl;
//    cout << h.extractMin() << endl;
//    cout << h.getMin() << endl;

    h.Delete(0);

    h.Traverse();
    return 0;
}


