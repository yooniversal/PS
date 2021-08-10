#include <string>
#include <vector>

using namespace std;

const int INF = 987654321;

char get_score(double cur) {
    if (cur >= 90.0) return 'A';
    if (cur >= 80.0) return 'B';
    if (cur >= 70.0) return 'C';
    if (cur >= 50.0) return 'D';
    return 'F';
}

string solution(vector<vector<int>> scores) {
    string answer = "";

    int n = scores.size();
    for (int i = 0; i < n; ++i) {
        double sum = 0.0;
        int maxx = 0, minn = INF, same_cnt = 0;
        for (int j = 0; j < n; ++j) {
            sum += scores[j][i];
            maxx = max(maxx, scores[j][i]);
            minn = min(minn, scores[j][i]);

            if (i != j && scores[j][i] == scores[i][i]) ++same_cnt;
        }

        if ((scores[i][i] == maxx || scores[i][i] == minn) && same_cnt == 0) {
            sum -= scores[i][i];
            answer += get_score(sum / (n - 1));
        }
        else {
            answer += get_score(sum / n);
        }
    }

    return answer;
}