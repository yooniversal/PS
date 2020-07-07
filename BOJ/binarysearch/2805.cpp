//2805

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
	ll mid = (low + high) / 2;

	while (low <= high) {
		ll cnt = 0;

		for (int i = 0; i < K; i++)
			if(line[i] > mid)
				cnt += line[i] - mid;

		//cout << "low:" << low << " high:" << high << " cnt:" << cnt << '\n';

		//���ϴ� ���̺��� �� ������ -> ������ �ø���
		if (cnt >= M) low = mid + 1;
		//���ϴ� ���̺��� �� ������ -> ������ ���δ�
		else high = mid - 1;

		mid = (low + high) / 2;
	}

	cout << mid;
}

int main() {

	cin.tie(nullptr);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	ll tmp, low=1, max = 0;

	cin >> K >> M;

	for (int i = 0; i < K; i++) {
		cin >> tmp;
		line.push_back(tmp);
		max = max < tmp ? tmp : max;
	}

	bi(low, max);

	return 0;
}