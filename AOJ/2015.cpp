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
#define coutv(v,n,m) FOR(i,n,m) cout<<v.at(i) <<" "; cout<<endl
#define cout(n) cout<<fixed<<setprecision(n)
int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);

  ll N,M;
  cin>>N>>M;

  while(N!=0&&M!=0){
    vector<ll> w(N+1);
    vector<ll> h(M+1);
    cinv(w,1,N+1);
    cinv(h,1,M+1);
    FOR(i,1,N+1){
      w[i]+=w[i-1];
    }
    FOR(i,1,M+1){
      h[i]+=h[i-1];
    }
    map<ll,ll> mpw;
    map<ll,ll> mph;

    FOR(i,0,N+1){
      FOR(j,i+1,N+1){
        mpw[w[j]-w[i]]++;
        //cout<<w[j]-w[i]<<endl;
      }
    }
    FOR(i,0,M+1){
      FOR(j,i+1,M+1){
        mph[h[j]-h[i]]++;
      }
    }
    ll res=0;
    FORm(i,mpw){
        res+=mph[i->first]*(i->second);
        //cout<<res<<endl;
    }
    cout<<res<<endl;






    cin>>N>>M;
  }

}
