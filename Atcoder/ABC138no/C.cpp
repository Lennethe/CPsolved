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
    ll n,m;
    cin>>n>>m;
    vector<vector<ll>> swc(n+1,vector<ll>(m+1,0));


    FOR(i,1,m+1){
      ll k;
      cin>>k;
      FOR(j,0,k){
        ll in;
        cin>>in;
        swc[in][i] = 1;
      }
    }

    vector<ll> p(m+1);
    FOR(i,1,m+1)cin>>p[i];

    ll ans = 0;
    FOR(i,0,1<<n){
      vector<ll> lmp(m+1);
      FOR(j,1,n+1){
        if(i & (1<<(j-1)) ){
          FOR(l,1,m+1){
            lmp[l] += swc[j][l];
          }
        }
      }

      ll flag = 1;
      FOR(j,1,m+1){
        if(lmp[j]%2 != p[j])flag=0;
      }
      ans += flag;
    }
    cout<<ans<<endl;

}
