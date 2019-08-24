#include <stdio.h>
#include <bits/stdc++.h>

using namespace std;

int main(){
	
	double a,b,n;
	
	cin>>n;
	
	double y1,x1,y2,x2,res;
	
	a=3;
	b=7;
	res=0;
	
	
	for(int i=0; i<n; i++){
		
		x1=a+i*(b-a)/n;
		y1=3*x1*x1 + 2*x1 +5;
	
		x2=x1+(b-a)/n;
		y2=3*x2*x2 + 2*x2 +5;
		
		res=res + ((b-a)/n)*((y1+y2)/2); 
	}
	
	cout << res <<endl;
	
}
