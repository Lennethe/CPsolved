#include <stdio.h>
#include <bits/stdc++.h>

using namespace std;

int main(){
	
	int sum;
	
	int a,b;
	cin >> a >> b ;
	
	sum =0;
	
	for (int i=1; i < b-a;i++ ){
		sum = sum + i;
		
	}
	cout << sum - a;
	
	
	
	
}
