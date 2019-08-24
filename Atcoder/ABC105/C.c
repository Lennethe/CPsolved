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
  ll N;
  ll left=0;
  ll right=1;
  ll n=1;
  cin>>N;
  while(N<left ||  right<N){
    if(n%2==1){
      left+=pow(-2,n);
    //  cout<<"left="<<left<<endl;

    }
    else right+=pow(-2,n);
    n++;
  }

  n--;
  if(n%2==1) left-=pow(-2,n);
  else right-=pow(-2,n);

  //cout<<n<<" left="<<left<<" right="<<right<<" N="<<N<<endl;
  FORr(i,n,-1){
    if(N<left||right<N) {
      cout<<'1';
      if(i%2==0) left-=pow(-2,i-1);
      else right-=pow(-2,i-1);
      N-=pow(-2,i);
    }
    else {
      cout<<'0';
      if(i%2==0) left-=pow(-2,i-1);
      else right-=pow(-2,i-1);
    }
      //cout<<i<<" left="<<left<<" right="<<right<<" N="<<N<<endl;
  }
  cout<<endl;
}
