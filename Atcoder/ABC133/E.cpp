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
    ll n,k;
    cin>>n>>k;
    vector<vector<ll>> g(n+1);
    FOR(i,0,n-1){
      ll a,b;
      cin>>a>>b;
      g[a].push_back(b);
      g[b].push_back(a);
    }
    vector<ll> v(n+1,k-2);
    v[1] = k;
    FOR(i,0,g[1].size()){
      ll x = g[1][i];
      v[x] = k-1;
    }

    deque<ll> q;
    q.push_back(1);
    vector<ll> used(n+1);
    used[1] = 1;
    ll ans = k;
    ll MOD = 1e9+7;
    while(!q.empty()){
      ll from = q.front();
      q.pop_front();
      ll f = 0;
      FOR(i,0,g[from].size()){
        ll to = g[from][i];
        if(used[to] == 0){
//          cout<<to<<" "<<v[to]<<" - "<<f<<endl;
          used[to] = 1;
          q.push_back(to);
          ans = ans*(v[to] - f)%MOD;
          f++;
        }
      }
    }
    cout<<ans<<endl;
}
