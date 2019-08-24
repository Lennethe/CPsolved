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

    ll n,q;
    cin>>n>>q;
    vector<vector<ll>> g(n+1);
    FOR(i,1,n){
      ll in,in1;
      cin>>in>>in1;
      g[in].push_back(in1);
    }

    vector<ll> ans(n+1);
    FOR(i,0,q){
      ll in,in2;
      cin>>in>>in2;
      ans[in]+=in2;
    }
    deque<ll> que;
    que.push_back(1);
    while(!que.empty()){
      ll src = que.back();
      que.pop_back();
      FOR(i,0,g[src].size()){
        ll to = g[src][i];
        ans[to] += ans[src];
        que.push_back(to);
      }
    }

    FOR(i,1,n+1){
      cout<<ans[i];
      if(i != n)cout<<" ";
      else cout<<endl;
    }

}
