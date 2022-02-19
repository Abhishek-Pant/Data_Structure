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

void yes()
{
    cout<<"YES"<<"\n";
}
void no()
{
    cout<<"NO"<<"\n";
}

/*
Problem Name: Palindromic Queries
Problem Difficulty: None
Problem Constraints: n <= 1000,m <= 100000
Problem Description:
Given a string s and m queries .
Each query consists of (l,r) where 1 <= l <= r <= n(size of string).
You need to print whether l to r is a palindromic string or not.
A string can be called palindrome if its reverse is same as itself . Ex - "aba" .
Input Format: First line contains n
Second lines contains a string of length n.
Next line contains m where m is the number of queries .
Next m lines contains two integers l,r as described in the question.
Sample Input:
5
abbac
2
1 4
2 4
Output Format: for every query from l to r print "YES" if s[l.....r] is palindrome
else print "NO" without quotes in a new line.
Sample Output: YES
NO
*/

bool ispalindrome(string s)
{
    for(ll i=0,j=s.size()-1;i<j;i++,j--)
    {
        if(s[i]!=s[j])
            return 0;
    }
    return 1;
}

void solve(ll n,string s)
{
    ll l,r;
    cin>>l>>r;
    ll dp[n][n];
    for(ll i=0;i<n;i++)
    {
        for(ll j=i;j<n;j++)
        {
            dp[i][j]=0;
        }
    }
    for(ll i=0;i<n;i++)
    {
        string ss="";
        for(ll j=i;j<n;j++)
        {
            ss+=s[j];
            if(i==j)
               dp[i][j]=1;
            else
            {
                if(ispalindrome(ss))
                    dp[i][j]=1;
            }
        }
    }
    dp[l-1][r-1] ? yes() : no();
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n; cin>>n;
    string s;
    cin>>s;
    ll m;
    cin>>m;
    while(m--)
    {
        solve(n,s);
    }
    return 0;
}

