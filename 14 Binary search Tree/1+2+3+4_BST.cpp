#include<bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node* Left;
    Node* Right;
};

class BST
{
private:
    Node* root;
public:
    BST()
    {
        root = NULL;
    }

    Node* CreateNewNode(int val)
    {
        Node* x = new Node;
        x->data = val;
        x->Left = NULL;
        x->Right = NULL;

        return x;
    }

    void Insert(int val)
    {
        Node* NewNode = CreateNewNode(val);
        if(root==NULL)
        {
            root = NewNode;
            return;
        }

        Node* current = root;
        Node* parent = NULL;

        while(current != NULL)
        {
            if(current->data > val)
            {
                parent = current;
                current = current->Left;
            }
            else
            {
                parent = current;
                current = current->Right;
            }
        }
        if(parent->data > val)
            parent->Left = NewNode;
        else
            parent->Right = NewNode;
    }

    bool Search(int val)
    {
        Node* tmp = root;

        while(tmp!=NULL)
        {
            if(tmp->data > val)
                tmp = tmp->Left;
            else if(tmp->data < val)
                tmp = tmp->Right;
            else
                return true;
        }
        return false;
    }

    void Delete(int val)
    {
        Node* current=root;
        Node* parent=NULL;
        while(current!=NULL)
        {
            if(current->data > val)
            {
                parent = current;
                current = current->Left;
            }
            else if(current->data < val)
            {
                parent = current;
                current = current->Right;
            }
            else
                break;
        }

        if(current == NULL)
            return;

        if(current->Left == NULL && current->Right == NULL)
        {
            if(parent->Left == current)
                parent->Left = NULL;
            else
                parent->Right = NULL;

            delete current;
            return;
        }

        if(current->Left != NULL && current->Right == NULL)
        {
            if(parent->Left == current)
                parent->Left = current->Left;
            else
                parent->Right = current->Left;

            delete current;
            return;
        }

        if(current->Left == NULL && current->Right != NULL)
        {
            if(parent->Left == current)
                parent->Left = current->Right;
            else
                parent->Right = current->Right;

            delete current;
            return;
        }

        Node* tmp = current->Right;

        while(tmp->Left!=NULL)
        {
            tmp=tmp->Left;
        }
        int value = tmp->data;
        Delete(value);
        current->data = value;
    }

    //Breadth first search- visiting Levelwise
    void BFS_traverse()
    {
        queue<Node*> A;
        A.push(root);
        while(!A.empty())
        {
            Node* tmp = A.front();
            A.pop();
            if(tmp->Left!=NULL)
                A.push(tmp->Left);
            if(tmp->Right!=NULL)
                A.push(tmp->Right);
            cout << tmp->data << ' ';
        }
        cout << '\n';
    }

    int getMin()
    {
        if(root==NULL)
            return -1;

        Node* tmp = root;
        while(tmp->Left != NULL)
            tmp=tmp->Left;
        return tmp->data;
    }

    int getMax()
    {
        if(root==NULL)
            return -1;

        Node* tmp = root;
        while(tmp->Right != NULL)
            tmp=tmp->Right;
        return tmp->data;
    }

    bool valid_BST()
    {
        queue<Node*> A;
        A.push(root);
        while(!A.empty())
        {
            Node* tmp = A.front();
            A.pop();
            if(tmp->Left!=NULL)
                A.push(tmp->Left);
            if(tmp->Right!=NULL)
                A.push(tmp->Right);
            if(tmp->Left!=NULL && tmp->Left->data>=tmp->data)
                return false;
            if(tmp->Right!=NULL && tmp->Right->data < tmp->data)
                return false;
        }
        return true;
    }
};

int main()
{
    BST b;

    b.Insert(5);
    b.Insert(7);
    b.Insert(6);
    b.Insert(3);
    b.Insert(4);
    b.Insert(8);
    b.Insert(2);
    b.Insert(1);

    b.BFS_traverse();

    cout << b.Search(8) << "\n";
    cout << b.Search(10) << "\n";

    b.Delete(5);
    b.BFS_traverse();
    b.Delete(7);

    b.BFS_traverse();

    cout << b.getMax() << '\n';
    cout << b.getMin() << '\n';
    cout << b.valid_BST() << '\n';

    return 0;
}

