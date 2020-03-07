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
  vector< int > data;
 
  UnionFind(int sz) {
    data.assign(sz, -1);
  }
 
  bool unite(int x, int y) {
    x = find(x), y = find(y);
    if(x == y) return (false);
    if(data[x] > data[y]) swap(x, y);
    data[x] += data[y];
    data[y] = x;
    return (true);
  }
 
  int find(int k) {
    if(data[k] < 0) return (k);
    return (data[k] = find(data[k]));
  }
 
  int size(int k) {
    return (-data[find(k)]);
  }
};

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll n,m,k;
    cin>>n>>m>>k;
    vector<ll> v(n);
    UnionFind uf(n);
    FOR(i,0,m){
        ll a,b;
        cin>>a>>b;
        a--; b--;
        uf.unite(a,b);
        v[a]++;
        v[b]++;
    }
    vector<vector<ll>> blk(n);
    FOR(i,0,k){
        ll a,b;
        cin>>a>>b;
        a--; b--;
        blk[a].push_back(b);
        blk[b].push_back(a);        
    }
    FOR(i,0,n){
        ll blc_num = 0;
        ll grp = uf.find(i);
        FOR(j,0,blk[i].size())if(grp == uf.find(blk[i][j])){
            blc_num++;
        //    cout<<blk[i][j]<<endl;
        }
        cout<<uf.size(i)-v[i]-1-blc_num;
        if(i == n-1)cout<<endl;
        else cout<<" ";
    }
}