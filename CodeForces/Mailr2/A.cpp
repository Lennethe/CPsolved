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

    ll n,s;
    cin>>n>>s;
    vector<ll> a(n);
    vector<ll> b(n);
    cinv(a,0,n);
    cinv(b,0,n);
    string res = "NO";
    if(a[0]==0){
      res = "NO";
    }
    else {
      if(a[s-1] == 1){
        res="YES";
      }
      else{
        if(b[s-1] == 1){
          FOR(i,s-1,n){
            if(a[i]*b[i]==1){
              res="YES";
              break;
            }
          }
        }
      }
    }
    cout<<res<<endl;
}
