#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    string s;
    cin >> s;
    string ans = "";
    stack<char> A;

    for(int i=0; i<s.size(); i++)
    {
        if(s[i]>='a' && s[i]<='z')
            ans+=s[i];
        else if(!A.empty() && (s[i]=='+' || s[i]=='-') && (A.top()=='*' || A.top()=='/'))
        {
            while(!A.empty())
            {
                char x = A.top();
                ans+=x;
                A.pop();
            }
            A.push(s[i]);
        }
        else
        {
            A.push(s[i]);
        }
    }
    while(!A.empty())
    {
        char x = A.top();
        ans+=x;
        A.pop();
    }
    cout << ans;
    return 0;
}
