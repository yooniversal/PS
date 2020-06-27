//1927

#include <iostream>
#include <string>
#include <cstring>
#include <cstdio>
#include <vector>
#include <deque>
#include <cmath>
#include <algorithm>
using namespace std;
#define MAX_SIZE 100001

typedef long long ll;
ll heap[MAX_SIZE];
int heap_size = 0;

void swap(ll* a, ll* b) {
	ll tmp = *a;
	*a = *b;
	*b = tmp;
}

//�� �߰� �� ��ġ ������
void push(ll input) {

	if (heap_size == MAX_SIZE - 1) return;

	//������ ���ҿ� input �߰�
	heap[++heap_size] = input;
	int parent = heap_size / 2;
	int child = heap_size;

	//�θ� �ڽĺ��� ũ��
	while (child != 1 && heap[parent] > heap[child]) {
		//�θ�� �ڽ� swap
		swap(&heap[parent], &heap[child]);
		child = parent;
		parent = child / 2;
	}
}

//�ִ� ��ȯ �� ��ġ ������
ll pop() {

	if (heap_size == 0) return 0;

	//���� ù ��° ���Ұ� ���� ũ��
	ll result = heap[1];

	if (heap_size > 0) {
		//�������� ù��°�� �ٲ�����
		swap(&heap[1], &heap[heap_size]);
		heap[heap_size--] = 0;
	}

	int parent = 1;
	int child = parent * 2;
	if (heap_size > 2) {
		//�ڽ� �� ���� �༮�� ����
		if (child <= heap_size)
			child = heap[child + 1] > heap[child] ? child : child + 1;
	}

	//�θ� �ڽĺ��� ���� ũ��
	while (child <= heap_size && heap[parent] > heap[child]) {
		//�θ�� �ڽ� swap
		swap(&heap[parent], &heap[child]);
		parent = child;
		child *= 2;

		//�ڽ� �� ���� �༮�� ���� && ������ ���� child �ʱ�ȭ
		if (child <= heap_size)
			child = heap[child + 1] > heap[child] ? child : child+1;
	}

	//�ִ� ��ȯ
	return result;
}

int main() {

	cin.tie(nullptr);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int t;
	ll tmp;

	cin >> t;
	while (t--) {
		cin >> tmp;
		if (tmp != 0) {
			push(tmp);
			/*cout << "heap:";
			for (int i = 0; i < 10; i++)
				cout << heap[i] << " ";
			cout << "\nheap_size:" << heap_size << endl;*/
		}
		else {
			cout << pop() << '\n';
			/*cout << "*heap:";
			for (int i = 0; i < 10; i++)
				cout << heap[i] << " ";
			cout << "\nheap_size:" << heap_size << endl;*/
		}
	}

	return 0;
}