#include <stdio.h>
#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define ld long double
#define  P pair<ll,ll>
#define FOR(i,n,m) for(ll i=n; i<(ll)m;i++)
#define FORr(i,n,m) for(ll i=n; i>=(ll)m; i--)
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
    ll n,m;
    cin>>n>>m;
    vector<ll> v(n);
    cinv(v,0,n);
    sortAlr(v);
    ll sum=0;
    FOR(i,0,n){
      sum+=v[i];
    }
    ll po=v[0];
    ll cost=0;
    FOR(i,1,n){
      if(po==1){
        cost=n-i;
        break;
      }
      else if(po<=v[i]){
        po--;
      }
      else if(po>v[i]){
        po=v[i];
      }
    }
//    cout<<sum<<" "<<cost<<" "<<v[0]<<endl;

    cout<<sum-cost-v[0]<<endl;

}
