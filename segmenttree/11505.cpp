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

//�Է¹��� a �迭�κ��� segment tree ����
ll init(vector<ll>& a, vector<ll>& tree, int node, int start, int end) {
	//���� ���
	if (start == end)
		return tree[node] = a[start];
	else {
		int mid = (start + end) / 2;
		//�θ��� �ε����� node�� ���� �ڽ� ��� �ε����� node*2, ������ �ڽ� ��� �ε����� node*2+1 (segment tree)
		//�θ���� �ڽ� ����� ��
		return tree[node] = ((init(a, tree, node * 2, start, mid)%INF) * (init(a, tree, node * 2 + 1, mid + 1, end)%INF))%INF;
	}
}

ll update(vector<ll>& tree, int node, int index, int start, int end) {
	int mid = (start + end) / 2;

	//���� �ȿ� ������ ������ ������Ʈ �� �ʿ䰡 �����Ƿ� �״�� �д�
	if (!(start <= index && index <= end)) return tree[node];

	//���� ��� �ʱ�ȭ
	if (start == end) return tree[node] = value;

	//�̿� ���̽� ��庰 �ʱ�ȭ
	return tree[node] = (update(tree, node*2, index, start, mid)* update(tree, node * 2+1, index, mid+1, end))%INF;
}

ll multi(vector<ll>& tree, int node, int start, int end, int left, int right) {
	//������ �ȵ����� ���
	if (right < start || end < left) return 1;

	//[left, right]�� [start, end]�� ������ ���, �� �̻� Ž���� �ʿ䰡 ����
	if (left <= start && end <= right)	return tree[node];

	//[start, end]�� [left, right]�� ������ ��� + ��ġ�� ���
	int mid = (start + end) / 2;
	return (multi(tree, node * 2, start, mid, left, right) * multi(tree, node * 2 + 1, mid + 1, end, left, right))%INF;
}

int main() {

	cin.tie(nullptr);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n, m, k, chance;

	cin >> n >> m >> k;
	
	int h = (int)ceil(log2(n));	//Ʈ�� ����
	int tree_size = (1 << (h + 1));	//Ʈ�� ������

	vector<ll> arr(n);
	vector<ll> tree(tree_size);

	for (int i = 0; i < n; i++)
		cin >> arr[i];

	init(arr, tree, 1, 0, n - 1);	//tree ����

	chance = m + k;

	while (chance--) {
		int a;
		cin >> a;

		if (a == 1) {
			int b;
			cin >> b >> value;
			b--;	//�ε����̹Ƿ� 1 ����
			update(tree, 1, b, 0, n - 1);
		}
		else {
			int left, right;
			cin >> left >> right;
			left--; right--;	//�ε����̹Ƿ� 1 ����
			cout << multi(tree, 1, 0, n - 1, left, right)%INF << "\n";
		}
	}

	return 0;
}