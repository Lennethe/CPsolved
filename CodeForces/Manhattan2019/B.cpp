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
    map<ll,ll> mp;
    vector<ll> v(n);
    ll over = 0;
    FOR(i,0,n){
      ll x;
      cin>>x;
      if(mp[x] >= 1)over++;
      v[i] = x;
      mp[x]++;
    }
    ll ans = n-1;
    if(over == 0) ans = 0;
    FOR(i,0,n){
      map<ll,ll> org = mp;
      map<ll,ll> tmp;
      ll t_o = over;
      ll t = 0;
      FOR(j,i,n){
        t++;
        if(mp[v[j]] - tmp[v[j]] > 1) t_o--;
        if(t_o == 0) ans = min(ans,t);
        tmp[v[j]]++;
      }
    }
    cout<<ans<<endl;
}
