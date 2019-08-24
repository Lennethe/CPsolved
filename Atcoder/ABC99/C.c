#include <stdio.h>
#include <bits/stdc++.h>

using namespace std;
using ll=long long;
using ld=long double;
using P=pair<ll,ll>;
#define FOR(i,n,m) for(ll i=n; i<(ll)m;i++)
#define FORr(i,n,m) for(ll i=n; i>(ll)m; i--)
#define cinv(v,n,m) FOR(i,n,m) cin>>v.at(i)
#define coutv(v,n,m) FOR(i,n,m) cout<<v.at(i) <<" "
#define cout(n) cout<<fixed<<setprecision(n)
int main(){
	ll N;
	cin>>N;
	ll res=1e9;
	ll i6=0,i9=0;
	int a;
	FOR(i,0,N+1){
		a=i;
		i6=0;
		i9=0;
		while(a!=0){
			i6+=a%6;
			a = a/6;
		}

		a=N-i;
		while(a!=0){
			i9+=a%9;
			a = a/9;
		}
		if(i6+i9<res) res=i6+i9;
	}
	cout<<res<<endl;
}
