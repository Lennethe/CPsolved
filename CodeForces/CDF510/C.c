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
#define coutv(v,n,m) FOR(i,n,m) cout<<v.at(i) <<" "; cout<<end
#define cout(n) cout<<fixed<<setprecision(n)
int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  ll n;
  cin>>n;
  vector<ll> v(n);
  cinv(v,0,n);
  ll flag=0;
  ll point=-1;
  ll x=-2e9;
  //cout<<"asdf"<<endl;
  FOR(i,0,n){
    if(v[i]<0){
      flag++;
      if(x<v[i]){
        x=v[i];
        point=i;
      }
    }
    //cout<<"as"<<endl;
  }
  if(point!=-1&&flag%2==1){
    v[point]=0;
  }

  ll fp=-1;
  ll zp=-1;
  ll count=0;
  FOR(i,0,n){
    if(v[i]==0){
      if(zp==-1){
        zp=i;
      }
      else{
        cout<<1<<" "<<zp+1<<" "<<i+1<<endl;
        zp=i;
        count++;
      }
    }
    else{
      if(fp==-1){
        fp=i;
      }
      else{
        cout<<1<<" "<<fp+1<<" "<<i+1<<endl;
        fp=i;
        count++;
      }
    }

  }
  if(zp!=-1&&count==n-2){
    cout<<2<<" "<<zp+1<<endl;
  }
  /*
  FOR(i,0,n){
    if(v[i]==0){
      cout<<2<<" "<<i+1<<endl;
    }
    else{
      fp=i+1;
      break;
    }
  }
  ll a=fp-1;
  FOR(i,a+1,n){
    if(v[i]==0){
      cout<<2<<" "<<i+1<<endl;
    }
    else{
      cout<<1<<" "<<fp<<" "<<i+1<<endl;
      fp=i+1;
    }
  }
  */

}
