#include <stdio.h>
#include <bits/stdc++.h>

using namespace std;
using ll=long long;
using ld=long double;
using P=pair<ll,ll>;
#define FOR(i,n,m) for(ll i=n; i<(ll)m;i++)
#define FORr(i,n,m) for(ll i=n; i>(ll)m; i--)
#define FORm(i,m) for(auto i=m.begin();i!=m.end();i++)
#define VEC2(x,a,b) vector<vector<ll>> x = vector<vector<ll>>(a,vector<ll>(b,0))
#define sortAl(v) sort(v.begin(),v.end())
#define sortAlr(v) sort(v.begin(),v.end()); reverse(v.begin(),v.end())
#define cinv(v,n,m) FOR(i,n,m) cin>>v.at(i)
#define coutv(v,n,m) FOR(i,n,m) cout<<v.at(i) <<" "; cout<<endl
#define cout(n) cout<<fixed<<setprecision(n)

bool is_prime(ll n){
	for(ll i=2; i*i<=n; i++){
		if(n%i==0) return false;
	}
	if(n==1)return false;
	return true;
}

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);

  ll n;
  cin>>n;

	ll und=0;
	und=max(und,n-1000);
	ll a=0,b=0,s=0;
	//cout<<is_prime(n)<<endl;
	FORr(i,n,und){
		if(is_prime(i)){
			if(n-i==0){
				s=i;
				break;
			}
			FOR(j,0,n-i){
				if(is_prime(j)&&is_prime(n-i-j)){

			//		cout<<2<<endl;
					a=j,b=n-i-j;
					s=i;
					break;
				}
			}
		}

		//cout<<3<<endl;
		if(b!=0)break;
	}
	ll res=1;
	if(a!=0)res++;
	if(b!=0)res++;
	cout<<res<<endl;
	cout<<s<<" ";
	if(a!=0)cout<<a<<" ";
	if(b!=0)cout<<b<<" ";
	cout<<endl;
}
