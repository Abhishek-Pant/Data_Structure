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

char nextalphabet(char a[],char c,int n)
{
    char ans='!';
    int s=0,e=n-1;
    while(s<=e)
    {
        int mid=s+(e-s)/2;
        if(a[mid]==c)
            return a[mid+1];
        else if(a[mid]>c)
        {
            ans=a[mid];
            e=mid-1;
        }
        else if(a[mid]<c)
            s=mid+1;
    }
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    char a[]= {'a','b','c','f','h','i','j','m','n'};
    int n=sizeof(a)/sizeof(a[0]);
    cout<<nextalphabet(a,'f',n);
    return 0;
}
