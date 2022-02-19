#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")

#include <bits/stdc++.h>

using namespace std;

#define ll long long int
#define llu long long unsigned int
#define ld long double
#define pb push_back
#define en '\n'

#define repi(i,n) for(ll i=0;i<n;i++)
#define repn(i,a,n) for(ll i=a;i<n;i++)
#define repan(i,a,n) for(ll i=0;i<=n;i++)

const ll mod=1e9+7;

/*
 There's a scientist named Brook who is intersted in budding of
 cells. He has one container which initially contains only
 a single cell. Now Brook wants n numbers of cells in the
 container. So he can change the number of cells in container in
 3 different ways:
 1. Double the number of cells present in the container.
 2. Increase the number of cells int the container by 1.
 3. Decrease the number of cells int the container by 1.
 Now all the above operations have a different costs associated
 with them x,y,z respectively for above operation. Help brook
 in finding the minimum cost to generate n cells in the container
 starting from one cell

 Input: n
        x,y,z
 Output: minimum cost
*/

ll cellproblem(ll n,ll x,ll y,ll z)// bottom up approch
{
    ll dp[n+1]={0};
    dp[0]=dp[1]=0;
    for(ll i=0;i<=n;i++)
    {
        if(i&n)
        {
            dp[i]=min(dp[i-1]+y,dp[(i+1)/2]+x+z);
        }
        else
        {
            dp[i]=min(dp[i+1]+y,dp[(i+1)/2]+x+z);
        }
    }
    return dp[n];
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n,x,y,z;
    cin>>n>>x>>y>>z;
    cout<<cellproblem(n,x,y,z);
    return 0;
}

