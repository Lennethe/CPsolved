#define _GLIBCXX_DEBUG
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

using Result = std::pair<int, int>;
struct Edge {
  int from, to, cost;
  Edge(int from, int to, int cost) : from(from), to(to), cost(cost) {}
};

using Edges = std::vector<Edge>;
using Graph = std::vector<Edges>;

Result visit(int p, int v, const Graph &g) {
    cout<<v<<endl;
  Result r(0, v);
  for(auto& e : g[v]) if (e.to != p) {
    Result t = visit(v, e.to, g);
    t.first += e.cost;
    if (r.first < t.first) r = t;
  }
  return r;
}
int diameter(const Graph &g) {
    cout<<"we"<<endl;
  Result r = visit(-1, 0, g);
  Result t = visit(-1, r.second, g);
  return t.first; // (r.second, t.second) is farthest pair
}
int INF = -12;
int bfs01(const Graph &g, int s) {
  int n = g.size();
  std::vector<int> d(n, INF);
  std::deque<int> que;
  que.push_back(s);
  d[s] = 0;
  while (!que.empty()) {
    int cur = que.front();
    que.pop_front();
    for (auto p : g[cur]) {
      int dst = p.to, w = p.cost;
      assert(w == 0 || w == 1);
      if (d[dst] != INF) continue;
      if (w == 0) {
        d[dst] = d[cur];
        que.push_front(dst);
      } else {
        d[dst] = d[cur] + 1;
        que.push_back(dst);
      }
    }
  }
  int res = 0;
  FOR(i,0,n) res = max(res,d[i]);
  return res;
}

bool bi(vector<string> &g, int n){
    vector<int> v(n,-1);
    v[0]  = 0;
    vector<int> used(n);
    deque<int> q;
    q.push_back(0);
    used[0] = 1;

    while(!q.empty()){
        int t = q.front();
        q.pop_front();
        int tmp_n = v[t];        
        FOR(i,0,n){
            int tmp_to = tmp_n ^ (g[t][i] - '0');
            if(tmp_n ^ tmp_to){
                if(used[i] == 0){
                    v[i] = tmp_to;
                    used[i] = 1;
                    q.push_back(i);
                } 
                if(v[i] != tmp_to) return false;
            }
        }
    }
    return true;
}


int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n;
    cin>>n;
    vector<string> v(n);
    Graph g(n);
    FOR(i,0,n){
        cin>>v[i];
        FOR(j,0,n)if(v[i][j] == '1') g[i].emplace_back(Edge(i,j,1));
    }

    if(!bi(v,n)) cout<<-1<<endl;
    else{
        int x = 0;
        FOR(i,0,n)x = max(bfs01(g,i),x);
        cout<<x+1<<endl;
    }
    
}