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
    ll n,k;
    cin>>n>>k;
    vector<ll> v(n);
    FOR(i,0,n) cin>>v[i];

    ll sum = 0;
    FOR(i,0,n) sum += v[i];

    vector<ll> div = Divisors(sum);

    vector<P> plus(n);
    vector<P> minus(n);
    ll ans = 0;
    FOR(i,0,div.size()){
      ll d = div[i];
      FOR(j,0,n){
        plus[j] = P(v[i]%d,j);
        minus[j] = P(d-v[i]%d,j);
      }
      sortAl(plus);
      sortAl(minus);
      vector<ll> used(n);

      ll tmp_p = 0;
      ll pos_p = 0;
      ll tmp_m = 0;
      ll pos_m = 0;
      cout<<"a"<<endl;
      cout<<"i = "<<i<<endl;
      while(pos_p<n && pos_m<n){
        cout<<" pos_p = "<<pos_p<<" , pos_m = "<<pos_m<<endl;
        if(tmp_p>=tmp_m){
          while(used[minus[pos_m].second] == 1)pos_m++;
          if(pos_m>=n)break;
          used[minus[pos_m].second] = 1;
          tmp_m += minus[pos_m].first;
        }
        else{
          while(used[plus[pos_p].second] == 1)pos_p++;
          if(pos_p>=n)break;
          used[plus[pos_p].second] = 1;
          tmp_p += plus[pos_p].first;
        }
      }
      ans = max(ans, tmp_p);
    }
    cout<<ans<<endl;
}
