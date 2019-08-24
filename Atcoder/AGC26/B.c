#include <stdio.h>
#include <bits/stdc++.h>

using namespace std;
using ll=long long;
using ld=long double;
using P=pair<ll,ll>;
#define FOR(i,n,m) for(ll i=n; i<(ll)m;i++)
#define cinv(v,n,m) FOR(i,n,m) cin>>v.at(i)
#define coutv(v,n,m) FOR(i,n,m) cout<<v.at(i) <<" "
#define cout(n) cout<<fixed<<setprecision(n)

ll gcd(ll a, ll b){
  ll x;
	while(a!=b){
    if(b==0)break;
    a=a%b;
    x=b;
    b=a;
    a=x;
  }
  return a;
}


int main(){
  int T;
  cin>>T;
  vector<vector<ll>> vec= vector<vector<ll>> (T,vector<ll>(4,0));

  ll A,B,C,D;
  ll a;
  ll g;
  FOR(i,0,T){
    cin>>A>>B>>C>>D;
    if(A<B || D<B){
      cout<<"No"<<endl;
    }
    else if(B<=C){
      cout<<"Yes"<<endl;
    }
    else{
      g = gcd(B,D);
      a=B-g+(A%g);
      if(a<=C) cout <<"Yes"<<endl;
      else cout <<"No"<<endl;

      }
    }
  }
