#include <stdio.h>
#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define ld long double
#define  P pair<ll,ll>
#define FOR(i,n,m) for(ll i=n; i<(ll)m;i++)
#define FORr(i,m,n) for(ll i=n; i>=(ll)m; i--)
#define FORm(i,m) for(auto i=m.begin();i!=m.end();i++)
#define VEC2(x,a,b) vector<vector<ll>> x = vector<vector<ll>>(a,vector<ll>(b,0))
#define sortAl(v) sort(v.begin(),v.end())
#define sortAlr(v) sort(v.begin(),v.end()); reverse(v.begin(),v.end())
#define cinv(v,n,m) FOR(i,n,m) cin>>v.at(i)
#define coutv(v,n,m) FOR(i,n,m) cout<<v.at(i) <<" "; cout<<endl
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
    ll a,b,c;
    cin>>a>>b>>c;
    vector<ll> ad = Divisors(a);
    vector<ll> bd = Divisors(b);
    map<ll,ll> mp;
    FOR(i,0,ad.size()){
      mp[ad[i]] += 1;
    }
    FOR(i,0,bd.size()){
      mp[bd[i]] += 1;
    }
    vector<ll> ans;
    FORm(i,mp){
      if(i->second == 2){
        ans.push_back(i->first);
      }
    }
    ll s = ans.size();
    cout<<ans[s-c]<<endl;


}
