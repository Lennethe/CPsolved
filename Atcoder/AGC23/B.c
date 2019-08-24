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
int main(){
  int N;
  cin>>N;
  vector<string> vec(N);
  cinv(vec,0,N);
  int flag=0;
  int res=0;
  FOR(i,0,N){
    FOR(j,0,N){
      FOR(k,0,N){
        if(vec[(j+i)%N][k]!=vec[(k+i)%N][j]) flag=1;
      }
    }
    if(flag==0)res++;
    flag=0;
  }
  cout<<res*N<<endl;
}
