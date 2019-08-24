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


  ll n,m;
  cin>>n;
  vector<ll> a(n);
  cinv(a,0,n);
  cin>>m;
  vector<ll> b(m);
  cinv(b,0,m);
  ll i=0,j=0;
  ll p=a[0],q=b[0];
  ll res=0;
  while(i<n&&j<m){
    if(p==q){
      res++;
      i++;
      j++;
      if(i!=n)p=a[i];
      if(j!=m)q=b[j];
    }
    else if(p<q){
      i++;
      p+=a[i];
    }
    else{
      j++;
      q+=b[j];
    }
  //  cout<<i<<" "<<j<<" "<<p<<" "<<q<<endl;
  }
  //ll sum=0,sumb=0;
  if(!(i>=n&&j>=m)){
    res=-1;
  }
  cout<<res<<endl;

}
