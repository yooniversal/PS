//1654

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
int K, N;
vector<ll> line;

void bi(ll low, ll high) {
	ll mid = (low + high) / 2;

	while (low <= high) {
		ll cnt = 0;

		for (int i = 0; i < K; i++)
			cnt += line[i] / mid;

		//개수가 더 많으면 -> 기준을 늘린다
		if (cnt >= N) low = mid + 1;
		//개수가 더 적으면 -> 기준을 줄인다
		else high = mid - 1;

		mid = (low + high) / 2;
	}

	cout << mid;
}

int main() {

	cin.tie(nullptr);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	ll max=0, tmp, low, high;
	
	cin >> K >> N;

	for (int i = 0; i < K; i++) {
		cin >> tmp;
		line.push_back(tmp);
		max = max < tmp ? tmp : max;
	}

	low = 1;
	high = max;
	bi(low, high);

	return 0;
}