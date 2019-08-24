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
  ll a,b;
  cin>>a>>b;
  b=b/1000;
  b=b-a;

  ll yuki=0,hide=0;

  ll res=-1,resd=-1,resf=-1;

  while(yuki+hide<=a){
    while(yuki+hide<=a){
      if(b==yuki*9+hide*4){
        res=yuki;
        resd=hide;
        resf=a-res-resd;
      }
      //cout<<yuki<<" "<<hide<<endl;
      hide++;
    }
    hide=0;
    yuki++;
  }
  cout<<res<<" "<<resd<<" "<<resf<<" "<<endl;

}
