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

//�Է¹��� a �迭�κ��� segment tree ����
long long init(vector<long long> &a, vector<long long> &tree, int node, int start, int end) {
	//���� ��忡 �������� ��
	if (start == end)
		return tree[node] = a[start];
	else {
		int mid = (start + end) / 2;
		//�θ��� �ε����� node��, ���� �ڽ� ��� �ε����� node*2, ������ �ڽ� ��� �ε����� node*2+1
		//�θ���� �ڽ� ����� ���̹Ƿ� ������ ���� ��Ÿ����
		return tree[node] = init(a, tree, node * 2, start, mid) + init(a, tree, node * 2 + 1, mid + 1, end);
	}
}

void update(vector<long long>& tree, int node, int index, int start, int end, long long diff) {
	//���� �ȿ� ������ ������ ������Ʈ �� �ʿ䰡 �����Ƿ� ����
	if (index < start || index > end) return;

	//���� �ȿ� ������ ������Ʈ ���־�� ��
	tree[node] += diff;

	//�̿� ��� ���̽��� ���� Ž��
	if(start != end) {
		int mid = (start + end) / 2;
		update(tree, node * 2, index, start, mid, diff);
		update(tree, node * 2 + 1, index, mid + 1, end, diff);
	}
}

long long sum(vector<long long>& tree, int node, int start, int end, int left, int right) {
	//���� �ȿ� ������ ������ ��ȯ �� �ʿ䰡 ����
	//���� 0�� ��ȯ
	if (right < start || end < left) return 0;

	//[left, right]�� [start, end]�� ������ ���, �� �̻� Ž���� �ʿ䰡 ����
	//�̹� �κ���(tree[node])�� ������ �ֱ� ������, ���� ��ȯ�Ѵ�
	if (left <= start && end <= right)	return tree[node];

	//��ġ�� ���
	//[start, end]�� [left, right]�� ������ ���
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
	int h = (int)ceil(log2(n));	//Ʈ�� ����
	int tree_size = (1 << (h + 1));	//Ʈ�� ������(�ִ�� ������� �� ĭ���� ���� ����)
	vector<long long> tree(tree_size);

	for (int i = 0; i < n; i++)
		cin >> arr[i];

	init(arr, tree, 1, 0, n - 1);	//tree �����ϱ�

	chance = m + k;

	while (chance--) {
		int a;
		cin >> a;
		
		//b��° ���� c�� �ٲٱ�
		if (a == 1) {
			int b;
			long long c;
			cin >> b >> c;
			b--;	//�ε����̹Ƿ� 1 ����
			long long diff = c - arr[b];
			arr[b] = c;
			update(tree, 1, b, 0, n - 1, diff);
		}
		//left : b  right : c , ������ ���
		else if (a == 2) {
			int b, c;
			cin >> b >> c;
			b--; c--;	//�ε����̹Ƿ� 1 ����
			cout << sum(tree, 1, 0, n - 1, b, c) << "\n";
		}
	}

	return 0;
}