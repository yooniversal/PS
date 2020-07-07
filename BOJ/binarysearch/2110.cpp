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
		ll cnt = 1, wifi = line[0]; //cnt�� �������� ����, wifi�� �ֱ� �������� ��ġ
									 //ù ���� �����⸦ ��ġ�ϰ� �����ؾ� ��.

		for (int i = 1; i < K; i++)
			if (line[i] - wifi >= mid) {
				cnt++;
				wifi = line[i];
			}

		//������ ������ ��ġ ������ ������ -> ������ ������
		if (cnt >= M) {
			max = max < mid ? mid : max;
			low = mid + 1;
		}
		//������ ������ ��ġ ������ �������� -> ������ ���δ�
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