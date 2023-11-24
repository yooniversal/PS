#include <string>
#include <cstring>
#include <vector>

using namespace std;

/**
    f(alp, cop) : alp, cop를 가질 때 소비하는 최소 시간
    각 상태에서 해주는 작업
    - 모든 문제를 풀 수 있는지 체크 : O(N)
    - 문제 스캔하면서 풀 수 있는 문제 분류 : O(N)
    - 3가지 방법을 모두 시도
      풀 수 있는 문제가 있으면 모두 시도
    => 복잡도 : 10^6 * 상수
*/

const int INF = 987654321;
int cache[151][151];
vector<vector<int>> P;
int max_alp = -1, max_cop = -1;

int f(int alp, int cop) {
    if (alp >= max_alp && cop >= max_cop) return 0;
    int& ret = cache[alp][cop];
    if (ret != -1) return ret;
    ret = INF;
    
    if (alp < max_alp) ret = min(ret, f(alp+1, cop) + 1);
    if (cop < max_cop) ret = min(ret, f(alp, cop+1) + 1);
    
    for (auto& problem : P) {
        if (problem[0] <= alp && problem[1] <= cop) {
            int new_alp = min(alp + problem[2], max_alp);
            int new_cop = min(cop + problem[3], max_cop);
            ret = min(ret, f(new_alp, new_cop) + problem[4]);
        }
    }
    
    return ret;
}

int solution(int alp, int cop, vector<vector<int>> problems) {
    P = problems;
    memset(cache, -1, sizeof(cache));
    
    for (auto& p : problems) {
        max_alp = max(max_alp, p[0]);
        max_cop = max(max_cop, p[1]);
    }
    
    return f(alp, cop);
}