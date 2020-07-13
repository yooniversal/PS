//5639

#include <iostream>
#include <string>
#include <cstring>
#include <cstdio>
#include <vector>
#include <deque>
#include <queue>
#include <stack>
#include <cmath>
#include <algorithm>
using namespace std;

class Node {
public:
	int data;
	Node* left;
	Node* right;
	Node() {}
	Node(int data) : data(data) {
		left = NULL;
		right = NULL;
	}
	~Node() {
		this->data = NULL;
		left = NULL;
		right = NULL;
	}
};

Node* root;

void addNode(Node* here, int data) {
	here = new Node;
	here->data = data;
	here->left = NULL;
	here->right = NULL;
}

void searchNode(Node* root, int data) {
	Node* cur = root;
	while (1) {
		Node* prev = cur;
		if (cur->data > data) {
			if (cur->left != NULL) {
				cur = cur->left;
				prev->left = cur;
			}
			else {
				cur->left = new Node(data);
				cur = cur->left;
				prev->left = cur;
				return;
			}
		}
		else {
			if (cur->right != NULL) {
				cur = cur->right;
				prev->right = cur;
			}
			else {
				cur->right = new Node(data);
				cur = cur->right;
				prev->right = cur;
				return;
			}
		}
	}
}

void postorder(Node* cur) {
	if (!cur) return;
	postorder(cur->left);
	postorder(cur->right);
	if(cur != NULL) printf("%d\n", cur->data);
}



int main() {

	cin.tie(nullptr);
	cout.tie(NULL);
	//ios_base::sync_with_stdio(false);

	int input;

	root = new Node(-1);

	//input
	while (scanf("%d", &input) > 0) {
		if (root->data == -1) {
			root->data = input;
		}
		else {
			searchNode(root, input);
		}
	}

	postorder(root);

	return 0;
}