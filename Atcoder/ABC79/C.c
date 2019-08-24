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
int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);

  ll N,a,b,c,d;
  cin>>N;
  a=N/1000;
  b=N/100%10;
  c=N/10%10;
  d=N%10;

  ll res=0;

  ll op1=1;
  ll op2=1;
  ll op3=1;
  string s1="+",s2="+",s3="+";
  FOR(i,0,2){
    FOR(j,0,2){
      FOR(k,0,2){
        if(op1==1){
          op1=-1;
          s1="-";
        }
        else {
          op1=1;
          s1="+";
        }
        res=a+b*op1+c*op2+d*op3;
        //s=""+a+""+s1+""+b+""+s2+""+c+""+s3+""+d;

        //cout<<a<<s1<<b<<s2<<c<<s3<<d<<endl;

      if(res==7)break;
      }

      if(res==7)break;
      if(op2==1){
        op2=-1;
        s2="-";
      }
      else {
        op2=1;
        s2="+";
      }
    }
    if(res==7)break;
    if(op3==1){
      op3=-1;
      s3="-";
    }
    else {
      op3=1;
      s3="+";
    }
  }
  cout<<a<<s1<<b<<s2<<c<<s3<<d<<"=7"<<endl;
}
