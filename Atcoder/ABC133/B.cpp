//#define _GLIBCXX_DEBUG
#include <iostream>
#include <bits/stdc++.h>


using namespace std;
#define ll long long
#define ld long double
#define  P pair<ll,ll>
#define FOR(i,n,m) for(ll i=n; i<(ll)m;i++)
#define FORr(i,m,n) for(ll i=n; i>=(ll)m; i--)
#define FORm(i,m) for(auto i=m.begin();i!=m.end();i++)
#define sortAl(v) sort(v.begin(),v.end())
#define sortAlr(v) sort(v.begin(),v.end()); reverse(v.begin(),v.end())
#define cout(n) cout<<fixed<<setprecision(n)

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll n,d;
    cin>>n>>d;
    vector<vector<ll>> v(n,vector<ll>(d));
    FOR(i,0,n)FOR(j,0,d)cin>>v[i][j];
    ll ans = 0;
    FOR(i,0,n){
      FOR(j,i+1,n){
        ld a=0;
        FOR(k,0,d){
          a += abs(v[i][k] - v[j][k])*abs(v[i][k] - v[j][k]);
//          cout<<v[i][k]<<" "<<v[j][k]<<" "<<a<<endl;
        }
        if(sqrt(a) == (ll)sqrt(a)) ans++;
//        cout<<sqrt(a)<<" "<<a<<endl;
      }
    }
    cout<<ans<<endl;
}
