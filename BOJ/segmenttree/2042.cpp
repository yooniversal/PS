//2042

#include <iostream>
#include <string>
#include <cstring>
#include <cstdio>
#include <vector>
#include <deque>
#include <cmath>
#include <ctime>
#include <algorithm>
using namespace std;

//입력받은 a 배열로부터 segment tree 생성
long long init(vector<long long> &a, vector<long long> &tree, int node, int start, int end) {
	//리프 노드에 도착했을 때
	if (start == end)
		return tree[node] = a[start];
	else {
		int mid = (start + end) / 2;
		//부모노드 인덱스가 node면, 왼쪽 자식 노드 인덱스는 node*2, 오른쪽 자식 노드 인덱스는 node*2+1
		//부모노드는 자식 노드의 합이므로 다음과 같이 나타낸다
		return tree[node] = init(a, tree, node * 2, start, mid) + init(a, tree, node * 2 + 1, mid + 1, end);
	}
}

void update(vector<long long>& tree, int node, int index, int start, int end, long long diff) {
	//범위 안에 들어오지 않으면 업데이트 할 필요가 없으므로 종료
	if (index < start || index > end) return;

	//범위 안에 들어오면 업데이트 해주어야 함
	tree[node] += diff;

	//이외 경우 케이스를 나눠 탐색
	if(start != end) {
		int mid = (start + end) / 2;
		update(tree, node * 2, index, start, mid, diff);
		update(tree, node * 2 + 1, index, mid + 1, end, diff);
	}
}

long long sum(vector<long long>& tree, int node, int start, int end, int left, int right) {
	//범위 안에 들어오지 않으면 반환 할 필요가 없다
	//따라서 0을 반환
	if (right < start || end < left) return 0;

	//[left, right]가 [start, end]를 포함할 경우, 더 이상 탐색할 필요가 없다
	//이미 부분합(tree[node])이 구해져 있기 때문에, 값을 반환한다
	if (left <= start && end <= right)	return tree[node];

	//겹치는 경우
	//[start, end]가 [left, right]를 포함할 경우
	int mid = (start + end) / 2;
	return sum(tree, node * 2, start, mid, left, right) + sum(tree, node * 2 + 1, mid + 1, end, left, right);
}

int main() {

	cin.tie(nullptr);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n, m, k, tmp, chance;

	cin >> n >> m >> k;
	vector<long long> arr(n);
	int h = (int)ceil(log2(n));	//트리 높이
	int tree_size = (1 << (h + 1));	//트리 사이즈(최대로 맞춰줘야 빈 칸에도 삽입 가능)
	vector<long long> tree(tree_size);

	for (int i = 0; i < n; i++)
		cin >> arr[i];

	init(arr, tree, 1, 0, n - 1);	//tree 생성하기

	chance = m + k;

	while (chance--) {
		int a;
		cin >> a;
		
		//b번째 값을 c로 바꾸기
		if (a == 1) {
			int b;
			long long c;
			cin >> b >> c;
			b--;	//인덱스이므로 1 감소
			long long diff = c - arr[b];
			arr[b] = c;
			update(tree, 1, b, 0, n - 1, diff);
		}
		//left : b  right : c , 구간합 출력
		else if (a == 2) {
			int b, c;
			cin >> b >> c;
			b--; c--;	//인덱스이므로 1 감소
			cout << sum(tree, 1, 0, n - 1, b, c) << "\n";
		}
	}

	return 0;
}