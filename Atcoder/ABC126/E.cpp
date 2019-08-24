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
    vector<ll> v(n+1);

    UnionFind u(n+1);
    FOR(i,0,m){
      ll in1,in2,c;
      cin>>in1>>in2>>c;
      u.unionSet(in1,in2);
    }

    ll ans = n;
    FOR(i,1,n+1){
      v[u.size(i)]++;
    }

    FOR(i,1,n+1){
      ans -= v[i]/i*(i-1);
    }
    cout<<ans<<endl;
}
