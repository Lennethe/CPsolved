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

int arrow[9] = {0,1,2,0,-1,2,0,1,2};

ll step(string s, ll f){
  // f = 1なら右足をだす
  ll left=0,right=0;
  if(f == 1){
    right = arrow[s[0] - '0' - 1];
    left = arrow[s[1] - '0' - 1];
  }
  else{
    right = arrow[s[1] - '0' - 1];
    left = arrow[s[0] - '0' - 1];
  }
  ll tmp = right;
  if(right<left){
    right = left;
    left = tmp;
    f = (f+1)%2;
  }
  ll res = 0;
  FOR(i,2,s.size()){
    ll foot = arrow[s[i] - '0' - 1];
  //  cout<<"("<<left <<","<< right<<")"<<f<<" "<<foot<<endl;
    if(f == 1){
      if(left <= foot){
        f = 0;
        right = foot;
      }
      else{
        left = foot;
        res++;
      }
    }
    else{
      if(foot <= right){
        f = 1;
        left = foot;
      }
      else{
        right = foot;
        res++;
      }
    }
  }
//  cout<<"answer is "<<res<<endl;
  return res;
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    string s;
    cin>>s;
    while(s != "#"){
      if(s.size()<=2){
        cout<<0<<endl;
      }
      else{
        cout<<min(step(s,0), step(s,1))<<endl;
      }
      cin>>s;
    }
}
