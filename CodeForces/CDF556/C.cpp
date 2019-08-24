//#define _GLIBCXX_DEBUG
#include <iostream>
#include <vector>
#include <stdio.h>
#include <bits/stdc++.h>


using namespace std;
#define ll long long
#define ld long double
#define  P pair<ll,ll>
#define FOR(i,n,m) for(ll i=n; i<(ll)m;i++)
#define FORa(i,c) for(__typeof((c).begin())i=(c).begin();i!=(c).end();++i)
#define FORr(i,m,n) for(ll i=n; i>=(ll)m; i--)
#define FORm(i,m) for(auto i=m.begin();i!=m.end();i++)
#define FORs(i,st) for(auto i : st)
#define REP(i,n) for(int i=0;i<(int)n;++i)
#define ALL(c) (c).begin(), (c).end()
#define VEC2(x,a,b) vector<vector<ll>> x = vector<vector<ll>>(a,vector<ll>(b,0))
#define sortAl(v) sort(v.begin(),v.end())
#define sortAlr(v) sort(v.begin(),v.end()); reverse(v.begin(),v.end())
#define cinv(v,n,m) FOR(i,n,m) cin>>v.at(i)
#define coutv(v,n,m) FOR(i,n,m) cout<<v.at(i) <<" "; cout<<endl
#define cout(n) cout<<fixed<<setprecision(n)

vector<ll> primVec(ll N){
	vector<ll> res, vec;
	vec= vector<ll>(N+1,1);
	for(ll i=2; i<N+1; i++){
		if(vec.at(i)==1){
			for(ll j = 0; i*(j+2)<N+1; j++){
				vec.at(i*(j+2))=0;
			}
		}
	}
	for(ll i=2; i<N+1; i++){
		if(vec.at(i)==1) res.push_back(i);
	}
	return res;
}


int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);

    vector<ll> prim = primVec(400000);
    ll one=0;
    ll two=0;
    ll n;
    cin>>n;
    FOR(i,0,n){
      ll in;
      cin>>in;
      if(in == 1)one++;
      if(in == 2)two++;
    }

    deque<ll> ans;

    ll i=0;
    ll tmp = 0;
    while(one != 0 || two != 0){
//      cout<<one<<" "<<two<<endl;
      if(prim[i] <= tmp) i++;
      // 常にprim > tmp が補償
      if(prim[i] - tmp > 1){
        if(two > 0){
          ans.push_back(2);
          two--;
          tmp += 2;
        }
        else if(one > 0){
          ans.push_back(1);
          one--;
          tmp += 1;
        }
      }
      else{
        if(one > 0){
          ans.push_back(1);
          one--;
          tmp += 1;
        }
        else if(two > 0){
          ans.push_back(2);
          two--;
          tmp += 2;
        }
      }
    }

    while(!ans.empty()){
      cout<<ans.front();
      ans.pop_front();
      if(!ans.empty())cout<<" ";
    }
    cout<<endl;
}
