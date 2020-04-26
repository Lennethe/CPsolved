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
#define REV(v) reverse(v.begin(),v.end())
#define sortAl(v) sort(v.begin(),v.end())
#define sortAlr(v) sort(v.begin(),v.end()); reverse(v.begin(),v.end())
#define cout(n) cout<<fixed<<setprecision(n)
#define dout(n) cout<<# n<<" = "<<n<<endl;
#define v1out(v) FOR(j,0,v.size()){cout<<v[j]; if(j!=(ll)v.size()-1)cout<<" ";else cout<<endl; }
#define v2out(v) FOR(i,0,v.size())v1out(v[i]);

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
    ll n,k;
    cin>>n>>k;
    vector<vector<ll>> v(n+1);
    FOR(i,0,n-1){
        ll a,b;
        cin>>a>>b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    vector<P> ans;
    deque<ll> q;
    vector<ll> used(n+1,-1); 
    q.push_back(1);
    used[1] = 0;
    while(!q.empty()){
        ll from = q.front();
        q.pop_front();
        FOR(i,0,v[from].size()){
            ll to = v[from][i];
            if(used[to] != -1)continue;
            used[to] = used[from]+1;
            q.push_back(to);
            cout<<to<<endl;
            ans.push_back(P(used[from]+1,to));
        }
    }
    sortAlr(ans);

    UnionFind u(n+1);
    map<ll,ll> dist;
    vector<ll> ini(n+1,-1);
    used = ini;
    FOR(i,0,k){
        ll from = ans[i].second;
        used[from] = 0;
        FOR(j,0,v[from].size()){
            ll to = v[from][j];

            if(used[to] == -1)continue;
            cout<<" unit "<<from<<" "<<to<<endl;
            u.unite(from,to);
            dist[u.find(from)] = ans[i].first;
            cout<<"fi "<<ans[i].first<<endl;
        }
    }
    ll ret = 0;
    FOR(i,1,n+1){
        cout<<"i "<<i<<" "<<u.find(i)<<endl;
    }
    FOR(i,0,k){
        cout<<dist[u.find(ans[i].second)]<<endl;
        ret += dist[u.find(ans[i].second)];
        if(dist[u.find(ans[i].second)] == 0)ret+=ans[i].first;
        if(dist[u.find(ans[i].second)] == 0)cout<<ans[i].first<<endl;;        
    }
    cout<<ret<<endl;

}