#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    map<int, int> mp;
    bool c = true;
    int ans=-1,val=-1;
    for(int i=0; i<n; i++)
    {
        int x;
        cin >> x;
        if(c && mp[x]!=0)
        {
            c = false;
            ans = mp[x]-1;
            val = x;
        }
        mp[x] = i+1;

    }
    cout << "First duplicate element is " << val << ", first occurring at index " << ans << '\n';
    return 0;
}

