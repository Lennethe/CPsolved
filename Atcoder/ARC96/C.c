#include <stdio.h>
#include <bits/stdc++.h>

using namespace std;

int main(){
	
	int a,b,c,x,y;
	
	cin >> a >> b >> c >> x >> y;
	
	int res = 0;
	int inst = 0;
	
	res = a*x+b*y;
	
	if(x<y){
		inst = 2*c*x + b*(y-x);
	}
	else{
		inst = 2*c*y + a*(x-y);
	}
	if(inst < res) res = inst;
	
	if(x<y){
		inst = 2*c*y;
	}
	else{
		inst = 2*c*x;
	}
	if(inst < res) res = inst;
	
	
	cout << res << endl;
	
}
