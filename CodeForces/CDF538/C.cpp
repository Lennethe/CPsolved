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
    ll n,k;
    cin>>n>>k;
    vector<ll> v = Divisors(k);
    vector<ll> k_prim;
    FOR(i,0,v.size()){
      if(is_prime(v[i]) && v[i] != 1 ){
        k_prim.push_back(v[i]);
      }
    }

//    coutv(k_prim,0,k_prim.size());
    map<ll,ll> recepi;
    ll tmp = k;
    FOR(i,0,k_prim.size()){
      ll prim = k_prim[i];
      ll div = prim;
      //cout<<prim<<endl;
      while(tmp%div == 0 && div>0){
        div *= prim;
        recepi[prim]++;
      }
    }

//    FORm(i,recepi){
//      cout<<i->first<<"is"<<i->second<<"th"<<endl;
//    }
    map<ll,ll> material;
    FOR(i,0,k_prim.size()){
      ll prim = k_prim[i];
      ll div = prim;
      ll tmp = n;
      while(tmp>=div){
        material[prim] += tmp/div;
        tmp /= div;
      }
    }
//    FORm(i,material){
//    cout<<i->first<<"is"<<i->second<<"th"<<endl;
//    }

    ll res = 1e18;
    FORm(i,recepi){
      ll j = i->first;
      ll rec = recepi[j];
      ll mat = material[j];
      res = min(res,mat/rec);
    }

    cout<<res<<endl;
}
