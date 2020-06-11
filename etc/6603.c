//6603

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define _CRT_SECURE_NO_WARNINGS

int arr[20], chk[20], ans[6];	//chk는 지나간 곳을 체크하기 위한 공간
int N, S, cnt = 0;
int temp = 0;	//매 케이스마다 temp에 저장하는 공간

void dfs(int idx) {
	int i;

	ans[cnt] = arr[idx];		//temp에 값을 더한다
	cnt++;

	//종료 조건
	if (cnt == 6) {
		for (int j = 0; j < 6; j++)
			printf("%d ", ans[j]);
		printf("\n");
		return;
	}
	else {
		for (i = idx; i < N - 1; i++)	//N-1까지가 아니라 N-2까지 돌아야 한다(dfs(i+1)이기 때문)
			if (!chk[i]) {		//지나가지 않았다면
				chk[i] = 1;		//지나갔음을 체크
				dfs(i + 1);		//자식 노드로 탐색(depth search)
				chk[i] = 0;		//이후 탐색에 영향을 주지 않도록 체크 해제
				cnt--;
			}
	}
}

int main() {

	while (1) {
		scanf("%d", &N);
		if (N == 0) return 0;

		for (int i = 0; i < N; i++)
			scanf("%d", &arr[i]);

		for (int i = 0; i < N-5; i++) {
			dfs(i);
			temp = 0;	//전역변수 temp는 맨 첫번째 케이스가 반복될 때마다
			cnt = 0;	//초기화해서 다음 케이스에 영향을 주지 않아야 한다
		}
		printf("\n");
	}

	return 0;
}