#include<bits/stdc++.h>
using namespace std;

class Node
{
public:
    int id;
    int data;
    Node* parent;
    Node* Left;
    Node* Right;
};

class Binary_tree
{
public:
    Node* root;
    Binary_tree()
    {
        root = NULL;
    }

    Node* CreateNewNode(int id, int val)
    {
        Node* tmp = new Node;
        tmp->id = id;
        tmp->data = val;
        tmp->parent = NULL;
        tmp->Left = NULL;
        tmp->Right = NULL;

        return tmp;
    }

    //At level wise free node
    void Insertion(int id,int val)
    {
        Node* NewNode = CreateNewNode(id,val);
        if(root == NULL)
        {
            root = NewNode;
            return;
        }

        queue<Node*> A;
        A.push(root);
        while(!A.empty())
        {
            Node* tmp = A.front();
            A.pop();

            if(tmp->Left!=NULL)
                A.push(tmp->Left);
            else
            {
                tmp->Left = NewNode;
                NewNode->parent = tmp;
                return;
            }
            if(tmp->Right != NULL)
                A.push(tmp->Right);
            else
            {
                tmp->Right = NewNode;
                NewNode-> parent = tmp;
                return;
            }
        }
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
            cout << tmp->id << ' ';
        }
        cout << '\n';
    }

    //Depth first search
    void DFS_traverse(Node* root)
    {
        if(root == NULL)
            return;
        cout << root->id << ' ';
        DFS_traverse(root->Left);
        DFS_traverse(root->Right);
    }

    //left + root + right
    void InOrder(Node* root)
    {
        if(root == NULL)
            return;

        DFS_traverse(root->Left);
        cout << root->id << ' ';
        DFS_traverse(root->Right);
    }

    //root + left + right
    void PreOrder(Node* root)
    {
        if(root == NULL)
            return;
        cout << root->id << ' ';
        DFS_traverse(root->Left);
        DFS_traverse(root->Right);
    }

    //left + right + root
    void PostOrder(Node* root)
    {
        if(root == NULL)
            return;

        DFS_traverse(root->Left);
        DFS_traverse(root->Right);
        cout << root->id << ' ';
    }

    void Searching(int val)
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
            if(tmp->data == val)
                cout << tmp->id << ' ';
        }
        cout << '\n';
    }

    bool isPerfectBinaryTree()
    {
        if (root == NULL)
        {
            return true;
        }

        queue<Node*> q;
        q.push(root);
        int level = 0;
        int expectedNodes = 1;

        while (!q.empty())
        {
            int nodesInLevel = q.size();
            if (nodesInLevel != expectedNodes)
            {
                return false;
            }
            expectedNodes *= 2;

            while (nodesInLevel--)
            {
                Node* node = q.front();
                q.pop();

                if (node->Left == NULL && node->Right == NULL)
                {
                    // This is a leaf node
                    if (level == 0)
                    {
                        // This is the first level with leaf nodes
                        level = 1;
                    }
                    else if (level != 1)
                    {
                        // Leaf node at a different level
                        return false;
                    }
                }
                else if (node->Left == NULL || node->Right == NULL)
                {
                    // This is not a perfect binary tree
                    return false;
                }
                else
                {
                    // Add the child nodes to the queue
                    q.push(node->Left);
                    q.push(node->Right);
                }
            }
            level++;
        }

        return true;
    }

    bool isCompleteBinaryTree()
    {
        if (root == NULL)
        {
            return true;
        }

        queue<Node*> q;
        q.push(root);
        bool isLastLevel = false;

        while (!q.empty())
        {
            Node* node = q.front();
            q.pop();

            if (node->Left == NULL && node->Right != NULL)
            {
                // This is not a complete binary tree
                return false;
            }

            if (isLastLevel && (node->Left != NULL || node->Right != NULL))
            {
                // This is not a complete binary tree
                return false;
            }

            if (node->Left != NULL)
            {
                q.push(node->Left);
            }

            if (node->Right != NULL)
            {
                q.push(node->Right);
            }

            if (node->Left == NULL || node->Right == NULL)
            {
                // This is the last level
                isLastLevel = true;
            }
        }

        return true;
    }



};

int main()
{
    Binary_tree bt;
    bt.Insertion(0,5);
    bt.Insertion(1,10);
    bt.Insertion(2,15);
    bt.Insertion(3,20);
    bt.Insertion(4,25);
    bt.Insertion(5,30);
    bt.Insertion(6,35);
    bt.Insertion(7,40);
    bt.Insertion(8,45);
    bt.Insertion(9,50);
    bt.Insertion(10,100);

    bt.BFS_traverse();
    cout << '\n';
    bt.DFS_traverse(bt.root);
    cout << '\n';
    bt.InOrder(bt.root);
    cout << '\n';
    bt.PreOrder(bt.root);
    cout << '\n';
    bt.PostOrder(bt.root);
    cout << '\n';
    bt.Searching(25);
    cout << '\n';

    cout << endl << endl;
    cout << bt.isCompleteBinaryTree() << '\n';
    cout << bt.isPerfectBinaryTree() << '\n';
    return 0;
}

