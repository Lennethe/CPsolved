//#define _GLIBCXX_DEBUG
#include <iostream>
#include <bits/stdc++.h>
    
    
using namespace std;
#define ll long long
#define ld long double
#define  P pair<ll,ll>
#define FOR(i,n,m) for(ll i=n; i<(ll)m;i++)
#define FORr(i,m,n) for(ll i=n; i>=(ll)m; i--)
#define FORm(i,m) for(auto i=m.begin();i!=m.end();i++)
#define sortAl(v) sort(v.begin(),v.end())
#define sortAlr(v) sort(v.begin(),v.end()); reverse(v.begin(),v.end())
#define cout(n) cout<<fixed<<setprecision(n)
#define dout(n) cout<<# n<<" = "<<n<<endl;
    
int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll x,n;cin>>x>>n;
    vector<ll>v(2*n);
    FOR(i,0,n)cin>>v[i];
    FOR(i,0,n)v[n+i] = v[i]+x;
    ll ans = 1e9;
    FOR(i,0,n){
        ans = min(ans,v[n-1+i]-v[i]);
    }
    cout<<ans<<endl;
    
}