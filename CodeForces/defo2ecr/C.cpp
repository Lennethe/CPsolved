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
  ll n;
  string s;
  ll x,y;
  cin>>n>>s>>x>>y;
  if(n<abs(x)+abs(y) || n%2 == (abs(x)+abs(y))%2){
    cout<<-1<<endl;
  }
  else{
    ll x_tmp=0,y_tmp=0;
    ll vector<ll> R,L,U,D;
    FOR(i,0,n){
      if(s[i]=='R'){
        x_tmp++;
        R.push_back(i);
      }
      if(s[i]=='L'){
        x_tmp--;
        L.push_back(i);
      }
      if(s[i]=='U'){
        y_tmp++;
        U.push_back(i);
      }
      if(s[i]=='D'){
        x_tmp--;
        D.push_back(i);
      }
    }

    if(x-x_tmp>0){
      if(y-y_tmp>0){

      }
      else if(y-y_tmp==0){

      }
      else{

      }
    }
    else if(x-x_tmp==0){
      if(y-y_tmp>0){
        FOR()
      }
      else if(y-y_tmp==0){
        cout<<0<<endl;
      }
      else{

      }
    }
    else{
      if(y-y_tmp>0){

      }
      else if(y-y_tmp==0){

      }
      else{

      }
    }
  }
}
