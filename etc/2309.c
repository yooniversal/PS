//2309

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define _CRT_SECURE_NO_WARNINGS

int arr[20], chk[20] = { 0 }, ans[7];	//chk는 지나간 곳을 체크하기 위한 공간
int S = 100, cnt = 0;					//cnt는 뽑은 갯수를 의미
int temp = 0;							//매 케이스마다 temp에 저장하는 공간

void merge(int* arr, int start, int mid, int end) {
	int i = start, j = mid + 1, index = start;
	int* sorted = malloc(sizeof(int) * 1000001);
	int k;

	while (i <= mid && j <= end) {
		if (arr[i] <= arr[j]) {
			sorted[index] = arr[i];
			i++;
		}
		else {
			sorted[index] = arr[j];
			j++;
		}
		index++;
	}

	if (i > mid)
		for (k = j; k <= end; k++) {
			sorted[index] = arr[k];
			index++;
		}
	else
		for (k = i; k <= mid; k++) {
			sorted[index] = arr[k];
			index++;
		}

	//copy to arr
	for (k = start; k <= end; k++)
		arr[k] = sorted[k];

	free(sorted);
}

void mergesort(int* arr, int p, int q) {
	int n;

	if (p < q) {
		n = (p + q) / 2;

		mergesort(arr, p, n);
		mergesort(arr, n + 1, q);
		merge(arr, p, n, q);
	}
}

void dfs(int idx) {
	int i;

	temp += arr[idx];
	ans[cnt] = arr[idx];
	cnt++;

	//종료 조건
	if (temp == S && cnt == 7) {

		mergesort(ans, 0, 6);

		for (int i = 0; i < 7; i++)
			printf("%d\n", ans[i]);

		exit(0);
	}
	else {
		for (i = idx; i<8; i++)	//N-1까지가 아니라 N-2까지 돌아야 한다(dfs(i+1)이기 때문)
			if (!chk[i]) {		//지나가지 않았다면
				chk[i] = 1;		//지나갔음을 체크
				dfs(i + 1);		//자식 노드로 탐색(depth search)
				chk[i] = 0;		//이후 탐색에 영향을 주지 않도록 체크 해제
				temp -= arr[i + 1];	//dfs(i+1)에서 temp에 추가된 값을 제거(이후 탐색에 영향을 주지 않도록)
				cnt--;				//cnt는 7이상이면 안됨
			}
	}
}

int main() {

	for (int i = 0; i < 9; i++)
		scanf("%d", &arr[i]);

	for (int i = 0; i < 3; i++) {
		dfs(i);
		temp = 0; //전역변수 temp, cnt는 맨 첫번째 케이스가 반복될 때마다
		cnt = 0;  //초기화돼서 다음 케이스에 영향을 주지 않아야 한다
	}

	return 0;
}