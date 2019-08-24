//#define _GLIBCXX_DEBUG
#include <iostream>
#include <vector>
#include <stdio.h>
#include <bits/stdc++.h>


using namespace std;
#define ll long long
#define ld long double
#define  P pair<ll,ll>
#define FOR(i,n,m) for(ll i=n; i<(ll)m;i++)
#define FORa(i,c) for(__typeof((c).begin())i=(c).begin();i!=(c).end();++i)
#define FORr(i,m,n) for(ll i=n; i>=(ll)m; i--)
#define FORm(i,m) for(auto i=m.begin();i!=m.end();i++)
#define FORs(i,st) for(auto i : st)
#define REP(i,n) for(int i=0;i<(int)n;++i)
#define ALL(c) (c).begin(), (c).end()
#define VEC2(x,a,b) vector<vector<ll>> x = vector<vector<ll>>(a,vector<ll>(b,0))
#define sortAl(v) sort(v.begin(),v.end())
#define sortAlr(v) sort(v.begin(),v.end()); reverse(v.begin(),v.end())
#define cinv(v,n,m) FOR(i,n,m) cin>>v.at(i)
#define coutv(v,n,m) FOR(i,n,m) cout<<v.at(i) <<" "; cout<<endl
#define cout(n) cout<<fixed<<setprecision(n)
//計算量O(E)


//    Edges := 重み付き辺の集合
//    WeightedGraph := 重み付きグラフ
//    UnWeightedGraph := 重み無しグラフ
//    Matrix := 距離行列
template< typename T >
struct edge {
  ll src, to;
  T cost;

  edge(ll to, T cost) : src(-1), to(to), cost(cost) {}

  edge(ll src, ll to, T cost) : src(src), to(to), cost(cost) {}

  edge &operator=(const int &x) {
    to = x;
    return *this;
  }

  operator ll() const { return to; }
};

template< typename T >
using Edges = vector< edge< T > >;
template< typename T >
using WeightedGraph = vector< Edges< T > >;
using UnWeightedGraph = vector< vector< ll > >;
template< typename T >
using Matrix = vector< vector< T > >;


template< typename T >
pair< T, int > dfs(const WeightedGraph< T > &g, int idx, int par)
{
  pair< T, int > ret(0, idx);
  for(auto &e : g[idx]) {
    if(e.to == par) continue;
    auto cost = dfs(g, e.to, idx);
    cost.first += e.cost;
    ret = max(ret, cost);
  }
  return ret;
}

template< typename T >
T tree_diameter(const WeightedGraph< T > &g)
{
  auto p = dfs(g, 0, -1);
  auto q = dfs(g, p.second, -1);
  return (q.first);
}


int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll n;
    cin>>n;
    WeightedGraph<ll> g(n);
    FOR(i,1,n){
      ll in1,in2;
      cin>>in1>>in2;
      in1--;
      in2--;
      g[in1].push_back(edge<ll>(in1,in2,1));
      g[in2].push_back(edge<ll>(in2,in1,1));
    }
    ll x = tree_diameter<ll>(g);

    if(x % 3 == 1 ) cout<<"Second"<<endl;
    else cout<<"First"<<endl;

}
