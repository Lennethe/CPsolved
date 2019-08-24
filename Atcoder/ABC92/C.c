#include <stdio.h>
#include <bits/stdc++.h>

using namespace std;
using ll=long long;
using ld=long double;
using P=pair<ll,ll>;
#define FOR(i,n,m) for(ll i=n; i<(ll)m;i++)
#define FORr(i,n,m) for(ll i=n; i>(ll)m; i--)
#define cinv(v,n,m) FOR(i,n,m) cin>>v.at(i)
#define coutv(v,n,m) FOR(i,n,m) cout<<v.at(i) <<" "
#define cout(n) cout<<fixed<<setprecision(n)
int main(){
  int N;
  cin>>N;
  vector<ll> v(N+2,0);
  cinv(v,1,N+1);
  ll sum=0;
  FOR(i,1,N+2){
    sum += abs(v[i]-v[i-1]);
  }
  int a,b;
  FOR(i,1,N+1){
    if((v[i-1]<=v[i]&&v[i]<=v[i+1])||(v[i-1]>=v[i]&&v[i]>=v[i+1])) cout<<sum<<endl;
    else {
      a=abs(v[i-1]-v[i]);
      b=abs(v[i+1]-v[i]);
      if(a<b) cout<<sum-2*a<<endl;
      else cout<<sum-2*b<<endl;
    }
  }
}
