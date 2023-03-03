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

    void build_from_array(vector<T> &A)
    {
        Nodes = A;
        int non_leaf_node = A.size()/2-1;
        for(int i=non_leaf_node; i>=0; i--)
        {
            down_heapify(i);
        }
    }
};


vector<int> HeapSort(vector<int> A)
{
    min_heap<int> h;
    h.build_from_array(A);
    vector<int> sorted;
    for(int i=0; i<A.size(); i++)
        sorted.push_back(h.extractMin());
    return sorted;
}



int main()
{
    vector<int> A= {9,1,5,6,3,2,4};

    A = HeapSort(A);

    for(auto it: A)
        cout << it << ' ';
    return 0;
}


