#include <string>
#include <vector>

using namespace std;

double solution(vector<int> arr) {
    double answer = 0;
    for (int i = 0; i < arr.size(); i++) {
        answer += (double)arr[i];
    }
    answer /= (double)arr.size();
    return answer;
}