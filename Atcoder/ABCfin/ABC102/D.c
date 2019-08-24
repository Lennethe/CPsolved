#include <stdio.h>
#include <bits/stdc++.h>

using namespace std;
using ll=long long;
using ld=long double;
using P=pair<ll,ll>;
#define FOR(i,n,m) for(ll i=n; i<(ll)m;i++)
#define cinv(v,n,m) FOR(i,n,m) cin>>v.at(i)
#define coutv(v,n,m) FOR(i,n,m) cout<<v.at(i) <<" "
#define cout(n) cout<<fixed<<setprecision(n)
int main(){
	ll N;
	cin>>N;
	vector<ll> v(N);
	int in;
	cin>>v[0];
	FOR(i,1,N){
		cin>>in;
		v[i] = v[i-1] + in;
	}


	ll la,lb,ra,rb,res=1e9;
	ll L=0,R=2;
	vector<ll> key(4);
	FOR(i,2,N-1){
		while(abs(v[i-1]-v[L]-v[L])>abs(v[i-1]-v[L+1]-v[L+1])){
			L++;
		}
		while(abs(v[N-1]-v[R]-v[R]+v[i-1])>abs(v[N-1]-v[R+1]-v[R+1]+v[i-1])){
			R++;
		}
		rb=v[N-1]-v[R];
		ra=v[R]-v[i-1];
		lb=v[i-1]-v[L];
		la=v[L];

		key[0]=la;
		key[1]=lb;
		key[2]=ra;
		key[3]=rb;
		sort(key.begin(),key.end());
		if(key[3]-key[0]<res) res=key[3]-key[0];
		//cout<<"L="<<L<<" i="<<i<<" R="<<R<<endl;

		//cout<<la<<" "<<lb<<" "<<ra<<" "<<rb<<endl;

	}
	cout<<res<<endl;
}
