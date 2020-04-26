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

struct treedp{
    map<pair<int,int>,ll> depth; //深さ
    map<pair<int,int>,int> c_num;   //子供の数
    vector<vector<int>> g; //元の木
    ll q = 1;
    void dfs(int idx, int par){
        for(int& to : g[idx]){
            pair<int,int> p_node = {idx,q};
            pair<int,int> c_node = {to,q};            
            if(to == par) continue;
            depth[c_node] = 1;
            dfs(to, idx);
            depth[p_node] = min(depth[p_node], depth[c_node] - 1);
            c_num[p_node] += c_num[c_node]+1;
        }
    }

};

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll n,k;
    cin>>n>>k;
    vector<vector<int>> v(n+1);
    FOR(i,0,n-1){
        ll a,b;
        cin>>a>>b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    treedp t;
    t.g = v;
    t.dfs(1,-10);

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
            ans.push_back(P(used[to] - t.c_num[{to,1}],to));
        }
    }
    sortAlr(ans);
    ll ret = 0;
    FOR(i,0,k){
        ret += (ans[i].first);
    }
    cout<<ret<<endl;


}