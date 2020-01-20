#include <bits/stdc++.h>
#define FOR(i,a,b) for(int i = (a); i < (b); i++)
#define ll long long
#define M 1000000007
#define N 200010
using namespace std;

int n,h[N];
ll mx,ans,a[N],t[N];

ll get(int p)
{
    ll ret=0;
    while(p>0)
    {
        ret=max(ret,t[p]);
        p-=p&(-p);
    }
    return ret;
}

void put(int p,ll v)
{
    while(p<N)
    {
        t[p]=max(t[p],v);
        p+=p&(-p);
    }
}

int main()
{
    cin>>n; 
    FOR(i,0,n) cin>>h[i];
    FOR(i,0,n) cin>>a[i];
    FOR(i,0,n)
    {
        mx=get(h[i]);
        put(h[i],mx+a[i]);
        ans=max(ans,mx+a[i]);
    }
    cout<<ans<<'\n';

    return 0;
}