//2357

#include <iostream>
#include <string>
#include <cstring>
#include <cstdio>
#include <vector>
#include <deque>
#include <cmath>
#include <ctime>
#include <algorithm>
#define INF 1000000001
using namespace std;

//입력받은 a 배열로부터 segment tree 생성
long long init_min(vector<long long>& a, vector<long long>& tree, int node, int start, int end) {
	//리프 노드에 도착했을 때
	if (start == end)
		return tree[node] = a[start];
	else {
		int mid = (start + end) / 2;
		//부모노드 인덱스가 node면, 왼쪽 자식 노드 인덱스는 node*2, 오른쪽 자식 노드 인덱스는 node*2+1
		//부모노드는 자식 노드들의 최솟값을 취한다
		return tree[node] = min(init_min(a, tree, node * 2, start, mid), init_min(a, tree, node * 2 + 1, mid + 1, end));
	}
}

long long minsetting(vector<long long>& tree, int node, int start, int end, int left, int right) {
	//포함되지 않으면 고려X
	if (right < start || end < left) return INF;
	//완전 포함되는 경우 해당 노드가 최솟값을 반환
	if (left <= start && end <= right) return tree[node];
	//이외 케이스, 자식 노드중 작은 값을 반환
	int mid = (start + end) / 2;
	return min(minsetting(tree, node * 2, start, mid, left, right), minsetting(tree, node * 2+1, mid+1, end, left, right));
}

//입력받은 a 배열로부터 segment tree 생성
long long init_max(vector<long long>& a, vector<long long>& tree, int node, int start, int end) {
	//리프 노드에 도착했을 때
	if (start == end)
		return tree[node] = a[start];
	else {
		int mid = (start + end) / 2;
		//부모노드 인덱스가 node면, 왼쪽 자식 노드 인덱스는 node*2, 오른쪽 자식 노드 인덱스는 node*2+1
		//부모노드는 자식 노드들의 최댓값을 취한다
		return tree[node] = max(init_max(a, tree, node * 2, start, mid), init_max(a, tree, node * 2 + 1, mid + 1, end));
	}
}

long long maxsetting(vector<long long>& tree, int node, int start, int end, int left, int right) {
	//포함되지 않으면 고려X
	if (right < start || end < left) return 0;
	//완전 포함되는 경우 해당 노드가 최댓값을 반환
	if (left <= start && end <= right) return tree[node];
	//이외 케이스, 자식 노드중 큰 값을 반환
	int mid = (start + end) / 2;
	return max(maxsetting(tree, node * 2, start, mid, left, right), maxsetting(tree, node * 2 + 1, mid + 1, end, left, right));
}

int main() {

	cin.tie(nullptr);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n, m, a, b;

	cin >> n >> m;
	vector<long long> arr(n);
	int h = (int)ceil(log2(n));	//트리 높이
	int tree_size = (1 << (h + 1));	//트리 사이즈(최대로 맞춰줘야 빈 칸에도 삽입 가능)
	vector<long long> tree_min(tree_size);
	vector<long long> tree_max(tree_size);

	for (int i = 0; i < n; i++)
		cin >> arr[i];

	init_min(arr, tree_min, 1, 0, n - 1);	//tree_min 생성하기
	init_max(arr, tree_max, 1, 0, n - 1);	//tree_max 생성하기

	while (m--) {
		cin >> a >> b;
		cout << minsetting(tree_min, 1, 0, n - 1, a - 1, b - 1) << " " << maxsetting(tree_max, 1, 0, n-1, a-1, b-1) << "\n";
	}

	return 0;
}