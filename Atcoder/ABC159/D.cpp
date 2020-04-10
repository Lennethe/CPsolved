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
    ll n;
    cin>>n;
    vector<ll> v(2e5+1);
    vector<ll> t(n);
    FOR(i,0,n){
        cin>>t[i];
        v[t[i]]++;
    }
    ll ans=0;
    FOR(i,0,2e+5+1){
        ans += v[i]*(v[i]-1);
    }

    FOR(i,0,n){
        ll p = t[i];
        cout<<(ans - v[p]*(v[p]-1) + (v[p]-1)*(v[p]-2))/2<<endl;;
    }

}