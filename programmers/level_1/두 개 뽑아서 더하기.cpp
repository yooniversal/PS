#include <string>
#include <algorithm>
#include <vector>
using namespace std;

bool chk[201];

vector<int> solution(vector<int> numbers) {
    vector<int> answer;

    for (int i = 0; i < numbers.size() - 1; ++i)
        for (int j = i + 1; j < numbers.size(); ++j) {
            if (chk[numbers[i] + numbers[j]]) continue;
            chk[numbers[i] + numbers[j]] = true;
            answer.push_back(numbers[i] + numbers[j]);
        }
    sort(answer.begin(), answer.end());

    return answer;
}