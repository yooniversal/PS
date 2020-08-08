#include <string>
#include <vector>

using namespace std;

vector<int> solution(int brown, int yellow) {
    vector<int> answer;

    int sum = brown + yellow;

    int m = 3;
    while (!(sum % m == 0 && m >= sum / m && 2 * (m + sum / m) - 4 == brown && (m - 2) * (sum / m - 2) == yellow)) {
        m++;
    }

    answer.push_back(m);
    answer.push_back(sum / m);

    return answer;
}