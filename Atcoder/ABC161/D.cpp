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
    ll n;
    cin>>n;
    vector<vector<ll>> dp(10);
    FOR(i,1,10)dp[0].push_back(i);
    FOR(i,0,9){
        FOR(j,0,dp[i].size()){
            ll r = dp[i][j]%10;
            ll x = dp[i][j]*10;
            if(r==0){
                dp[i+1].push_back(x+0);
                dp[i+1].push_back(x+1);                
            }
            else if(r == 9){
                dp[i+1].push_back(x+8);
                dp[i+1].push_back(x+9);                
            }
            else{
                dp[i+1].push_back(x+r-1);
                dp[i+1].push_back(x+r);
                dp[i+1].push_back(x+r+1);                
            }
        }
        sortAl(dp[i+1]);
    }

    ll x = 0;
    FOR(i,0,10){
        FOR(j,0,dp[i].size()){
            x++;
            if(x==n){
                cout<<dp[i][j]<<endl;
                return 0;
            }
        }
    }

}