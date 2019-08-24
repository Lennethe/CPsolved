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

ll gcd(ll a, ll b){
  ll x;
	while(a!=b){
    if(b==0)break;
    a=a%b;
    x=b;
    b=a;
    a=x;
  }
  return a;
}


int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll a,b,c,d;
    cin>>a>>b>>c>>d;
    a--;
    ll ans = 0;
    ll g = c*d/gcd(c,d);
    ans = (b - b/c - b/d + b/g) - (a - a/c - a/d + a/g);
    cout<<ans<<endl;

}
