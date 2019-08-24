#include <stdio.h>
#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define ld long double
#define  P pair<ll,ll>
#define FOR(i,n,m) for(ll i=n; i<(ll)m;i++)
#define FORr(i,n,m) for(ll i=n; i>=(ll)m; i--)
#define FORm(i,m) for(auto i=m.begin();i!=m.end();i++)
#define VEC2(x,a,b) vector<vector<string>> x = vector<vector<string>>(a,vector<string>(b,"."))
#define sortAl(v) sort(v.begin(),v.end())
#define sortAlr(v) sort(v.begin(),v.end()); reverse(v.begin(),v.end())
#define cinv(v,n,m) FOR(i,n,m) cin>>v.at(i)
#define coutv(v,n,m) FOR(i,n,m) cout<<v.at(i) <<" "; cout<<endl
#define cout(n) cout<<fixed<<setprecision(n)

string strcon(string a, string b){
  if(a.size() > b.size()){
    return a;
  }
  else if(a.size() < b.size()){
    return b;
  }
  else{
    vector<string> v;
    v.push_back(a);
    v.push_back(b);
    sortAl(v);
    return v[1];
  }
}

string insert_s (string s, char in){
  ll pos=0;
  FOR(i,0,s.size()){

    char x = s[i];
    if(in - x > 0){
      break;
    }
    pos = i+1;
  }
  string res;
  FOR(i,0,pos){
    res.push_back(s[i]);
  }
  res.push_back(in);
  FOR(i,pos,s.size()){
    res.push_back(s[i]);
  }
  return res;
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);

    map<ll,ll> number;
    number[1] = 2;
    number[2] = 5;
    number[3] = 5;
    number[4] = 4;
    number[5] = 5;
    number[6] = 6;
    number[7] = 3;
    number[8] = 7;
    number[9] = 6;

    ll n,m;
    cin>>n>>m;
    VEC2(dp,n+1,m+1);
    vector<char> v(m);
    cinv(v,0,m);
    FOR(i,0,m+1){
      dp[0][i] = "";
    }

    FOR(i,1,n+1){
      FOR(j,1,m+1){
        char num = v[j-1];
        ll mat = number[num - '0'];
        string tmp_ans1 = dp[i][j-1];
        string tmp_ans2 = ".";
//        cout<<"i = "<<i<<endl;
        if(i - mat >= 0){
          tmp_ans2 = dp[i - mat][m];
//          cout<<"ans2 = "<<tmp_ans2<<" in = "<<num<<endl;
          if(tmp_ans2 != ".")tmp_ans2 = insert_s(tmp_ans2, num);
//          cout<<"in ans2 = "<<tmp_ans2<<endl;
        }
        string res = ".";
        if(tmp_ans2 == "." && tmp_ans1 == "." );
        else if(tmp_ans1 == "."){
          res = tmp_ans2;
        }
        else if(tmp_ans2 == "."){
          res = tmp_ans1;
        }
        else{
          res = strcon(tmp_ans1, tmp_ans2);
        }

        dp[i][j] = res;
      }
    }
    cout<<dp[n][m]<<endl;


}
