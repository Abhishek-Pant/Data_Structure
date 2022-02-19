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
Input :
----> n,k
   n-->steps
   max jump of k at each step
   i.e if k=4 then possible ways are 1,2,3,4
output :
   #ways to reach nth step
*/

ll ladder(ll n,ll k)// recursive approch
{
    if(n==0)
        return 1;
    ll ways=0;
    for(ll i=1;i<=k;i++)
    {
        if(n-i>=0){
        ways+=ladder(n-i,k);
        }
    }
    return ways;
}

ll top_down_ladder(ll n,ll k,ll dp[])
{
    if(n==0)
        return 1;
    if(dp[n]!=0)
        return dp[n];
    ll ways=0;
    for(ll i=1;i<=k;i++)
    {
        if(n-i>=0)
        {
            ways+=top_down_ladder(n-i,k,dp);
        }
    }
    return dp[n]=ways;
    //0(n*k)
    //0(n)
}

ll bottom_up_ladder(ll n,ll k)
{
    ll dp[100]={0};
    dp[0]=1;
    for(ll i=1;i<=n;i++)
    {
        for(ll j=1;j<=k;j++)
        {
            if(i-j>=0)
                dp[i]+=dp[i-j];
        }
    }
    return dp[n];
    //0(n*k)
    //0(n)
}

ll optimize_bottom_up_ladder(ll n,ll k)
{
    ll dp[100]={0};
    dp[0]=dp[1]=1;
    for(ll i=2;i<=n;i++)
    {
        dp[i]=dp[i-1]*2;
        i-k-1>=0?dp[i]-=dp[i-k-1]:dp[i]-=0;
    }
    return dp[n];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n,k; cin>>n>>k;
    ll dp[100]={0};
    cout<<ladder(n,k)<<" ";
    cout<<top_down_ladder(n,k,dp)<<" ";
    cout<<bottom_up_ladder(n,k)<<" ";
    cout<<optimize_bottom_up_ladder(n,k);
    return 0;
}

