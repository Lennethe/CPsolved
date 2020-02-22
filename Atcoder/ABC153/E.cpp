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
    ll h,n;
    cin>>h>>n;
    vector<P> v(n);
    FOR(i,0,n)cin>>v[i].first>>v[i].second;
    vector<vector<ll>> dp(n+1,vector<ll>(h+1,1e9));
    FOR(i,0,n+1)dp[i][0] = 0;
    //FOR(i,0,h)dp[0][i] = 0;

    FOR(i,1,n+1){
        FOR(j,1,h+1){
            ll dmg = v[i-1].first;
            ll mp = v[i-1].second;
            ll pre = max((ll)0, j-dmg);
            dp[i][j] = min(dp[i-1][j], dp[i][pre] + mp);
        }
    }

    cout<<dp[n][h]<<endl;

}