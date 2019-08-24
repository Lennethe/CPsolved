#include <stdio.h>
#include <bits/stdc++.h>

using namespace std;

int main(){
	int a,x, result,inst;
	string b;
	
	cin >> a >> b;
	result = 0;
	inst=0;
	x= 0;
	
	for(int i=0; i<a; i++){
		
		if (b.at(i) == 'W') x-- ;
		else x++;
		
		
		if(result <= x) {
			result = x;
			inst = i;
		}
	}
	
	result = 0;
	
	for(int i=inst-1; i>=0; i--){
		if(b.at(i) == 'W') result++;
	}
	for(int i=inst+1; i<a; i++){
		if(b.at(i) == 'E') result++;
	}
	
	cout << result << endl;
}
