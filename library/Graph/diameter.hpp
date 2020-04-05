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
#define dout(n) cout<<# n<<" = "<<n<<endl;


struct diameter{
    struct edge{int to, cost;};
    vector< edge > g[200020];
    long long dist[200020];

    void dfs1(int idx, int par){
    for(edge &e : g[idx]) {
        if(e.to == par) continue;
        dfs1(e.to, idx);
        dist[idx] = max(dist[idx], dist[e.to] + e.cost);
    }
    }

    int dfs2(int idx, int d_par, int par){
    vector< pair< int, int > > d_child;
    d_child.emplace_back(0, -1); // 番兵みたいなアレ
    for(edge &e : g[idx]) {
        if(e.to == par) d_child.emplace_back(d_par + e.cost, e.to);
        else d_child.emplace_back(e.cost + dist[e.to], e.to);
    }
    sort(d_child.rbegin(), d_child.rend());
    int ret = d_child[0].first + d_child[1].first; // 最大から 2 つ
    for(edge &e : g[idx]) {
        if(e.to == par) continue;
        // 基本は d_child() の最大が d_par になるが, e.to の部分木が最大値のときはそれを取り除く必要がある
        ret = max(ret, dfs2(e.to, d_child[d_child[0].second == e.to].first, idx));
    }
    return (ret);
    }

    int get(){
        dfs1(1,-1);
        return dfs2(1,0,-1);
    }
};

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);

    int n;
    cin>>n;
    diameter d;
    for(int i = 0; i < n - 1; i++) {
        int a, b, w;
        cin >> a >> b >> w;
        d.g[a].push_back({b, w});
        d.g[b].push_back({a, w});
    }
    cout << d.get() << endl;
}
