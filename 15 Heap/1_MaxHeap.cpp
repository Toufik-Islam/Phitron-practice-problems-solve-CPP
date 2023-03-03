#include<bits/stdc++.h>
using namespace std;

template<class T>
class max_heap
{
public:
    vector<T> Nodes;

    max_heap()
    {

    }

    void up_heapify(int idx)
    {
        int parent = (idx-1)/2;

        while(parent>=0 && Nodes[parent]<Nodes[idx])
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
            int maxx = idx;

            if(Left<Nodes.size() && Nodes[Left]>Nodes[idx])
                maxx = Left;
            if(Right<Nodes.size() && Nodes[Right]>Nodes[maxx])
                maxx = Right;

            if(idx==maxx)
                break;
            swap(Nodes[idx],Nodes[maxx]);
            idx = maxx;
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

    T getMax()
    {
        if(Nodes.empty())
        {
            cout << "Heap is Empty..\n";
            T x;
            return x;
        }
        return Nodes[0];
    }
    T extractMax()
    {
        if(Nodes.empty())
        {
            cout << "Heap is Empty..\n";
            T x;
            return x;
        }
        T maxx = Nodes[0];
        Delete(0);
        return maxx;
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
    max_heap<char> h;
    h.Insert('a');
    h.Insert('b');
    h.Insert('c');
    h.Insert('d');
    h.Insert('e');
    h.Insert('f');
    h.Insert('g');

    h.Traverse();
//
//    cout << h.getMax() << endl;
//    cout << h.extractMax() << endl;
//    cout << h.getMax() << endl;

    h.Delete(0);
    h.Delete(0);

    h.Traverse();
    return 0;
}

