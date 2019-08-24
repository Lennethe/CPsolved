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
  ll N;
  cin>>N;
  vector<vector<ll>> v;
  ll inst=0;
  vector<ll> key;
  vector<ll> x;
  ll in;
  FOR(i,0,N){
    cin>>inst;

    x={};
    FOR(j,0,inst){
      cin>>in;
      x.push_back(in);
    }
    //coutv(x,0,x.size());
    //cout<<"xsize="<<x.size()<<endl;
    //cinv(x,0,inst);
    sort(x.begin(),x.end());
    key={};
    FOR(j,1,inst){
      if(x[j-1]==x[j]){
        key.push_back(x[j]);
        j++;
      }
    }
    v.push_back(key);
  }



  ll a,b;
  ld min=0;
//  coutv(v[0],0,v[0].size());



  FOR(i,0,N){
    min=1e9;
    FORr(j,v[i].size()-1,0){
      if(min*v[i][j]*v[i][j-1]>=(ld)v[i][j-1]*v[i][j-1]+v[i][j]*v[i][j]){
        b=v[i][j];
        a=v[i][j-1];
        min=(ld)a/b+b/a;
      //  cout<<min<<endl;
      }
      //cout<<"asdasd"<<endl;
    }
    cout<<a<<" "<<a<<" "<<b<<" "<<b<<endl;
  }
//cout<<"AAAA"<<endl;

}
