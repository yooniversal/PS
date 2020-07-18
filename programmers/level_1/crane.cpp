#include <string>
#include <vector>
#include <stack>

using namespace std;

int solution(vector<vector<int>> board, vector<int> moves) {
    int answer = 0;
    stack<int> map[30];
    stack<int> ans;

    for (int i = 0; i < board[0].size(); i++) {
        for (int j = board[0].size() - 1; j >= 0; j--) {
            if (board[j][i] != 0)
                map[i].push(board[j][i]);
        }
    }

    for (int i = 0; i < moves.size(); i++) {
        int where = moves[i] - 1;
        if (map[where].size() > 0) {
            ans.push(map[where].top());
            map[where].pop();
        }
        if (ans.size() > 1) {
            int top = ans.top();
            ans.pop();
            if (ans.top() == top) {
                ans.pop();
                answer += 2;
            }
            else {
                ans.push(top);
            }
        }
    }

    return answer;
}