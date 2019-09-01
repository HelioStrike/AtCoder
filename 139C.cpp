#include <bits/stdc++.h>
#define FOR(i,a,b) for(int i = (a); i < (b); i++)
using namespace std;

int main()
{
    int n; cin>>n;
    int x,p,cur,ans;
    cin>>p; cur=ans=0;
    FOR(i,1,n)
    {
        cin>>x;
        if(x<=p) cur++,ans=max(ans,cur);
        else cur=0;
        p=x;
    }
    cout<<ans<<'\n';

    return 0;
}