#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;
const int MAX = 10001;

struct NODE {
    int x, y, n;
    NODE() : x(-1), y(-1), n(-1) {}
    NODE(int a, int b, int c) : x(a), y(b), n(c) {}
    bool operator<(const NODE& N) const {
        if (y != N.y) return y > N.y;
        return x < N.x;
    }
};

struct LR {
    int l, r;
    LR() : l(-1), r(-1) {}
    LR(int a, int b) : l(a), r(b) {}
};

LR lr[MAX];
vector<NODE> Node, NodeNum;
vector<int> preo, posto;

void connect(NODE& root, NODE& cur) {
    if (lr[root.n].l == -1 && cur.x < root.x)
        lr[root.n].l = cur.n;
    else if (lr[root.n].r == -1 && root.x < cur.x)
        lr[root.n].r = cur.n;
    else {
        int left = lr[root.n].l, right = lr[root.n].r;
        if (cur.x < root.x)
            connect(NodeNum[left], cur);
        else
            connect(NodeNum[right], cur);
    }
}

void preorder(int root) {
    preo.push_back(root);
    int left = lr[root].l, right = lr[root].r;
    if (left != -1) preorder(left);
    if (right != -1) preorder(right);
}

void postorder(int root) {
    int left = lr[root].l, right = lr[root].r;
    if (left != -1) postorder(left);
    if (right != -1) postorder(right);
    posto.push_back(root);
}

vector<vector<int>> solution(vector<vector<int>> nodeinfo) {
    vector<vector<int>> answer;

    for (int i = 0; i < nodeinfo.size(); ++i) {
        Node.push_back({ nodeinfo[i][0], nodeinfo[i][1], i + 1 });
    }
    sort(Node.begin(), Node.end());

    //각 넘버에 맞는 노드 매칭
    NodeNum.resize(MAX);
    for (int i = 0; i < Node.size(); ++i)
        NodeNum[Node[i].n] = Node[i];

    for (int i = 1; i < Node.size(); ++i)
        connect(Node[0], Node[i]);

    preorder(Node[0].n);
    postorder(Node[0].n);
    answer.push_back(preo);
    answer.push_back(posto);

    return answer;
}