//11505

#include <iostream>
#include <string>
#include <cstring>
#include <cstdio>
#include <vector>
#include <deque>
#include <cmath>
#include <algorithm>
#define INF 1000000007
using namespace std;
typedef long long ll;

ll value;

//입력받은 a 배열로부터 segment tree 생성
ll init(vector<ll>& a, vector<ll>& tree, int node, int start, int end) {
	//리프 노드
	if (start == end)
		return tree[node] = a[start];
	else {
		int mid = (start + end) / 2;
		//부모노드 인덱스가 node면 왼쪽 자식 노드 인덱스는 node*2, 오른쪽 자식 노드 인덱스는 node*2+1 (segment tree)
		//부모노드는 자식 노드의 곱
		return tree[node] = ((init(a, tree, node * 2, start, mid)%INF) * (init(a, tree, node * 2 + 1, mid + 1, end)%INF))%INF;
	}
}

ll update(vector<ll>& tree, int node, int index, int start, int end) {
	int mid = (start + end) / 2;

	//범위 안에 들어오지 않으면 업데이트 할 필요가 없으므로 그대로 둔다
	if (!(start <= index && index <= end)) return tree[node];

	//리프 노드 초기화
	if (start == end) return tree[node] = value;

	//이외 케이스 노드별 초기화
	return tree[node] = (update(tree, node*2, index, start, mid)* update(tree, node * 2+1, index, mid+1, end))%INF;
}

ll multi(vector<ll>& tree, int node, int start, int end, int left, int right) {
	//범위에 안들어오는 경우
	if (right < start || end < left) return 1;

	//[left, right]가 [start, end]를 포함할 경우, 더 이상 탐색할 필요가 없다
	if (left <= start && end <= right)	return tree[node];

	//[start, end]가 [left, right]를 포함할 경우 + 겹치는 경우
	int mid = (start + end) / 2;
	return (multi(tree, node * 2, start, mid, left, right) * multi(tree, node * 2 + 1, mid + 1, end, left, right))%INF;
}

int main() {

	cin.tie(nullptr);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n, m, k, chance;

	cin >> n >> m >> k;
	
	int h = (int)ceil(log2(n));	//트리 높이
	int tree_size = (1 << (h + 1));	//트리 사이즈

	vector<ll> arr(n);
	vector<ll> tree(tree_size);

	for (int i = 0; i < n; i++)
		cin >> arr[i];

	init(arr, tree, 1, 0, n - 1);	//tree 생성

	chance = m + k;

	while (chance--) {
		int a;
		cin >> a;

		if (a == 1) {
			int b;
			cin >> b >> value;
			b--;	//인덱스이므로 1 감소
			update(tree, 1, b, 0, n - 1);
		}
		else {
			int left, right;
			cin >> left >> right;
			left--; right--;	//인덱스이므로 1 감소
			cout << multi(tree, 1, 0, n - 1, left, right)%INF << "\n";
		}
	}

	return 0;
}