//1182

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define _CRT_SECURE_NO_WARNINGS

int arr[20], chk[20] = { 0 };	//chk는 지나간 곳을 체크하기 위한 공간
int N, S, cnt = 0;
int temp = 0;	//매 케이스마다 temp에 저장하는 공간

void dfs(int idx) {
	int i;

	temp += arr[idx];		//temp에 값을 더한다
	if (temp == S) cnt++;	//정답이면 정답 카운트 증가
	
	//종료 조건
	if (idx == N - 1) return;	//마지막 순번일 때 종료
	else {
		for (i = idx; i < N-1; i++)	//N-1까지가 아니라 N-2까지 돌아야 한다(dfs(i+1)이기 때문)
			if (!chk[i]) {		//지나가지 않았다면
				chk[i] = 1;		//지나갔음을 체크
				dfs(i + 1);		//자식 노드로 탐색(depth search)
				chk[i] = 0;		//이후 탐색에 영향을 주지 않도록 체크 해제
				temp -= arr[i+1];	//dfs(i+1)에서 temp에 추가된 값을 제거(이후 탐색에 영향을 주지 않도록)
			}
	}
}

int main(){

	scanf("%d %d", &N, &S);

	for (int i = 0; i < N; i++)
		scanf("%d", &arr[i]);

	for (int i = 0; i < N; i++) {
		dfs(i);
		temp = 0; //전역변수 temp는 맨 첫번째 케이스가 반복될 때마다
				  //초기화해서 다음 케이스에 영향을 주지 않아야 한다
	}

	printf("%d", cnt);

	return 0;
}