//11279

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

int heap[MAX_SIZE];
int heap_size=0;

void swap(int* a, int* b) {
	int tmp = *a; *a = *b; *b = tmp;
}

//�� �߰� �� ��ġ ������
void push(int input) {
	//cout << "heaszie:" << heap_size << endl;
	//������ ���ҿ� input �߰�
	heap[++heap_size] = input;
	int parent =  heap_size / 2;
	int child = heap_size;

	//�θ� �ڽĺ��� ������
	while (child != 1 && heap[parent] < heap[child]) {
		//�θ�� �ڽ� swap
		swap(&heap[parent], &heap[child]);
		child = parent;
		parent = child / 2;
	}
}

//�ִ� ��ȯ �� ��ġ ������
int pop() {
	//���� ù ��° ���Ұ� ���� ũ��
	int result = heap[1];

	if (heap_size > 0) {
		//�������� ù��°�� �ٲ�����
		swap(&heap[1], &heap[heap_size]);
		heap[heap_size] = 0;	//�迭�̶� ���� ������� �ʾ� ���Ƿ� ó������
		heap_size--;
	}

	int parent = 1;
	int child = parent * 2;
	//�ڽ� �� ū �༮�� ����
	if (child <= heap_size)
		child = heap[child + 1] > heap[child] ? child+1 : child;

	//�θ� �ڽĺ��� ���� ������
	while (child <= heap_size && heap[parent] < heap[child]) {
		//�θ�� �ڽ� swap
		swap(&heap[parent], &heap[child]);
		parent = child;
		child *= 2;

		//�ڽ� �� ū �༮�� ���� && ������ ���� child �ʱ�ȭ
		if (child <= heap_size)
			child = heap[child + 1] > heap[child] ? child + 1 : child;
	}

	//�ִ� ��ȯ
	return result;

}

int main() {

	cin.tie(nullptr);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int t, tmp;

	cin >> t;
	while (t--) {
		cin >> tmp;
		if (tmp != 0) {
			push(tmp);
			/*cout << "heap:";
			for (int i = 0; i < 10; i++)
				cout << heap[i] << " ";
			cout << "\n";*/
		}
		else {
			cout << pop() << '\n';
			/*cout << "*heap:";
			for (int i = 0; i < 10; i++)
				cout << heap[i] << " ";
			cout << "\n";*/
		}
	}

	return 0;
}