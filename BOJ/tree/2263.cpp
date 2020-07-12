//2263

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

int n;
int inorder[100001], postorder[100001];

int get_irp(int val) {
	for (int i = 1; i <= n; i++)
		if (inorder[i] == val)
			return i;
}

void order(int is, int ie, int ps, int pe) {
	if (is > ie) return;
	int prp = pe;
	int irp = get_irp(postorder[prp]);
	cout << inorder[irp] << " ";
	if (is >= ie) return;
	order(is, irp - 1, ps, ps + (irp -1 -is));
	order(irp+1, ie, ps + (irp -1 -is)+1, pe-1);
}

int main() {

	cin.tie(nullptr);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> n;

	for (int i = 1; i <= n; i++) cin >> inorder[i];
	for (int i = 1; i <= n; i++) cin >> postorder[i];
	order(1, n, 1, n);

	return 0;
}