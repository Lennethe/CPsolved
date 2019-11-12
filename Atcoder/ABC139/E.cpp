//#define _GLIBCXX_DEBUG
#include <iostream>
#include <bits/stdc++.h>
    
    
using namespace std;
#define ll long long
#define ld long double
#define  P pair<int,int>
#define FOR(i,n,m) for(ll i=n; i<(ll)m;i++)
#define FORr(i,m,n) for(ll i=n; i>=(ll)m; i--)
#define FORm(i,m) for(auto i=m.begin();i!=m.end();i++)
#define sortAl(v) sort(v.begin(),v.end())
#define sortAlr(v) sort(v.begin(),v.end()); reverse(v.begin(),v.end())
#define cout(n) cout<<fixed<<setprecision(n)
    
class TopologicalSort {
  using Graph = std::vector<std::vector<int>>;
  // 頂点数
  int V;
  std::vector<std::vector<int>> G;
  void dfs(int v, std::vector<int> &res, std::vector<int> &used) {
    used[v] = 1;
    for (auto to : G[v])
      if (used[to] == 0) {
        dfs(to, res, used);
      }
    res.push_back(v);
  }

 public:
  TopologicalSort(int _v) : V(_v), G(_v) {}
  void addEdge(int a, int b) {
    assert(0 <= a && a < V);
    assert(0 <= b && b < V);
    G[a].push_back(b);
  }
  std::vector<int> topologicalSort() {
    std::vector<int> ide(V);
    for (int i = 0; i < V; i++) {
      for (auto to : G[i]) {
        ide[to]++;
      }
    }
    std::vector<int> res;
    std::vector<int> used(V);
    for (int i = V - 1; i >= 0; i--) {
      if (ide[i] == 0) {
        dfs(i, res, used);
      }
    }
    if (res.size() == 0) res = {-1};
    reverse(res.begin(), res.end());
    return res;
  }
};

P sortP(int a, int b){
    return P(min(a,b), max(a,b));
}
int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n;
    cin>>n;
    vector<vector<int>> v(n*(n-1));
    map<P,int> key;
    int t = 1;
    TopologicalSort T(n*(n-1)+1);
    FOR(i,0,n){
        vector<P> tmp;
        FOR(j,0,n-1){
            int in;
            cin>>in;            
            tmp.push_back(sortP(i, in-1));
            key[sortP(i,in-1)] = t;
            t++;
        }

        FOR(j,1,n-1){
            int from = key[tmp[j-1]];
            int to = key[tmp[j]];
            v[from].push_back(to);
            T.addEdge(from,to);
        }
    }

    vector<int> x = T.topologicalSort();
    FOR(i,0,x.size()){
        cout<<x[i]<<endl;
    }



}