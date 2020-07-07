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

//값 추가 및 위치 재정렬
void push(int input) {
	//cout << "heaszie:" << heap_size << endl;
	//마지막 원소에 input 추가
	heap[++heap_size] = input;
	int parent =  heap_size / 2;
	int child = heap_size;

	//부모가 자식보다 작으면
	while (child != 1 && heap[parent] < heap[child]) {
		//부모와 자식 swap
		swap(&heap[parent], &heap[child]);
		child = parent;
		parent = child / 2;
	}
}

//최댓값 반환 및 위치 재정렬
int pop() {
	//힙은 첫 번째 원소가 가장 크다
	int result = heap[1];

	if (heap_size > 0) {
		//마지막과 첫번째를 바꿔주자
		swap(&heap[1], &heap[heap_size]);
		heap[heap_size] = 0;	//배열이라서 값이 사라지지 않아 임의로 처리했음
		heap_size--;
	}

	int parent = 1;
	int child = parent * 2;
	//자식 중 큰 녀석을 선택
	if (child <= heap_size)
		child = heap[child + 1] > heap[child] ? child+1 : child;

	//부모가 자식보다 값이 작으면
	while (child <= heap_size && heap[parent] < heap[child]) {
		//부모와 자식 swap
		swap(&heap[parent], &heap[child]);
		parent = child;
		child *= 2;

		//자식 중 큰 녀석을 선택 && 다음에 쓰일 child 초기화
		if (child <= heap_size)
			child = heap[child + 1] > heap[child] ? child + 1 : child;
	}

	//최댓값 반환
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