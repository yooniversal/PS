#include <bits/stdc++.h>

using namespace std;

long long gcd(long long a, long long b){
	long long tmp;
	if(b == 0) return 1;
	if(a<b){
		tmp = a;
		a = b;
		b = tmp;
	}
	while(b != 0){
		tmp = a%b;
		a = b;
		b = tmp;
	}
	return a;
}

int main(){
	int t;
	cin >> t;
	
	while(t--){
		long long n;
		cin >> n;
		long long a=1, b=n-1;
		
		if(n%2==0){
			cout << n/2 << " " << n/2 << '\n';
			continue;
		}
		for(int i=2; i*i<=n; i++){
			if(n%i == 0){
				a = n/i; b = n-a;
				break;
			}
		}
		
		cout << a << " " << b << '\n';
	}
	
	return 0;
}
