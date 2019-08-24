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

vector<ll> incr(ll a, ll b, ll c, vector<ll> v){
  FOR(i,a-1,b-1){
    v[i]+=c;
  }
  return v;
}

ll ease(ll a, ll b, ll k, vector<ll> v){
  ll l=a-1;
  ll r=b-1;
  ll po=r;

  while(l<po-k-1 && v[po-k-1]%2==1){
    po-=k-1;
  }
  return po;
}

ll solve(ll a, ll b, ll k, vector<ll> v){
  ll l = a-1;
  ll r = b-1;
  v[l]--;

  if(r-k-1<l) return 1;
  else{
    ll sum=0;
    FOR(i,l,r){
      sum+=v[i];
    }
    if(sum%2==0) return 2;
    else return 1;
  }

}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);

    ll n, m, q;
    cin>>n>>m>>q;
    vector<ll> v(n);
    cinv(v,0,n);
    FOR(i,0,q){
      ll in;
      cin>>in;
      if(in==1){
        ll a,b,c;
        cin>>a>>b>>c;
        v = incr(a,b,c,v);
      }
      else{
        ll in1,in2;
        cin>>in1>>in2;
        in2 = ease(in1,in2,m,v);
        ll res = solve(in1,in2,m,v);
        cout<<res<<endl;
      }
    }
}
