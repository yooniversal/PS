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

//�Է¹��� a �迭�κ��� segment tree ����
long long init_min(vector<long long>& a, vector<long long>& tree, int node, int start, int end) {
	//���� ��忡 �������� ��
	if (start == end)
		return tree[node] = a[start];
	else {
		int mid = (start + end) / 2;
		//�θ��� �ε����� node��, ���� �ڽ� ��� �ε����� node*2, ������ �ڽ� ��� �ε����� node*2+1
		//�θ���� �ڽ� ������ �ּڰ��� ���Ѵ�
		return tree[node] = min(init_min(a, tree, node * 2, start, mid), init_min(a, tree, node * 2 + 1, mid + 1, end));
	}
}

long long minsetting(vector<long long>& tree, int node, int start, int end, int left, int right) {
	//���Ե��� ������ ���X
	if (right < start || end < left) return INF;
	//���� ���ԵǴ� ��� �ش� ��尡 �ּڰ��� ��ȯ
	if (left <= start && end <= right) return tree[node];
	//�̿� ���̽�, �ڽ� ����� ���� ���� ��ȯ
	int mid = (start + end) / 2;
	return min(minsetting(tree, node * 2, start, mid, left, right), minsetting(tree, node * 2+1, mid+1, end, left, right));
}

//�Է¹��� a �迭�κ��� segment tree ����
long long init_max(vector<long long>& a, vector<long long>& tree, int node, int start, int end) {
	//���� ��忡 �������� ��
	if (start == end)
		return tree[node] = a[start];
	else {
		int mid = (start + end) / 2;
		//�θ��� �ε����� node��, ���� �ڽ� ��� �ε����� node*2, ������ �ڽ� ��� �ε����� node*2+1
		//�θ���� �ڽ� ������ �ִ��� ���Ѵ�
		return tree[node] = max(init_max(a, tree, node * 2, start, mid), init_max(a, tree, node * 2 + 1, mid + 1, end));
	}
}

long long maxsetting(vector<long long>& tree, int node, int start, int end, int left, int right) {
	//���Ե��� ������ ���X
	if (right < start || end < left) return 0;
	//���� ���ԵǴ� ��� �ش� ��尡 �ִ��� ��ȯ
	if (left <= start && end <= right) return tree[node];
	//�̿� ���̽�, �ڽ� ����� ū ���� ��ȯ
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
	int h = (int)ceil(log2(n));	//Ʈ�� ����
	int tree_size = (1 << (h + 1));	//Ʈ�� ������(�ִ�� ������� �� ĭ���� ���� ����)
	vector<long long> tree_min(tree_size);
	vector<long long> tree_max(tree_size);

	for (int i = 0; i < n; i++)
		cin >> arr[i];

	init_min(arr, tree_min, 1, 0, n - 1);	//tree_min �����ϱ�
	init_max(arr, tree_max, 1, 0, n - 1);	//tree_max �����ϱ�

	while (m--) {
		cin >> a >> b;
		cout << minsetting(tree_min, 1, 0, n - 1, a - 1, b - 1) << " " << maxsetting(tree_max, 1, 0, n-1, a-1, b-1) << "\n";
	}

	return 0;
}