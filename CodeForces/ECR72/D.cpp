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


#define REP(i,n) for(int i=0;i<(int)n;++i)
#define FORc(i,c) for(__typeof((c).begin())i=(c).begin();i!=(c).end();++i)
#define ALL(c) (c).begin(), (c).end()
typedef int Weight;
struct Edge {
  int src, dst;
  Weight weight;
  Edge(int src, int dst, Weight weight) :
    src(src), dst(dst), weight(weight) { }
};
bool operator < (const Edge &e, const Edge &f) {
  return e.weight != f.weight ? e.weight > f.weight : // !!INVERSE!!
    e.src != f.src ? e.src < f.src : e.dst < f.dst;
}
typedef vector<Edge> Edges;
typedef vector<Edges> Graph;

typedef vector<Weight> Array;
typedef vector<Array> Matrix;

bool visit(const Graph &g, int v, vector<int> &order, vector<int> &color) {
  color[v] = 1;
  FORc(e, g[v]) {
    if (color[e->dst] == 2) continue;
    if (color[e->dst] == 1) return false;
    if (!visit(g, e->dst, order, color)) return false;
  }
  order.push_back(v); color[v] = 2;
  return true;
}

bool topologicalSort(const Graph &g, vector<int> &order, vector<int> &color) {
  int n = g.size();
  REP(u, n) if (!color[u] && !visit(g, u, order, color))
    return false;
  reverse(ALL(order));
  return true;
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll m,n;
    cin>>m>>n;
    Graph g(m+1);
    vector<Edge> v;
    FOR(i,0,n){
      ll a,b;
      cin>>a>>b;
      Edge e = Edge(a,b,1);
      v.push_back(e);
      g[a].push_back(e);
    }
    vector<int> order;
    vector<int> color(m+1);

    if(topologicalSort(g,order,color) == 0){
      cout<<2<<endl;
      FOR(i,0,n){
        if(v[i].src>v[i].dst) cout<<1;
        else cout<<2;
        if(i != n-1)cout<<" ";
      }
      cout<<endl;
    }
    else{
      cout<<1<<endl;
      FOR(i,0,n){
        cout<<1;
        if(i != n-1)cout<<" ";
      }
      cout<<endl;
    }

}
