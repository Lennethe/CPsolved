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

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);

    ll n,m;
    cin>>n>>m;
    vector<ll> v(n+1);
    vector<ll> skip(n+1);
    FOR(i,0,m){
      ll in;
      cin>>in;
      skip[in] = 1;
    }
    ll mod = 1e9+7;
    v[0] = 1;

    FOR(i,0,n-1){
      if(skip[i+1] == 0) v[i+1] = (v[i+1] + v[i])%mod;
      if(skip[i+2] == 0) v[i+2] = (v[i+2] + v[i])%mod;
    }
    if(skip[n] == 0) v[n] = (v[n] + v[n-1])%mod;

    cout<<v[n]<<endl;

}
