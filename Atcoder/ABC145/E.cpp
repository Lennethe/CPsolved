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
    ll n,t;
    cin>>n>>t;
    vector<P> cost_value(n);
    FOR(i,0,n)cin>>cost_value[i].first>>cost_value[i].second;
    vector<vector<ll>> dp(n+1,vector<ll>(t,0));

    FOR(i,1,n+1){
        FOR(j,0,t){
            ll value = cost_value[i-1].second;
            ll cost = cost_value[i-1].first; 
            dp[i][j] = dp[i-1][j];
            if(j-cost>=0 && dp[i][j] < dp[i-1][j-cost] + value){
                dp[i][j] = dp[i-1][j-cost] + value;
            }
        }
    }
    vector<ll> trace(n);
    ll x=n,y=t-1;
    while(x>0 && y>0){
        if(dp[x-1][y] != dp[x][y]){
            trace[x-1] = 1;
            y -= cost_value[x-1].first;
        }
        x--;
    }



//    FOR(i,0,n+1){
//        FOR(j,0,t){
//            cout<<dp[i][j]<<" ";
//        }
//        cout<<endl;
 //   }
    ll res = 0;
    FOR(i,0,n){
        if(trace[i] == 0){
//            cout<<" no used "<<i<<endl;
            res = max(res, cost_value[i].second);
        }
    }
    cout<<dp[n][t-1]+res<<endl;
}