#include <bits/stdc++.h>
 
using namespace std;
 
int main(){
	int t;
	cin >> t;
	
	while(t--){
		int n;
		cin >> n;
		vector<int> arr(n);
		arr[0] = 1;
		if(n>1) arr[1] = 2;
		if(n==1){
			cout<< arr[0] << '\n';
			continue;	
		}
		for(int i=1; i<n; i++){
			arr[i] = arr[i-1]+2;
			if(arr[i-1] + arr[i-2] == arr[i] ) arr[i]++;
			if(arr[i]>1000) arr[i] = 1;
		}
		for(int i=0; i<n; i++) cout << arr[i] << " ";
		cout << '\n';
	}
	
	return 0;
}
