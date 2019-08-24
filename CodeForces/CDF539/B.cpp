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
    vector<ll> v(n);
    cinv(v,0,n);
    map<ll,ll> mp;
    FOR(i,0,n){
      mp[v[i]] = 1;
    }

    ll cost=0;
    FORm(i,mp){
      FORm(j,mp){
        ll a = i -> first;
        ll b = j -> first;
        ll now_cost = a + b;
        ll tmp_cost = 0;
        vector<ll> div = Divisors(a);
        FOR(k,0,div.size()){
          ll x = div[k];
          ll y = a/x;
//          cout<<x<<" "<<y<<endl;
          tmp_cost = max(tmp_cost, now_cost - (x+y*b));
        }
        cost = max(tmp_cost, cost);
//        cout<<"i = "<<a<<" j = "<<b <<" cost =" << cost<<endl;
      }
    }

    ll sum = 0;
    FOR(i,0,n){
      sum += v[i];
    }
    cout<<sum-cost<<endl;
}
