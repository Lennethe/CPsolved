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
    vector<vector<ll>> g(n+1);
    FOR(i,0,m){
      ll a,b;
      cin>>a>>b;
      g[a].push_back(b);
    }
    ll M = 1e9;
    vector<vector<ll>> v(n+1,vector<ll>(3,M));
    ll s,t;
    cin>>s>>t;

    deque<P> q;
    q.push_back(P(0,s));
    while(!q.empty()){
      ll cost = q.front().first;
      ll from = q.front().second;
      q.pop_front();
//      cout<<"from = "<<from<<" cost = "<<cost<<endl;
      if(cost >= v[from][cost%3]) continue;
      else v[from][cost%3] = cost;
      FOR(i,0,g[from].size()){
        ll to = g[from][i];
        q.push_back(P(cost+1,to));
      }
    }
    if(v[t][0] == M)cout<<-1<<endl;
    else cout<<v[t][0]/3<<endl;
}
