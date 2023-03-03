#include<bits/stdc++.h>
using namespace std;

int main()
{
    string A;
    getline(cin, A);

    string word = "";
    map<string, int> mp;
    for(int i=0; i<A.size(); i++)
    {
        if(A[i]==' ')
        {
            mp[word]++;
            word = "";
        }
        else
            word+= A[i];
    }
    mp[word]++;
    word = "";
    int cnt=0;
    for(auto it:mp)
    {
        if(it.second>cnt)
        {
            word = it.first;
            cnt = it.second;
        }
    }
    cout << "Maximum occurring word is \"" << word << "\".\n";
    cout << "Occurring " << cnt << " times\n";
    return 0;
}
