#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    set<int> s;
    for(int i=0; i<n; i++)
    {
        int x;
        cin >> x;
        s.insert(x);
    }
    int m;
    cin >> m;
    set<int> Intersecton;
    for(int i=0; i<m; i++)
    {
        int x;
        cin >> x;
        int prv_sz = s.size();
        s.insert(x);
        if(prv_sz == s.size())
            Intersecton.insert(x);
    }
    for(auto it: Intersecton)
        cout << it << ' ';
    return 0;
}


