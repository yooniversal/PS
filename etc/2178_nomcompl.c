//2178
//정해진 영역 밖(x==n or y==m)으로 벗어날 때 어떻게 해야할지 모르겠음
//아무리 제한을 걸어봐도 해결이 안됨
//길이 대부분 0으로 막혀있으면 답을 찾을 수 있으나
//여러 갈래로 나누어질 경우의 수가 있는 경우 최솟값을 갖는 루트는 찾지 못함
//이유는 이동하는 우선순위(if~else)가 있기 때문 -- 수정 바람

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define _CRT_SECURE_NO_WARNINGS

int sum = 1;

typedef struct history {
	int x;
	int y;
	struct history* next;
	struct history* prev;
} history;

void AddNode(history* location, int x, int y) {
	history* newNode = malloc(sizeof(history));
	newNode->prev = location;
	newNode->next = NULL;
	newNode->x = x;
	newNode->y = y;
	location->next = newNode;
}

void DeleteNode(history* location) {
	location->prev->next = NULL;
	free(location);
}

void searchway(int *a[], int n, int m) {

	history* head = malloc(sizeof(history));
	head->x = 0;
	head->y = 0;
	head->next = NULL;
	head->prev = NULL;
	history* location = head;
	history* temp = NULL;
	a[0][0] = 0;
	printf("location->x : %d  location->y : %d  sum : %d\n", location->x, location->y, sum);

	//최종 위치에 도착하면 완료
	while(!(location->x == n-1 && location->y == m-1)){
		//이동 가능
		if (a[location->x + 1][location->y] == 1 || a[location->x][location->y + 1] == 1 ||
			a[location->x - 1][location->y] == 1 || a[location->x][location->y - 1] == 1){

			if (a[location->x + 1][location->y] == 1) {
				sum++;
				AddNode(location, location->x + 1, location->y);
				a[location->x+1][location->y] = 0;
				location = location->next;
				printf("CASE1 ! ");
				printf("location->x : %d  location->y : %d  sum : %d\n", location->x, location->y, sum);
				//printf("*********\n");
			}
			else if (a[location->x][location->y + 1] == 1) {
				sum++;
				AddNode(location, location->x, location->y+1);
				a[location->x][location->y+1] = 0;
				location = location->next;
				printf("CASE2 ! ");
				printf("location->x : %d  location->y : %d  sum : %d\n", location->x, location->y, sum);
				printf("*********\n");
			}
			else if (a[location->x - 1][location->y] == 1) {
				sum++;
				AddNode(location, location->x-1, location->y);
				a[location->x-1][location->y] = 0;
				location = location->next;
				printf("CASE3 ! ");
				printf("location->x : %d  location->y : %d  sum : %d\n", location->x, location->y, sum);
				printf("*********\n");
			}
		}
		//이동 불가
		else {
			printf("DELETE CASE\n");
			location = location->prev;
			DeleteNode(location->next);
			sum--;
		}
	}


	while (head->next == NULL) {
		DeleteNode(location);
	}
	free(head);

	return;
}

int main() {
	int n, m, i, j;
	long long int temp;

	scanf("%d %d", &n, &m);

	int** a = malloc(sizeof(int*) * n);
	for (i = 0; i < n; i++)
		*(a + i) = malloc(sizeof(int) * m);

	for (i = 0; i < n; i++) {
		scanf("%lld", &temp);
		for (j = m - 1; j >= 0; j--) {
			a[i][j] = temp % 10;
			temp /= 10;
		}
	}

	printf("\na :\n");
	for (i = 0; i < n; i++) {
		for (j =0; j<m; j++) {
			printf("%d ", a[i][j]);
		}
		printf("\n");
	}

	searchway(a, n, m);

	printf("finally : %d", sum);

	for (i = 0; i < n; i++)
		free(a[i]);
	free(a);

	return 0;
}