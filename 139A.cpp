#include <bits/stdc++.h>
#define FOR(i,a,b) for(int i = (a); i < (b); i++)
using namespace std;

int main()
{
    string s,t; int ans=0;
    cin>>s>>t;
    FOR(i,0,s.length()) ans+=s[i]==t[i];
    cout<<ans<<'\n';

    return 0;
}