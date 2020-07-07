//10866

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

void frontdeleteNode(Node* head) {
	Node* temp = head->next;
	head->next = temp->next;

	free(temp);
}

void backdeleteNode(Node* head) {
	Node* tail = head;
	Node* temp = NULL;

	while (tail->next != NULL) {
		temp = tail;
		tail = tail->next;
	}

	if (temp != NULL)
		temp->next = NULL;

	free(tail);
}

void backAddNode(Node* head, int data) {
	Node* tail = searchTail(head);
	Node* newNode = malloc(sizeof(Node));

	tail->next = newNode;
	newNode->data = data;
	newNode->next = NULL;
}

void frontAddNode(Node* head, int data) {

	Node* newNode = malloc(sizeof(Node));

	newNode->next = head->next;
	newNode->data = data;

	head->next = newNode;
}

int linkedSize(Node* head) {
	int cnt = 0;

	while (head->next != NULL) {
		head = head->next;
		cnt++;
	}

	return cnt;
}

int main() {

	int n, i, data;
	char input[11];

	Node* head = malloc(sizeof(Node));
	head->next = NULL;
	Node* temp;

	scanf("%d", &n);

	for (i = 0; i < n; i++) {
		scanf("%s", input);

		if (!strcmp("push_back", input)) {
			scanf("%d", &data);
			backAddNode(head, data);
		}
		else if (!strcmp("push_front", input)) {
			scanf("%d", &data);
			frontAddNode(head, data);
		}
		else if (!strcmp("pop_front", input)) {
			temp = head->next;
			if (temp == NULL)
				printf("-1\n");
			else {
				printf("%d\n", temp->data);
				frontdeleteNode(head);
			}
		}
		else if (!strcmp("pop_back", input)) {
			temp = searchTail(head);
			if (head->next == NULL)
				printf("-1\n");
			else {
				printf("%d\n", temp->data);
				backdeleteNode(head);
			}
		}
		else if (!strcmp("size", input))
			printf("%d\n", linkedSize(head));
		else if (!strcmp("empty", input))
			if (head->next == NULL) printf("1\n");
			else printf("0\n");
		else if (!strcmp("front", input)) {
			temp = head->next;
			if (temp == NULL) printf("-1\n");
			else printf("%d\n", temp->data);
		}
		else {
			temp = searchTail(head);
			if (head->next == NULL) printf("-1\n");
			else printf("%d\n", temp->data);
		}

		memset(input, NULL, sizeof(input));
	}

	return 0;
}