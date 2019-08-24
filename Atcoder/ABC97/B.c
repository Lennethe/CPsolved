#include <stdio.h>
#include <bits/stdc++.h>

using namespace std;

int main(){
	
	int x, b,p,result;
	
	b=2;
	p=2;
	result=1;
	cin >> x ;
	
	
	
	while(pow(b,2) <= x){
		
		while(pow(b,p) <= x){
			
			if(result <= pow(b,p)) {
				result = pow(b,p);
			}
			p++;
		}
		p=2;
		b++;
	}
	cout << result <<endl;
}
