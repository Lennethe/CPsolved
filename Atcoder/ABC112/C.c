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

  ll N;
  cin>>N;
  VEC2(v,N,3);
  FOR(i,0,N){
    cin>>v[i][0]>>v[i][1]>>v[i][2];
  }
  ll size=min((ll)5,N);
  ll resx=0,resy=0;
  FOR(i,0,101){
    FOR(j,0,101){
      ll x=abs(i-v[0][0])+abs(j-v[0][1]);
      FOR(k,0,size){
        ll x1=abs(i-v[k][0])+abs(j-v[k][1]);
        if(x!=x1)break;
        if(x==x1&&k==size-1){
          resx=i;
          resy=j;
        }
      }
    }
  }
  cout<<resx<<" "<<resy<<" "<<abs(resx-v[0][0])+abs(resy-v[0][1])+v[0][2]<<endl;


}
