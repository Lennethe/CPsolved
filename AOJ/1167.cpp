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

  vector<ll> v(1e6,10);
  vector<ll> seisi;
  ll a=0;
  seisi.push_back(a);
  a++;
  while(a<200){
    seisi.push_back(a+seisi[a-1]);
    a++;
  }
  FOR(i,1,seisi.size()){
    seisi[i]+=seisi[i-1];
  }
  //coutv(seisi,0,100);
  vector<ll> dp1(1e6,10);
  vector<ll> dp2(1e6,1e6);
  dp1[0]=0;
  dp2[0]=0;
  dp2[1]=1;
  FOR(i,1,seisi.size()){
    FOR(j,seisi[i],1e6){
      dp1[j]=min(dp1[j-seisi[i]]+1,dp1[j]);
      if(seisi[i]%2==1)dp2[j]=min(dp2[j],dp2[j-seisi[i]]+1);
    }
  }
  while(true){
    ll n;
    cin>>n;
    if(n==0)break;
    cout<<dp1[n]<<" "<<dp2[n]<<endl;
  }
}
