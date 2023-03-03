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

class Priority_queue
{
public:
    min_heap<int> h;
    Priority_queue()
    {

    }

    void insert(int val)
    {
        h.Insert(val);
    }

    void pop()
    {
        h.extractMin();
    }

    int top()
    {
        return h.getMin();
    }
    bool sz()
    {
        return h.Nodes.size();
    }
};

int main()
{
    Priority_queue pq;
    pq.insert(3);
    pq.insert(-2);
    pq.insert(-6);
    pq.insert(4);
    pq.insert(10);

    while(pq.sz())
    {
        cout << pq.top() << ' ';
        pq.pop();
    }
    return 0;
}



