#include <stdio.h>
#include <bits/stdc++.h>

using namespace std;
using ll=long long;
using ld=long double;
using P=pair<ll,ll>;
#define FOR(i,n,m) for(ll i=n; i<(ll)m;i++)
#define FORr(i,n,m) for(ll i=n; i>(ll)m; i--)
#define FORm(i,m) for(auto i=m.begin();i!=m.end();i++)
#define VEC2(x,a,b) vector<vector<char>> x = vector<vector<char>>(a,vector<char>(b,'.'))
#define sortAl(v) sort(v.begin(),v.end())
#define sortAlr(v) sort(v.begin(),v.end()); reverse(v.begin(),v.end())
#define cinv(v,n,m) FOR(i,n,m) cin>>v.at(i)
#define coutv(v,n,m) FOR(i,n,m) cout<<v.at(i) <<" "; cout<<endl
#define cout(n) cout<<fixed<<setprecision(n)
int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  VEC2(v,1001,1001);
  FOR(i,0,1001){
    if(i%5==3)v[i][0]='X';

    FOR(j,0,1001){
      if(i%5==0&&j%5==0)v[i][j]='X';
      if(i%5==2&&j%5==1)v[i][j]='X';
      if(i%5==4&&j%5==2)v[i][j]='X';
      if(i%5==1&&j%5==3)v[i][j]='X';
      if(i%5==3&&j%5==4)v[i][j]='X';
      if(i==0&&j%5==2)v[i][j]='X';

    }
  }

  ll N;
  //ll x=0;
  cin>>N;
  FOR(i,0,N-1){
    FOR(j,0,N-1){
      cout<<v[i][j];
      //if(v[i][j]=='X')x++;
    }
    //x++;
    if(v[i][N-1]=='X'||v[i][N]=='X')cout<<'X'<<endl;
    else cout<<'.'<<endl;
  }
  FOR(j,0,N){
    if(v[N-1][j]=='X'||v[N][j]=='X')cout<<'X';
    else cout<<'.';
    //x++;
  }
  //cout<<x<<endl;
}
