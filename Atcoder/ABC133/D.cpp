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
    ll n;
    cin>>n;
    vector<ll> dam(n);
    FOR(i,0,n)cin>>dam[i];
    ll all = 0;
    FOR(i,0,n) all += dam[i];
    ll a = all/=2;
    for(ll i=1; i<(ll)n; i+=2){
      a -= dam[i];
    }
    FOR(i,0,n){
      cout<<a*2;
      if(i != n-1)cout<<" ";
      else cout<<endl;
      a = dam[i] - a;
    }

}
