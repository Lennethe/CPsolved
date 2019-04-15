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

vector<string> v(100);

int s_size(string s){
  ll res = 0;
  FOR(i,0,s.size()){
    if(s[i] == '.') res++;
  }
  return res;
}


P calf(ll pos, ll dpt, string c){
  ll cur_pos = pos + 1;
  ll cur_dpt = dpt + 1;
  ll res = 0;
  if(c == "*") res++;
  if(c == "+" || c == "*"){
    while (true) {

      //cout<<"cur_pos = "<<cur_pos<<endl;
      //cout<<res<<endl;
      if(v[cur_pos] == "") break;
      if(v[cur_pos].size()-1 != cur_dpt) break;
      if(v[cur_pos][cur_dpt] == '+'){
        P p = calf(cur_pos,cur_dpt,"+");
        if(c == "+") res += p.first;
        if(c == "*") res *= p.first;
        cur_pos = p.second-1;
      }
      else if(v[cur_pos][cur_dpt] == '*'){
        P p = calf(cur_pos,cur_dpt,"*");
        if(c == "+") res += p.first;
        if(c == "*") res *= p.first;
        cur_pos = p.second-1;
      }
      else if(c == "+"){
        res += v[cur_pos][cur_dpt] - '0';
        //cout<<"aa"<<endl;
      }
      else{
        res *= v[cur_pos][cur_dpt] - '0';
        //cout<<"bb"<<endl;
      }
      cur_pos++;
    }
    return P(res, cur_pos);

  }
  return P(stoi(c), 0);

}


int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll n = 0;
    cin>>n;
    while(n!=0){
      vector<string> ini(100);
      v = ini;

      cinv(v,0,n);
      cout<<calf(0,0,v[0]).first<<endl;
      cin>>n;
    }
}
