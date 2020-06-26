//2110

#include <iostream>
#include <string>
#include <cstring>
#include <cstdio>
#include <vector>
#include <deque>
#include <cmath>
#include <algorithm>
using namespace std;

typedef long long ll;
int K, M;
vector<ll> line;

void bi(ll low, ll high) {
	ll mid = (low + high) / 2, max=0;

	while (low <= high) {
		ll cnt = 1, wifi = line[0]; //cnt는 공유기의 개수, wifi는 최근 공유기의 위치
									 //첫 집에 공유기를 설치하고 시작해야 함.

		for (int i = 1; i < K; i++)
			if (line[i] - wifi >= mid) {
				cnt++;
				wifi = line[i];
			}

		//공유기 개수가 설치 개수를 넘으면 -> 기준을 넓힌다
		if (cnt >= M) {
			max = max < mid ? mid : max;
			low = mid + 1;
		}
		//공유기 개수가 설치 개수를 못넘으면 -> 기준을 줄인다
		else high = mid - 1;

		mid = (low + high) / 2;
	}

	cout << max;
}

int main() {

	cin.tie(nullptr);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	ll tmp, low = 0, max = 0;

	cin >> K >> M;

	for (int i = 0; i < K; i++) {
		cin >> tmp;
		line.push_back(tmp);
		max = max < tmp ? tmp : max;
	}

	sort(line.begin(), line.end());

	bi(low, max);

	return 0;
}