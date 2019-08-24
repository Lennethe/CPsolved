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
#define cinv(v,n,m) FOR(i,n,m) cin>>v.at(i)
#define coutv(v,n,m) FOR(i,n,m) cout<<v.at(i) <<" "
#define cout(n) cout<<fixed<<setprecision(n)
int main(){
  ll N;
  cin>>N;
  N--;
  VEC2(v,N,3);
  FOR(i,0,N){
    cin>>v[i][0]>>v[i][1]>>v[i][2];
  }

  ll res=0;
  FOR(i,0,N){
    res=0;
    FOR(j,i,N){
      if(res<=v[j][1]) res=v[j][1];
      else if(res%v[j][2]==0) ;
      else res=(v[j][2]-res%v[j][2]) + res;
      res+=v[j][0];
    }
    cout<<res<<endl;
  }
  cout<<0<<endl;
}
