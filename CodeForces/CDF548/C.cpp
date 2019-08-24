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

struct UnionFind {
  vector<ll> data;
  UnionFind(ll size) : data(size, -1) { }
  bool unionSet(ll x, ll y) {
    x = root(x); y = root(y);
    if (x != y) {
      if (data[y] < data[x]) swap(x, y);
      data[x] += data[y]; data[y] = x;
    }
    return x != y;
  }
  bool findSet(ll x, ll y) {
    return root(x) == root(y);
  }
  int root(ll x) {
    return data[x] < 0 ? x : data[x] = root(data[x]);
  }
  int size(ll x) {
    return -data[root(x)];
  }
};

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll n,k;
    cin>>n>>k;
    UnionFind uni(n+1);
    ll mod = 1e9+7;
    FOR(i,1,n){
      ll in1,in2,f;
      cin>>in1>>in2>>f;
      if(f == 0) uni.unionSet(in1,in2);
    }

    map<ll,ll> used;
    deque<ll> q;
    FOR(i,1,n+1){
      int set = uni.root(i);
      if(used[set] == 0){
        q.push_back(uni.size(i));
        used[set]=1;
      }
    }

    ll res = 1;
    FOR(i,0,k){
      res = res*n % mod;
    }

    while(!q.empty()){
      ll x = q.front();
      q.pop_front();
      ll tmp = 1;
      FOR(i,0,k){
        tmp = tmp*x % mod;
      }
      res -= tmp;
      if(res<0) res+=mod;
    }

    cout<<res<<endl;


}
