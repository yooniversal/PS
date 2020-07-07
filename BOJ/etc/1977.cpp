//1977

#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <deque>
#include <algorithm>
using namespace std;

int main() {

	cin.tie(nullptr);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n, m, first=0;
	long long sum = 0;
	vector<int> temp;

	for (int i = 1; i <= 100; i++)
		temp.push_back(i * i);

	cin >> n >> m;
	for(int i=n; i<=m; i++)
		for(int j=0; j<temp.size(); j++)
			if(i==temp[j])
				if (first == 0) {
					first = temp[j];
					sum = temp[j];
				}
				else {
					sum += temp[j];
				}

	if (first != 0)
		cout << sum << "\n" << first;
	else
		cout << "-1";

	return 0;
}