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

//素数かどうかを判定するO(sqrt(n))
bool is_prime(ll n){
	for(ll i=2; i*i<=n; i++){
		if(n%i==0) return false;
	}

	return true;
}


int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll a,b;
    cin>>a>>b;
    ll x = gcd(a,b);
    vector<ll> v = Divisors(x);
    ll ans = 0;
    FOR(i,0,v.size()){
      if(is_prime(v[i])) ans++;
    }
    cout<<ans<<endl;
}
