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
    vector<ld> doble(30,1);
    FOR(i,1,30){
      doble[i] = 2*doble[i-1];
    }
    ll n,k;
    cin>>n>>k;
    ll po = 20;
    ld ans = 0;
    FOR(i,1,n+1){
      while(i*doble[po]>=k){
        po--;
      }
      ans = ans + (ld)(1/doble[po+1]);
    }
    ans = ans/(ld)n;
    cout(10)<<ans<<endl;
}
