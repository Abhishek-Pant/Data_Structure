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

ll fr(ll n,ll dp[])
{
    if(n==0||n==1)
        return n;
    if(dp[n]!=0)
        return dp[n];
    else
        return fr(n-1,dp)+fr(n-2,dp);
}
ll fi(ll n,ll dp[])
{
    if(n==1||n==0)
        return n;
    dp[0]=0;
    dp[1]=1;
    for(ll i=2;i<1000;i++)
        dp[i]=dp[i-1]+dp[i-2];
    return dp[n];
}
ll space_optimisation_fi(ll n)
{
    if(n==1||n==0)
        return n;
    ll a=0;
    ll b=1,c=0;
    n--;
    while(n--){
       c=a+b;
       a=b;
       b=c;
    }
    return c;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n; cin>>n;
    ll dp[1000]={0};
    ll val1=space_optimisation_fi(n);
    cout<<val1<<en;
    ll val2=fi(n,dp);
    cout<<val2<<en;
    ll val3=fr(n,dp);
    cout<<val3<<en;
    return 0;
}
