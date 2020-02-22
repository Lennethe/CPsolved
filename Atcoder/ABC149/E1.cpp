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


const double pi = std::acos(-1.0);

using type = std::complex<long double>;

std::vector<type> fft(std::vector<type> v, bool inv = false) {
  ll const n = v.size();
  double theta = 2 * pi / n * (inv ? -1 : 1);
  for (ll m = n; m >= 2; m >>= 1) {
    ll mh = m >> 1;
    type theta_i(0, theta);
    for (ll i = 0; i < mh; i++) {
      type w = std::exp((type)i * theta_i);
      for (ll j = i; j < n; j += m) {
        type x = v[j] - v[j + mh];
        v[j] = v[j] + v[j + mh];
        v[j + mh] = w * x;
      }
    }
    theta *= 2;
  }
  ll i = 0;
  for (ll j = 1; j < n - 1; j++) {
    for (ll k = n >> 1; k > (i ^= k); k >>= 1)
      ;
    if (j < i) std::swap(v[i], v[j]);
  }
  if (inv) {
    for (auto &x : v) x /= n;
  }
  return v;
}

std::vector<long long> convolution(std::vector<type> x, std::vector<type> y) {
  ll sz = 1;
  ll t = x.size() + y.size() - 1;
  while (sz < t) {
    sz <<= 1;
  }
  x.resize(sz);
  y.resize(sz);
  x = fft(std::move(x));
  y = fft(std::move(y));
  for (ll i = 0; i < sz; i++) {
    x[i] *= y[i];
  }
  x = fft(std::move(x), true);
  vector<long long> res(sz);
  for(ll i=0; i<sz; i++) res[i] = (long long)(x[i].real() + 0.5);
  return res;
}



int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll n,k;
    cin>>n>>k;
    vector<type> a(1e5+1),b(1e5+1);
    FOR(i,0,n){
        ll in;
        cin>>in;
        a[in]+=1; b[in]+=1;
    }
    vector<ll> v = convolution(a,b);
    ll cnt=0;
    ll res = 0;
    FORr(i,0,v.size()){
        if(cnt >= k)break;
        res += min(v[i],k-cnt)*i;
        cnt += min(v[i],k-cnt);
    }
    cout<<res<<endl;
}