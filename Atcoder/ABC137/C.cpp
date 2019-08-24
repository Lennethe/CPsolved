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
    vector<string> v(n);
    FOR(i,0,n){
      string s;
      cin>>s;
      sortAl(s);
      v[i] = s;
    }
    sortAl(v);

    vector<ll> com(n+1,0);
    FOR(i,2,n+1){
      com[i] += com[i-1] + i-1;
    }

    ll tmp = 0;
    ll ans = 0;
    string s = "";
    FOR(i,0,n){
      if(s != v[i]){
        s = v[i];
        ans += com[tmp];
        tmp = 1;
      }
      else tmp++;
    }
    ans += com[tmp];
    cout<<ans<<endl;
}
