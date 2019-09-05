//#define _GLIBCXX_DEBUG
#include <iostream>
#include <vector>
#include <stdio.h>
#include <bits/stdc++.h>


using namespace std;
#define ll long long
#define ld long double
#define  P pair<ll,ll>
#define FOR(i,n,m) for(ll i=n; i<(ll)m;i++)
#define FORa(i,c) for(__typeof((c).begin())i=(c).begin();i!=(c).end();++i)
#define FORr(i,m,n) for(ll i=n; i>=(ll)m; i--)
#define FORm(i,m) for(auto i=m.begin();i!=m.end();i++)
#define FORs(i,st) for(auto i : st)
#define REP(i,n) for(int i=0;i<(int)n;++i)
#define ALL(c) (c).begin(), (c).end()
#define VEC2(x,a,b) vector<vector<ll>> x = vector<vector<ll>>(a,vector<ll>(b,0))
#define sortAl(v) sort(v.begin(),v.end())
#define sortAlr(v) sort(v.begin(),v.end()); reverse(v.begin(),v.end())
#define cinv(v,n,m) FOR(i,n,m) cin>>v.at(i)
#define coutv(v,n,m) FOR(i,n,m) cout<<v.at(i) <<" "; cout<<endl
#define cout(n) cout<<fixed<<setprecision(n)

ll dp[303030][5];


int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);

    ll n,x;
    cin>>n>>x;

    FOR(i,1,n+1){
      ll in;
      cin>>in;
      dp[i][0] = 0;
      dp[i][1] = max(max(dp[i-1][0], dp[i-1][1]) + in, dp[i][0]);
      dp[i][2] = max(max(dp[i-1][1], dp[i-1][2]) + in*x, dp[i][1]);
      dp[i][3] = max(max(dp[i-1][2], dp[i-1][3]) + in, dp[i][2]);
      dp[i][4] = max(dp[i-1][4], dp[i][3]);

    }
    cout<<dp[n][4]<<endl;

}
