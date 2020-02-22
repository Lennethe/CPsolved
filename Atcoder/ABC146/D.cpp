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
    
int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll n;
    cin>>n;
    vector<vector<ll>> g(n+1);
    vector<ll> order(n);
    FOR(i,0,n-1){
        ll from,to;
        cin>>from>>to;
        g[from].push_back(to);
        order[i] = to;
    }
    deque<ll> q;
    q.push_back(1);
    vector<ll> res(n+1);
    while(!q.empty()){
        ll from = q.front();
        q.pop_front();
        map<ll,ll> key;
//        cout<<from<<endl;
        key[res[from]] = 1;
        ll t = 1;
        FOR(i,0,g[from].size()){
            ll to = g[from][i];
//            cout<<" "<<i<<endl;
            FOR(j,t,1e5+1){
//                cout<<"  "<<j<<endl;
                if(key[j] == 0){
                    res[to] = j;
                    key[j] = 1;
                    t = j;
                    break;
                }
            }
            q.push_back(to);
        }
    }
    ll ma = 0;
    FOR(i,1,n+1) ma = max(ma, res[i]);
    cout<<ma<<endl;
    FOR(i,0,n-1){
        cout<<res[order[i]]<<endl;
    }
}