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
    ll n;
    cin>>n;
    vector<ll> v(n+1);
    vector<ll> x(n+1);
    FOR(i,1,n+1)cin>>v[i];
    vector<ll> ans;
    FORr(i,0,n){
      if(v[i] != x[i]){
        ans.push_back(i);
        vector<ll> d = Divisors(i);
        FOR(j,0,d.size()){
          x[d[j]] = (x[d[j]] + 1)%2;
        }
      }
    }
    cout<<ans.size()<<endl;
    FOR(i,0,ans.size()){
      cout<<ans[i];
      if(i != ans.size()-1)cout<<" ";
      else cout<<endl;
    }
}
