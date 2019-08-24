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
int digitSum(int N){
  int a=0;
  while(N>0){
    a = a+ N%10;
    N = N/10;
  }
  return a;
}
int main(){
  int N;
  cin>>N;
  int a,b;
  a=1;
  b=N-a;

  int c;
  int res=N;
  N=N/2 + 1;
  FOR(i,0,N){
    c=digitSum(a)+digitSum(b);
    if(res>=c) res=c;
    a++;
    b--;
  }
  cout<<res<<endl;
}
