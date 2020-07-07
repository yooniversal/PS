//14003

#include <iostream>
#include <string>
#include <cstring>
#include <cstdio>
#include <vector>
#include <deque>
#include <stack>
#include <queue>
#include <cmath>
#include <algorithm>
#include <functional>
using namespace std;
#define INF -1000000001LL

typedef long long ll;
ll arr[1000001];
stack<pair<int, ll>> ans;	//first : index  second : value
stack<ll> result;

//lower_bound function : O(logn)
int searchindex(ll key, int start, int end) {
	int mid = (start + end) / 2;

	if (arr[mid + 1] == NULL) return mid;

	while (start < end) {
		mid = (start + end) / 2;
		if (arr[mid - 1] < key && key <= arr[mid]) return mid;
		else if (key <= arr[mid]) end = mid;
		else start = mid + 1;
	}
	return end;
}

int main() {

	cin.tie(nullptr);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	ll tempvalue;
	int cnt = 0, n, idx;

	cin >> n;
	arr[0] = INF;	//if(arr[cnt] < tempvalue) ������ �ּڰ����� ����������

	//O(nlogn)
	for (int i = 1; i <= n; i++) {
		cin >> tempvalue;
		//��� ����� ���� stack�� �Է�
		//���� ū ���� ������ ���� �ø���(LIS)
		if (arr[cnt] < tempvalue) {
			arr[++cnt] = tempvalue;
			ans.push(make_pair(cnt, tempvalue));
		}
		else {
			idx = searchindex(tempvalue, 1, cnt);
			arr[idx] = tempvalue;
			ans.push(make_pair(idx, tempvalue));
		}
	}

	cout << cnt << '\n';
	//���ÿ� ������ �´� ���� �߰��ϸ� ���� �������� ����
	//POINT
	while (cnt != 0) {
		if (ans.top().first == cnt) {
			//cout << cnt << " " << ans.top().second << '\n';
			result.push(ans.top().second);
			cnt--;
		}
		ans.pop();
	}
	
	//���� ������ �������� ���� �ٽ� ��� ���
	while (!result.empty()) {
		cout << result.top() << " ";
		result.pop();
	}

	return 0;
}