#include <bits/stdc++.h>
#define FOR(i,a,b) for(int i = (a); i < (b); i++)
using namespace std;

void nuu() { printf("-1"); exit(0); }

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n,x; scanf("%d",&n);
    set<int> v;
    list<int> a[n+1]; FOR(i,1,n+1) { FOR(j,1,n) scanf("%d",&x),a[i].push_back(x); v.insert(i); }

    int nfights,days=0;
    while(1)
    {
        map<int,int> done;
        nfights=0;
        for(int i: v)
        {
            if(a[i].empty() || a[a[i].front()].empty()) continue;
            int j=a[i].front();
            if(done[i] || done[j]) continue;
            if(a[j].front()==i)
            {
                done[i]=done[j]=1;
                a[j].pop_front();
                a[i].pop_front();
                if(a[j].empty()) v.erase(j);
                if(a[i].empty()) v.erase(i);
                nfights++;
            }
        }
        if(!nfights) break;
        days++;
    }
    FOR(i,1,n+1) if(!a[i].empty()) nuu();
    printf("%d\n",days);

    return 0;
}