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
    ll l1, r1, t1, l2, r2, t2;
    cin>>l1>>r1>>t1>>l2>>r2>>t2;
    ll t = gcd(t1,t2);
    ll la = l1%t;
    ll ra = r1-(l1-la);
    ll lb = l2%t;
    ll rb = r2 - (l2-lb);

    //cout<<la<<" "<<ra<<endl;
    //cout<<lb<<" "<<rb<<endl;
    ll res1 = max((ll)-1, min(ra,rb) - max(la,lb));
    ll res2 = max((ll)-1, min(ra+t,rb) - max(la+t,lb));
    ll res3 = max((ll)-1, min(ra,rb+t) - max(la,lb+t));
    ll res = max( max(res1,res2) ,res3);
    cout<<res+1<<endl;
}
