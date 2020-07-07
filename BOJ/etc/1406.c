//1406

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define _CRT_SECURE_NO_WARNINGS

char string[100001];

//Node Á¤ÀÇ
typedef struct Node {
	char data;
	struct Node* next;
	struct Node* back;
} Node;

Node* searchTail(Node* head) {
	Node* tail = head;

	while (tail->next != NULL) {
		tail = tail->next;
	}

	return tail;
}

void AddNode(Node* target, char data) {
	Node* newNode = malloc(sizeof(Node));
	Node* temp = target->next;

	newNode->next = target->next;
	newNode->back = target;
	if (temp != NULL)
		temp->back = newNode;
	target->next = newNode;

	newNode->data = data;
}

void DeleteNode(Node* target) {
	Node* leftNode = target->back;
	Node* rightNode = target->next;
	if (rightNode != NULL)
		leftNode->next = rightNode;
	else
		leftNode->next = NULL;
	if (rightNode != NULL)
		rightNode->back = leftNode;

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

	int n, i;
	char input, data;

	Node* head = malloc(sizeof(Node));
	head->next = NULL;
	head->back = NULL;

	scanf("%s", string);

	for (i = strlen(string) - 1; i >= 0; i--) {
		AddNode(head, string[i]);
	}

	scanf("%d", &n);

	//locate on tail node
	Node* target = searchTail(head);
	Node* temp = NULL;

	while (n--) {
		scanf(" %c", &input);

		if (input == 'P') {
			scanf(" %c", &data);
			AddNode(target, data);
			target = target->next;
		}
		else if (input == 'L') {
			if (target != head) target = target->back;
		}
		else if (input == 'D') {
			if (target->next != NULL) target = target->next;
		}
		else if (input == 'B') {
			temp = target->back;
			if (target != head) {
				DeleteNode(target);
				target = temp;
			}
		}
	}

	Node* point = head->next;

	while (point != NULL) {
		printf("%c", point->data);
		point = point->next;
	}

	return 0;
}