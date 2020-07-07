#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> arr) {
    vector<int> answer;

    int min = arr[0], key = 0;
    for (int i = 1; i < arr.size(); i++)
        if (min > arr[i]) {
            min = arr[i];
            key = i;
        }

    vector<int>::iterator iter = arr.begin();
    arr.erase(iter + key, iter + key + 1);
    answer.assign(arr.begin(), arr.end());

    if (answer.empty()) answer.push_back(-1);

    return answer;
}