#include <stdio.h>
#include <bits/stdc++.h>

using namespace std;

int main(){
	
	int a,b,sum,sub,mlt, inst;
	
	cin >> a >> b ;
	
	sum = a+b;
	sub = a-b;
	mlt = a*b;
	
	inst = sum;
	
	if (inst <= sub) inst = sub;
	if (inst <= mlt) inst = mlt;
	
	cout << inst << endl;
	
	
	
	
	
}
