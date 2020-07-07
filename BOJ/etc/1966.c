//1966

#include <stdio.h>
#include <stdlib.h>
#define _CRT_SECURE_NO_WARNINGS

//Node Á¤ÀÇ
typedef struct Node {
	int data;
	int key;
	struct Node* next;
} Node;

Node* searchTail(Node* head) {
	Node* tail = head;
	while (tail->next != NULL) {
		tail = tail->next;
	}
	return tail;
}
void DeleteNode(Node* head, Node* target) {
	Node* temp = head;

	if (target == head) return;
	else if (target == head->next) {
		head->next = target->next;
	}
	else {
		while (temp->next != target) {
			temp = temp->next;
		}
		temp->next = target->next;
	}

	free(target);
}

void backAddNode(Node* head, int data, int key) {
	Node* tail = searchTail(head);
	Node* newNode = malloc(sizeof(Node));
	tail->next = newNode;
	newNode->data = data;
	newNode->key = key;
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

Node* SearchMaxNode(Node* head) {
	Node* temp = head;
	Node* memory;
	int max;

	if (temp->next != NULL) {
		temp = temp->next;
		max = temp->data;
		memory = temp;
		while (temp->next != NULL) {
			temp = temp->next;
			if (max < temp->data) {
				max = temp->data;
				memory = temp;
			}
		}
	}

	return memory;
}

void movecurrent(Node* head, Node* current) {
	Node* tail = searchTail(head);

	head->next = current->next;
	tail->next = current;
	current->next = NULL;
}
int main() {
	int n, m, i, data, cnt = 0, T;
	char input[11];
	Node* head = malloc(sizeof(Node));
	head->next = NULL;

	Node* current;
	Node* maxelse;
	Node* deletepoint;

	scanf("%d", &T);

	while (T != 0) {
		scanf("%d %d", &n, &m);

		for (i = 0; i < n; i++) {
			scanf("%d", &data);
			if (i != m)
				backAddNode(head, data, 0);
			else
				backAddNode(head, data, 1);
		}

		current = head->next;
		maxelse = SearchMaxNode(head);

		while (head->next != NULL) {
			if (current->data != maxelse->data) {
				movecurrent(head, current);
				current = head->next;
				maxelse = SearchMaxNode(head);
			}
			else if (current == maxelse || current->data == maxelse->data) {
				cnt++;
				if (current->key == 1) {
					printf("%d\n", cnt);
					break;
				}
				else {
					DeleteNode(head, current);
					current = head->next;
					maxelse = SearchMaxNode(head);
				}
			}
		}

		while (head->next != NULL) {
			DeleteNode(head, head->next);
		}

		cnt = 0;

		T--;
	}

	return 0;
}