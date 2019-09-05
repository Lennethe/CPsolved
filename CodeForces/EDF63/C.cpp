//#define _GLIBCXX_DEBUG
#include <iostream>
#include <vector>
#include <stdio.h>
#include <bits/stdc++.h>


using namespace std;
#define ll long long
#define ld long double
#define  P pair<ll,ll>
#define FOR(i,n,m) for(ll i=n; i<(ll)m;i++)
#define FORa(i,c) for(__typeof((c).begin())i=(c).begin();i!=(c).end();++i)
#define FORr(i,m,n) for(ll i=n; i>=(ll)m; i--)
#define FORm(i,m) for(auto i=m.begin();i!=m.end();i++)
#define FORs(i,st) for(auto i : st)
#define REP(i,n) for(int i=0;i<(int)n;++i)
#define ALL(c) (c).begin(), (c).end()
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

//計算量はsqrt(N)
template<typename T>
vector<T> Divisors(T n)
{
    vector<T> result;

    T boundary = sqrt(n);

    for (T i = 1; i <= boundary; i++) {
        if (n % i == 0) {
            result.push_back(i);
            if(i != (n / i) && i * i != n)
                result.push_back(n/i);
        }
    }
    sort(result.begin(),result.end());
    return result;
}


int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);

    ll n,m;
    cin>>n>>m;

    vector<ll> t(n);
    FOR(i,0,n){
      cin>>t[i];
    }

    map<ll,ll> p;
    FOR(i,0,m){
      ll in;
      cin>>in;
      p[in] = i+1;
    }

    ll x = t[0];
    FORr(i,1,n-1){
      t[i] -= t[i-1];
    }
    t[0] = 0;


    map<ll,ll> mp;

    ll gc = t[1];
    FOR(i,1,n){
      gc = gcd(gc, t[i]);
    }


    FOR(i,0,ans.size()){
      if(p[ans[i]] != 0){
        cout<<"YES"<<endl;
        cout<<x<<" "<<p[ans[i]]<<endl;
        break;
      }
      if(i == ans.size() - 1){
        cout<<"NO"<<endl;
      }
    }

    if(ans.size() == 0) cout<<"NO"<<endl;

}
