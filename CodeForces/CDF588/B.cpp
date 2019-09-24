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
    ll n,k;
    cin>>n>>k;
    string s;
    cin>>s;
    ll x = 0;
    FOR(i,0,n){
      if(x==k) break;
      if(i == 0){
        if(s[i] != '1'){
          s[i] = '1';
          x++;
        }
      }
      else{
        if(s[i] != '0'){
          s[i] = '0';
          x++;
        }
      }
    }
    if(n == 1 && k>=1) cout<<0<<endl;
    else cout<<s<<endl;
}
