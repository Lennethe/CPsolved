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

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);

    ll n,m;
    cin>>n>>m;
    vector<P> student(n+1);
    map<ll,map<ll,ll>> club_pots;
    vector<ll> club_pot(n+1);
    FOR(i,1,n+1){
      ll in;
      cin>>in;
      student[i].first = in; //yaruki
    }
    FOR(i,1,n+1){
      ll in;
      cin>>in;
      student[i].second = in; //club
    }

    ll d;
    cin>>d;

    deque<ll> in_student;
    vector<ll> flag_in_student(n+1);
    flag_in_student[0] = 1;
    FOR(i,0,d){
      ll in_student_id;
      cin>>in_student_id;
      flag_in_student[in_student_id] = 1;
      in_student.push_back(in_student_id);
    }
    FOR(i,1,n+1){
      if(flag_in_student[i]==0) in_student.push_back(i);
    }

    deque<ll> ans;

    FOR(i,0,n){
      ll in_student_id = in_student.back();
      in_student.pop_back();

    }

}
