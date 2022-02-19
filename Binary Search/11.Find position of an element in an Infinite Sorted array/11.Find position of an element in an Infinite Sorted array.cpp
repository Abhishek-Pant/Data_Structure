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

int binarysearch(int a[],int s,int e,int key)
{
    while(s<=e)
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
    int a[]={1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31,32,33,34,35,36,37,38,39,40,41,42,43,44,45,46,47,48,49,50};
    int n=sizeof(a)/sizeof(a[0]);
    int key=24;
    int s=0,e=1;
    while(a[e]<key)
    {
        s=e;
        e=e*2;
    }
    cout<<binarysearch(a,s,e,key);
    return 0;
}
