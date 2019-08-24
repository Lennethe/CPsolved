#include <stdio.h>
#include <bits/stdc++.h>

using namespace std;
using ll=long long;
using ld=long double;
using P=pair<ll,ll>;
#define FOR(i,n,m) for(ll i=n; i<(ll)m;i++)
#define FORr(i,n,m) for(ll i=n; i>(ll)m; i--)
#define FORm(i,m) for(auto i=m.begin();i!=m.end();i++)
#define cinv(v,n,m) FOR(i,n,m) cin>>v.at(i)
#define coutv(v,n,m) FOR(i,n,m) cout<<v.at(i) <<" "
#define cout(n) cout<<fixed<<setprecision(n)
int main(){
  ll N,H;
  cin>>N>>H;
  vector<ll> v1(N),v2(N);
  FOR(i,0,N){
    cin>>v1[i]>>v2[i];
  }
  ll v1max=0;
  ll res=0,sum=0;

  FOR(i,0,N){
    if(v1[i]>v1max){v1max=v1[i];}
  }

  sort(v2.begin(),v2.end());
  reverse(v2.begin(),v2.end());

  FOR(i,0,N){
    if(v2[i]<v1max || sum>=H )break;
    else{
      sum+=v2[i];
      res++;
    }
  }

  if(sum<H){
    res+=(H-sum)/v1max;
    if((H-sum)%v1max!=0) res++;
    //res++;
    //cout<<v1max<<endl;
  }
  cout<<res<<endl;


}
