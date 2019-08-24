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
#define coutv(v,n,m) FOR(i,n,m) cout<<v.at(i) <<" "
#define cout(n) cout<<fixed<<setprecision(n)


vector<int> primVec(int N){
	vector<int> res, vec;
	vec= vector<int>(N+1,1);
	for(int i=2; i<N+1; i++){
		if(vec.at(i)==1){
			for(int j = 0; i*(j+2)<N+1; j++){
				vec.at(i*(j+2))=0;
			}
		}
	}
	res=vec;
	return res;
}

int main(){
  int N=1e5+3;
  vector<int> v(N);
  v = primVec(N);
  vector<int> key(N,0);
  FOR(i,3,N-1){
    if(v[i]==1&&v[(i+1)/2]==1)key[i]=1;
  }
  FOR(i,3,N){
    key[i]+=key[i-1];
  }


  ll Q;
  cin>>Q;
  ll a,b;
  FOR(i,0,Q){
    cin>>a>>b;
    cout<<key[b]-key[a-1]<<endl;
  }
}
