#include <stdio.h>
#include <bits/stdc++.h>

using namespace std;

int main(){
	int a,b,res;
	res = 0;
	cin >> a >> b;
	
	if(a <= b) res = a;
	else res = a-1;
	
	cout << res <<endl;
}
