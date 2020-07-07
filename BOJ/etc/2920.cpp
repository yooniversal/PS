//2920

#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;

int main() {

	cin.tie(nullptr);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int arr[8];
	int temp, mode;

	for (int i = 0; i < 8; i++) {
		cin >> arr[i];
	}

	for (int i = 0; i < 7; i++) {
		if (i == 0) {
			if (arr[0] > arr[1]) mode = 1;
			else if (arr[0] < arr[1]) mode = 2;
			else {
				cout << "mixed";
				
				return 0;
			}
		}
		else if (i == 6) {
			if (mode == 1)
				if (arr[i] > arr[i + 1]) cout << "descending" << "\n";
				else {
					cout << "mixed";
					
					return 0;
				}
			else if (mode == 2)
				if (arr[i] < arr[i + 1]) cout << "ascending" << "\n";
				else {
					cout << "mixed";
					return 0;
				}
		}
		else
			if (mode == 1)
				if (arr[i] > arr[i + 1]) continue;
				else {
					cout << "mixed";
					return 0;
				}
			else if (mode == 2)
				if (arr[i] < arr[i + 1]) continue;
				else {
					cout << "mixed";
					return 0;
				}

	}
	return 0;
}