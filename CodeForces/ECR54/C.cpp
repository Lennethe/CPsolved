#include <stdio.h>
#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define ld long double
#define  P pair<double,double>
#define FOR(i,n,m) for(ll i=n; i<(ll)m;i++)
#define FORr(i,n,m) for(ll i=n; i>=(ll)m; i--)
#define FORm(i,m) for(auto i=m.begin();i!=m.end();i++)
#define VEC2(x,a,b) vector<vector<ll>> x = vector<vector<ll>>(a,vector<ll>(b,0))
#define sortAl(v) sort(v.begin(),v.end())
#define sortAlr(v) sort(v.begin(),v.end()); reverse(v.begin(),v.end())
#define cinv(v,n,m) FOR(i,n,m) cin>>v.at(i)
#define coutv(v,n,m) FOR(i,n,m) cout<<v.at(i) <<" "; cout<<endl
#define cout(n) cout<<fixed<<setprecision(n)

P solve(ll d){
  ll D = d*d - 4*d;
  if(D < 0){
    return P(-1,-1);
  }
  return P((d+sqrt(D))/2, (d-sqrt(D))/2);
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll n;
    cin>>n;
    FOR(i,0,n){
      ll in;
      cin>>in;
      P p = solve(in);

      if(p.first==-1){
        cout<<"N"<<endl;
      }
      else{
        cout(9)<<"Y"<<" "<<p.first<<" "<<p.second<<endl;
      }
    }

}
