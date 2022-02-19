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
Subarray is continous where as subsequence is random
Subarray is a subsequence but vice varsa is not true
*/

ll maxsum(ll n,ll a[])
{
    ll dp[100]={0};
    dp[0]=a[0]>0?a[0]:0;
    ll max_so_far=dp[0];
    for(ll i=1;i<n;i++)
    {
        dp[i]=a[i]+dp[i-1];
        if(dp[i]<0)
            dp[i]=0;
        max_so_far=max(max_so_far,dp[i]);
    }
    return max_so_far;
}

ll omaxsum(ll n,ll a[])// space optimize
{
    ll current_sum=0;
    a[0]>0?current_sum=a[0]:current_sum=0;
    ll max_sum=current_sum;
    for(ll i=1;i<n;i++)
    {
        current_sum+=a[i];
        if(current_sum<0)
            current_sum=0;
        max_sum=max(max_sum,current_sum);
    }
    return max_sum;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll a[]={-3,2,5,-1,6,3,-2,7,-5,2};
    ll n=sizeof(a)/sizeof(a[0]);
    cout<<maxsum(n,a)<<" ";
    cout<<omaxsum(n,a);
    return 0;
}

