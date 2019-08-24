#include <stdio.h>
#include <bits/stdc++.h>

using namespace std;
using ll=long long;
using ld=long double;
using P=pair<ll,ll>;
#define FOR(i,n,m) for(ll i=n; i<(ll)m;i++)
#define FORr(i,n,m) for(ll i=n; i>(ll)m; i--)
#define FORm(i,m) for(auto i=m.begin();i!=m.end();i++)
#define VEC2(x,a,b) vector<vector<ll>> x = vector<vector<ll>>(a,vector<ll>(b,0))
#define sortAl(v) sort(v.begin(),v.end())
#define sortAlr(v) sort(v.begin(),v.end()); reverse(v.begin(),v.end())
#define cinv(v,n,m) FOR(i,n,m) cin>>v.at(i)
#define coutv(v,n,m) FOR(i,n,m) cout<<v.at(i) <<" "; cout<<endl
#define cout(n) cout<<fixed<<setprecision(n)
int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);

  ll n,k;
  cin>>n>>k;

  vector<string> v(n);
  FOR(i,0,n){
    cin>>v[i];
  }

  VEC2(num,n,n);
  FOR(i,0,n){
    FOR(j,0,n){
      num[i][j]=-1;
    }
  }

  num[0][0]=k;
  queue<P> q;
  q.push(P(0,0));

  while(!q.empty()){
    ll a,b;
    a=q.front().first;
    b=q.front().second;

    if(b!=n-1)q.push(P(a,b+1));
    if(a!=n-1)q.push(P(a+1,b));
    if(b!=0)num[a][b]=num[a][b-1];
    if(a!=0)num[a][b]=max(num[a][b],num[a-1][b]);
    if(v[a][b]!='a')num[a][b]--;
    q.pop();
  }

  FOR(i,0,n){
    FOR(j,0,n){
      if(num[i][j]>=0)v[i][j]='a';
    }
  }

  VEC2(dp,n,n);
  FOR(i,0,n){
    FOR(j,0,n){
      dp[i][j]=1e9;
    }
  }
  dp[0][0]=v[0][0]-'a';

  q.push(P(0,0));
  while(!q.empty()){
    ll a,b;
    a=q.front().first;
    b=q.front().second;

    if(b!=n-1)q.push(P(a,b+1));
    if(a!=n-1)q.push(P(a+1,b));
    if(a!=n-1)dp[a+1][b]=min(dp[a+1][b],dp[a][b]+v[a+1][b]-'a');
    if(b!=n-1)dp[a][b+1]=min(dp[a][b+1],dp[a][b]+v[a][b+1]-'a');

    q.pop();
  }
  ll i=n-1,j=n-1;
  vector<char> res;
  res.push_back(v[i][j]);
  FOR(i,0,n){
    FOR(j,0,n){
      cout<<dp[i][j]<<" ";
    }
    cout<<endl;
  }



}
