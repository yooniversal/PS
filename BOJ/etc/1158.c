//1158
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define _CRT_SECURE_NO_WARNINGS

//Node Á¤ÀÇ
typedef struct Node {
	int data;
	struct Node* next;
} Node;

Node* searchTail(Node* head) {
	Node* tail = head;
	while (tail->next != NULL) {
		tail = tail->next;
	}
	return tail;
}

void AddNode(Node* head, Node* target, int data) {
	Node* newNode = malloc(sizeof(Node));
	
	if (target == head) {
		head->next = newNode;
		newNode->next = newNode;
	}
	else if (target->next == target) {
		newNode->next = target;
		target->next = newNode;
	}
	else {
		newNode->next = target->next;
		target->next = newNode;
	}

	newNode->data = data;
}
void DeleteNode(Node* head, Node* target) {
	
	Node* point = head;
	Node* tail;

	if (target == head) return;
	else if (target->next == target) {
		head->next = NULL;
	}
	else if (target->next == head->next) {
		while (point->next != target) {
			point = point->next;
		}
		point->next = head->next;
	}
	else {
		while (point->next != target) {
			point = point->next;
		}
		
		if (point == head) {
			tail = head->next;
			while (tail->next != head->next) {
				tail = tail->next;
			}
			//printf("*******%d!!***\n", tail->data);
			tail->next = head->next->next;
		}

		point->next = target->next;
	}

	free(target);
}
int getSize(Node* head) {
	int cnt = 0;
	Node* temp = head;
	while (temp->next != NULL) {
		temp = temp->next;
		cnt++;
	}
	return cnt;
}
int main() {
	int n, k, i, cnt = 0;

	Node* head = malloc(sizeof(Node));
	head->next = NULL;
	Node* point;
	Node* temp;

	scanf("%d %d", &n, &k);
	int* remain = malloc(sizeof(int) * (n + 1));

	for (i = 1; i <= n; i++) {
		if (i == 1) {
			AddNode(head, head, i);
			point = head->next;
		}
		else {
			AddNode(head, point, i);
			point = point->next;
		}
	}

	point = head->next;

	while (head->next != NULL) {
		if (k != 1)
			for (i = 0; i < k - 1; i++)
				point = point->next;

		remain[cnt] = point->data;
		cnt++;

		//printf("what save : %d\n", remain[cnt - 1]);

		temp = point->next;
		
		DeleteNode(head, point);
		//printf("temp data : %d\n", temp->data);
		point = temp;
	}

	printf("<");
	for (i = 0; i < n; i++)
		if (i == n - 1)
			printf("%d", remain[i]);
		else
			printf("%d, ", remain[i]);
	printf(">");

	free(remain);

	return 0;
}
