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

    ll n;
    cin>>n;
    ll nor=0,cham=0;
    vector<ll> v(n);
    cinv(v,0,n);
    vector<ll> f(8);
    FOR(j,0,n){
      FOR(i,0,8){
        if(400*i <= v[j] && v[j] < 400*(i+1)){
          f[i]++;
        }
      }
    }
    ll sum=0;
    FOR(i,0,8){
      sum+=f[i];
      if(f[i]>0){
        nor++;
      }
    }
    cham=n-sum;

    if(nor==0){
      nor++;
      cham--;
    }
    cout<<nor<<" "<<nor+cham<<endl;
}
