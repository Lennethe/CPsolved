#include <stdio.h>
#include <bits/stdc++.h>

using namespace std;

int main(){
	int a, b ,c, k;
	
	cin >> a >> b >> c >> k;
	
	
	if(a > b && a > c){
		a = a*pow(2,k);
		cout << a+b+c << endl;
		
	}
	else if(b >= a && b >= c){
		b = b*pow(2,k);
		cout << a+b+c << endl;
		
	}
	else{
		c = c*pow(2,k);
		cout << a+b+c << endl;
		
	}
	
	
}
