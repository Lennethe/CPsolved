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
    
int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll n,x,y;
    cin>>n>>x>>y;
    x--;y--;
    vector<vector<ll>> v(n,vector<ll>(n,1e9));
    FOR(i,0,n){
        deque<ll> q;
        q.push_back(i);
        v[i][i] = 0;
        while(!q.empty()){
            ll from = q.front();
            q.pop_front();
            if(0<from && v[i][from-1]==1e9){
                v[i][from-1] = v[i][from]+1;
                q.push_back(from-1);
            }
            if(from<n-1 && v[i][from+1]==1e9){
                v[i][from+1] = v[i][from]+1;
                q.push_back(from+1);
            }
            if(from == x && v[i][y] == 1e9){
                v[i][y] = v[i][x]+1;
                q.push_back(y);
            }       
            if(from == y && v[i][x] == 1e9){
                v[i][x] = v[i][y]+1;
                q.push_back(x);
            }       
        }
    }
    vector<ll> ans(n);
    FOR(i,0,n){
        FOR(j,i+1,n){
            ans[v[i][j]]++;
        }
    }
    FOR(i,1,n){
        cout<<ans[i]<<endl;
    }
}