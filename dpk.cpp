#include <bits/stdc++.h>
#define FOR(i,a,b) for(int i = (a); i < (b); i++)
#define N 110
#define K 100010
using namespace std;

int n,k,a[N];
bool dp[K];

int main()
{
    cin>>n>>k;
    FOR(i,0,n) cin>>a[i];
    sort(a,a+n);
    FOR(i,a[0],k+1)
    {
        FOR(j,0,n)
        {
            if(i-a[j]<0) break;
            else if(!dp[i-a[j]])
            {
                dp[i]=1;
                break;
            }
        }
    }
    cout<<(dp[k]?"First":"Second")<<'\n';

    return 0;
}