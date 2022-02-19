#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")

#include <bits/stdc++.h>

using namespace std;

#define ll long long int
#define llu long long unsigned int
#define ld long double
#define ff first
#define ss second
#define mp(x,y) make_pair(x,y)
#define pll pair<ll,ll>
#define pb push_back
#define sz size
#define en '\n'

#define repi(i,n) for(ll i=0;i<n;i++)
#define repn(i,a,n) for(ll i=a;i<n;i++)
#define repan(i,a,n) for(ll i=0;i<=n;i++)


ll inf = 1e18;
ll mod = 1e9 + 7 ;

void sortarray(int a[],int n)
{
    int s=0,e=n-1;
    while(s<e)
    {
        if(a[s]==0&&a[e]==1)
        {
            s++;
        }
        else if(a[s]==0&&a[e]==2)
        {
            s++;
            e--;
        }
        else if(a[s]==0&&a[e]==0)
        {
            s++;
        }
        else if(a[s]==1&&a[e]==2)
        {
            e--;
        }
        else if(a[s]==1&&a[e]==0)
        {
            swap(a[s],a[e]);
            s++;
        }
        else if(a[s]==1&&a[e]==1)
        {
            s++;
            e--;
        }
        else if(a[s]==2&&a[e]==0)
        {
            swap(a[s],a[e]);
            s++;
            e--;
        }
        else if(a[s]==2&&a[e]==1)
        {
            swap(a[s],a[e]);
            e--;
        }
        else if(a[s]==2&&a[e]==2)
        {
            e--;
        }
    }
    return;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int a[]={0,1,2,1,1,1,2,0,0,0,1,0,2,2,0};
    int n=sizeof(a)/sizeof(a[0]);
    sortarray(a,n);
    for(int i=0;i<n;i++)
        cout<<a[i]<<" ";
    return 0;
}
