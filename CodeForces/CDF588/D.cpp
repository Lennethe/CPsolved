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
    ll n;
    cin>>n;
    vector<P> v(n);
    FOR(i,0,n)cin>>v[i].first;
    FOR(i,0,n)cin>>v[i].second;
    sortAl(v);
    map<ll,ll> mp;
    FOR(i,0,n)mp[v[i].first]++;
    vector<ll> key;
    FORm(i,mp) if(i->second>1) key.emplace_back(i->first);

    ll ans = 0;
    FOR(i,0,n){
      ll flag = 0;
      FOR(j,0,key.size()){
        if((key[j] | v[i].first) == key[j]) flag = 1;
      }
      if(flag == 1) ans += v[i].second;
    }
    cout<<ans<<endl;
}
