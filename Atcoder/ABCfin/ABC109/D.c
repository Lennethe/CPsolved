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

  ll H,W;
  cin>>H>>W;
  VEC2(v,H,W);
  FOR(i,0,H) FOR(j,0,W) cin>>v[i][j];
  FOR(i,0,H) FOR(j,0,W) v[i][j]=v[i][j]%2;

  ll flag=0;
  ll prei=0,prej=0;
  ll res=0;


  FOR(i,0,H){

    if(i%2==0){
      FOR(j,0,W){
        if(flag==1){
          //cout<<prei+1<<" "<<prej+1<<" "<<i+1<<" "<<j+1<<endl;
          res++;
          if(v[i][j]==1)flag=0;
        }
        else{
          if(v[i][j]==1)flag=1;
        }
      prei=i;
      prej=j;
      }
    }
    else{
      FORr(j,W-1,-1){
        if(flag==1){
          //cout<<prei+1<<" "<<prej+1<<" "<<i+1<<" "<<j+1<<endl;
          res++;
          if(v[i][j]==1)flag=0;
        }
        else{
          if(v[i][j]==1)flag=1;
        }
      prei=i;
      prej=j;
      }
    }

  }
  prei=0;
  prej=0;
  flag=0;

  cout<<res<<endl;
  FOR(i,0,H){

    if(i%2==0){
      FOR(j,0,W){
        if(flag==1){
          cout<<prei+1<<" "<<prej+1<<" "<<i+1<<" "<<j+1<<endl;
          if(v[i][j]==1)flag=0;
        }
        else{
          if(v[i][j]==1)flag=1;
        }
      prei=i;
      prej=j;
      }
    }
    else{
      FORr(j,W-1,-1){
        if(flag==1){
          cout<<prei+1<<" "<<prej+1<<" "<<i+1<<" "<<j+1<<endl;
          if(v[i][j]==1)flag=0;
        }
        else{
          if(v[i][j]==1)flag=1;
        }
      prei=i;
      prej=j;
      }
    }
  }


}
