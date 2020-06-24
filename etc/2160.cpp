//2160

#include <iostream>
#include <string>
#include <cstring>
#include <cstdio>
#include <vector>
#include <deque>
#include <cmath>
#include <algorithm>
using namespace std;

int arr[51][5][7];
int minn, key1, key2;

int diff(int N, int a, int b) {
	int cnt = 0;

	for (int i = 0; i < 5; i++)
		for (int j = 0; j < 7; j++)
			if (arr[a][i][j] != arr[b][i][j])
				cnt++;

	return cnt;
}

void compare(int N) {

	minn = diff(N, 1, 2);
	key1 = 1; key2 = 2;
	for(int i=1; i<=N-1; i++)
		for (int j = i+1; j <= N; j++) {
			if (minn > diff(N, i, j)) {
				minn = diff(N, i, j);
				key1 = i;
				key2 = j;
			}
		}
}

int main() {

	cin.tie(nullptr);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int N;
	char tmp;
	cin >> N;

	for (int i = 1; i <= N; i++)
		for (int j = 0; j < 5; j++)
			for (int k = 0; k < 7; k++) {
				cin >> tmp;
				if (tmp == '.')
					arr[i][j][k] = 0;
				else
					arr[i][j][k] = 1;
			}

	compare(N);

	cout << key1 << " " << key2;

	return 0;
}