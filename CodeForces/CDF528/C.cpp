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

void plotx(ll be_x,ll be_y, ll fin_x, ll fin_y){

}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll xa,ya,xb,yb,xc,yc;
    cin>>xa>>ya>>xb>>yb>>xc>>yc;

    ll res=0;
    res += abs(xa-xb)+abs(ya-yb);
    ll max_x, min_x, max_y, min_y;
    max_x = max(xa,xb);
    min_x = min(xa,xb);
    max_y = max(ya,yb);
    min_y = min(ya,yb);

    //範囲内なら1
    ll flagx=1,flagy=1;
    if(min_x<=xc && xc<=max_x){
    }
    else{
      res+=min(abs(xc-xa),abs(xc-xb));
      flagx=0;
    }
    if(yc<min_y || max_y < yc){
      res+=min(abs(yc-ya), abs(yc-yb));
      flagy=0;
    }
    cout<<res+1<<endl;

    ll dirx = (xc-xa)/abs(xc-xa);
    ll diry = (yc-ya)/abs(yc-ya);
    ll po_x=xa;
    ll po_y=ya;
    ll cent_x=xc;
    ll cent_y=yc;
    if(max_x<cent_x) cent_x=max_x;
    if(min_x>cent_x) cent_x=min_x;
    if(max_y<cent_y) cent_y=max_y;
    if(max_y>cent_y) cent_y=min_y;

      while(po_x!=cent_x){
        cout<<po_x<<" "<<po_y<<endl;
        po_x += dirx;
      }
      while(po_y!=cent_y){
        cout<<po_x<<" "<<po_y<<endl;
        po_y += diry;
      }
      while(po_x!=xb){
        cout<<po_x<<" "<<po_y<<endl;
        po_x += dirx;
      }
      while(po_y!=yb){
        cout<<po_x<<" "<<po_y<<endl;
        po_y += diry;
      }
      cout<<po_x<<" "<<po_y<<endl;


    if(flagx*flagy==0){
      po_x=cent_x;
      po_y=cent_y;

      if(cent_x!=xc){
        dirx= (xc-cent_x)/abs(xc-cent_x);
        while(po_x!=xc){
          po_x += dirx;
          cout<<po_x<<" "<<po_y<<endl;
        }
      }
      if(cent_y!=yc){
        diry= (yc-cent_y)/abs(yc-cent_y);
        while(po_y!=yc){
          po_y += diry;
          cout<<po_x<<" "<<po_y<<endl;
        }
      }

    }
}
