#include <stdio.h>
#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define ld long double
#define  P pair<ll,ll>
#define FOR(i,n,m) for(ll i=n; i<(ll)m;i++)
#define FORr(i,m,n) for(ll i=n; i>=(ll)m; i--)
#define FORm(i,m) for(auto i=m.begin();i!=m.end();i++)
#define VEC2(x,a,b) vector<vector<ll>> x = vector<vector<ll>>(a,vector<ll>(b,0))
#define sortAl(v) sort(v.begin(),v.end())
#define sortAlr(v) sort(v.begin(),v.end()); reverse(v.begin(),v.end())
#define cinv(v,n,m) FOR(i,n,m) cin>>v.at(i)
#define coutv(v,n,m) FOR(i,n,m) cout<<v.at(i) <<" "; cout<<endl
#define cout(n) cout<<fixed<<setprecision(n)


struct UnionFind {
  vector<ll> data;
  UnionFind(ll size) : data(size, -1) { }
  bool unionSet(int x, int y) {
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
    ll n,m;
    cin>>n>>m;
    vector<P> in(m);
    FOR(i,0,m){
      ll a,b;
      cin>>a>>b;
      in[i] = P(a,b);
    }
    UnionFind uni(n+1);
    reverse(in.begin(), in.end());
    ll res = n*(n-1)/2;
    deque<ll> ans;
    FOR(i,0,m){
      ll x = in[i].first;
      ll y = in[i].second;
      ans.push_back(res);
      if(!uni.findSet(x,y)){
        ll a=uni.size(x);
        ll b=uni.size(y);
        res -= (a+b)*(a+b-1)/2 - a*(a-1)/2 - b*(b-1)/2;
      }
      uni.unionSet(x,y);

    }

    FOR(i,0,m){
      cout<<ans.back()<<endl;
      ans.pop_back();
    }
}
