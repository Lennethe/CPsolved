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

ld sqrtf(ld a, ld b){
  a = fabs(a);
  b = fabs(b);
  if(a<b)swap(a,b);
  if(b==0)return a;
  const int ITERE = 3;
  ld s;
  FOR(i,0,ITERE){
    s=(b/a)*(b/a);
    s/=4+s;
    a+=2*a*s;
    b*=s;
  }
  return a;
}


int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    ld a,b,c;
    cin>>a>>b>>c;
    ld x1,y1,x2,y2;
    cin>>x1>>y1>>x2>>y2;
    if(a==0||b==0){
      cout(10)<<abs(x1-x2)+abs(y1-y2)<<endl;
    }
    else{
      ld p_x1 = -(ld)(b/a*y1 + c/a);
      ld p_x2 = -(ld)(b/a*y2 + c/a);
      ld p_y1 = -(ld)(a/b*x1 + c/b);
      ld p_y2 = -(ld)(a/b*x2 + c/b);
      /*
      cout<<"p_x1= "<<p_x1<<endl;
      cout<<"p_y1= "<<p_y1<<endl;
      cout<<"p_x2= "<<p_x2<<endl;
      cout<<"p_y2= "<<p_y2<<endl;
      */
      ll f_x1 =0;
      ll f_x2 =0;
      ll f_y1 =0;
      ll f_y2 =0;

      if((x2-p_x1)*(x1-p_x1)<0)f_x1=1;
      if((x2-p_x2)*(x1-p_x2)<0)f_x2=1;
      if((y2-p_y1)*(y1-p_y1)<0)f_y1=1;
      if((y2-p_y2)*(y1-p_y2)<0)f_y2=1;
      if(x1==p_x1)f_x1=1;
      if(x2==p_x2)f_x2=1;
      if(y2==p_y1)f_y1=1;
      if(y1==p_y2)f_y2=1;

      ld r_x1=0,r_y1=0,r_x2=0,r_y2=0;
      /*
      cout<<"f_x1= "<<f_x1<<endl;
      cout<<"f_y1= "<<f_y1<<endl;
      cout<<"f_x2= "<<f_x2<<endl;
      cout<<"f_y2= "<<f_y2<<endl;
      */

      if(f_x1+f_x2+f_y1+f_y2!=2){
        cout(10)<<(ll)abs(x1-x2)+(ll)abs(y1-y2)<<endl;
        //cout<<"ere"<<endl;
      }
      else{
        ld ans=abs(x1-x2)+abs(y1-y2);

        if(f_x1==1){
          r_x1=r_x2;
          r_y1=r_y2;
          r_x2=p_x1;
          r_y2=y1;
        }
        if(f_x2==1){
          r_x1=r_x2;
          r_y1=r_y2;
          r_x2=p_x2;
          r_y2=y2;
        }
        if(f_y1==1){
          r_x1=r_x2;
          r_y1=r_y2;
          r_x2=x1;
          r_y2=p_y1;
        }
        if(f_y2==1){
          r_x1=r_x2;
          r_y1=r_y2;
          r_x2=x2;
          r_y2=p_y2;
        }
        /*
        cout<<"r_x1= "<<r_x1<<endl;
        cout<<"r_y1= "<<r_y1<<endl;
        cout<<"r_x2= "<<r_x2<<endl;
        cout<<"r_y2= "<<r_y2<<endl;
        */
        ld absx=abs(r_x1-r_x2);
        //cout<<absx<<endl;
        ld absy=abs(r_y1-r_y2);
        //cout<<absy<<endl;
        ld calc = sqrtf(absx,absy);
        calc = absx*sqrt(1+(absy/absx)*(absy/absx));
        calc = sqrt(absy*absy+absx*absx);
        ld res1 =abs(x1-r_x1)+abs(x2-r_x2)+abs(y1-r_y1)+abs(y2-r_y2);
        ld res2 =abs(x1-r_x2)+abs(x2-r_x1)+abs(y1-r_y2)+abs(y2-r_y1);
        ld res=(ld)min(res1,res2)+calc;
        ans = min(ans,res);
        //cout<<"q"<<endl;
        //cout<<calc<<endl;
        //cout<<"ew"<<endl;
        //cout<<min(ans,res)<<endl;
        //cout<<"WW"<<endl;
        cout(10)<<ans<<endl;

      }


    }
}
