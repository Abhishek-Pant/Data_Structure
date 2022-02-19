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

int binarysearch(int a[],int key,int s,int e)
{
    while(e>s)
    {
        int mid=s+(e-s)/2;
        if(a[mid]==key)
            return mid;
        else if(a[mid]>key)
            e=mid-1;
        else if(a[mid]<key)
            s=mid+1;
    }
    return -1;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int a[10]={1,2,3,4,5,6,7,8,9,10};
    int s=0;
    int e=sizeof(a)/sizeof(a[0])-1;
    cout<<binarysearch(a,9,s,e);
    return 0;
}
