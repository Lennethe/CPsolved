#include <stdio.h>
#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define ld long double
#define  P pair<ll,ll>
#define FOR(i,n,m) for(ll i=n; i<(ll)m;i++)
#define FORr(i,m,n) for(ll i=n; i>=(ll)m; i--)
#define FORm(i,m) for(auto i=m.begin();i!=m.end();i++)
#define VEC2(x,a,b) vector<vector<ll>> x = vector<vector<ll>>(a,vector<ll>(b,0))
#define sortAl(v) sort(v.begin(),v.end())
#define sortAlr(v) sort(v.begin(),v.end()); reverse(v.begin(),v.end())
#define cinv(v,n,m) FOR(i,n,m) cin>>v.at(i)
#define coutv(v,n,m) FOR(i,n,m) cout<<v.at(i) <<" "; cout<<endl
#define cout(n) cout<<fixed<<setprecision(n)

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll n,m;
    cin>>n>>m;

    map<ll,ll> candy;
    vector<ll> num_candy(n);
    FOR(i,0,m){
      ll in1,in2;
      cin>>in1>>in2;
      ll x = in2-in1;
      if(x<0) x += n;
      if(candy[in1-1] == 0) candy[in1-1] = 1e9;
      candy[in1-1] = min(candy[in1-1], x);
      num_candy[in1-1]++;
    }

    FOR(i,0,n){
      ll start = i;
      ll tmp_can = 0;
      ll tmp_res = 0;
      //cout<<"i="<<i<<endl;
      FOR(j,0,n){
        ll tmp_pos = (start+j) % n;
      //  cout<<tmp_pos<<endl;
        if(num_candy[tmp_pos]==tmp_can){
          tmp_res = max(tmp_res, j + candy[tmp_pos]);
        }
        if(num_candy[tmp_pos]>tmp_can){
          tmp_can = num_candy[tmp_pos];
          tmp_res = j + candy[tmp_pos];
        }

      }
      cout<<n * (tmp_can - 1) + tmp_res<<" ";
      //cout<< tmp_can << " "<<po << " "<< tmp_res<<endl;
    }
    cout<<endl;

}
