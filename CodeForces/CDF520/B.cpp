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

bool is_prime(ll n){
	for(ll i=2; i*i<=n; i++){
		if(n%i==0) return false;
	}

	return true;
}


int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);

    ll n;
    ll a;
    cin>>n;
    a=n;
    vector<ll> v = Divisors(n);
    vector<ll> vp;
    FOR(i,1,v.size()){
      if(is_prime(v[i]))vp.push_back(v[i]);
    }
    map<ll,ll> mp;
    ll res=0;
    ll inst=0;
    FOR(i,1,v.size()){
      inst=0;
      while(n%v[i]==0){
        n/=v[i];
        inst++;
      }
      res=max(res,inst);
    }
    if(res%2!=0)res++;

    ll ans=0;
    while(res/2!=0){
      ans++;
      res/=2;
    }
    ll sum=1;
    FOR(i,0,vp.size()){
      sum*=vp[i];
    }
    if(sum==a)ans--;
    if(a==1)cout<<1<<" "<<1<<endl;
    else if(is_prime(a))cout<<a<<" "<<1<<endl;
    else cout<<sum<<" "<<ans+2<<endl;
}
