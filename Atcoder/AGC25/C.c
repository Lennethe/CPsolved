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
  ll N;
  cin>>N;
  vector<vector<int>> vec = vector<vector<int>> (N,vector<int>(2,0));

  int a,b;
  FOR(i,0,N){
    cin>>a>>b;
    if(a*b>0){
      vec[i][0]=a;
      vec[i][1]=b;
    }
  }
  sort(vec.begin(),vec.end());

  int left=0,right=0;

  FOR(i,0,N){
    if(left<vec[i][0])left=vec[i][0];
    if(right>vec[i][1])right=vec[i][1];
  }

  /*FOR(i,0,N){
    cout<<vec[i][0]<<" "<<vec[i][1]<<endl;
  }*/
  ll res=0;
  if(right<0)res = res + (2*right)*(-1);
  if(left>0) res = res + (2*left);
  cout<<res<<endl;

}
