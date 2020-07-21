using namespace std;

int GCD(int w, int h) {
    while (h != 0) {
        int tmp = w % h;
        w = h;
        h = tmp;
    }
    return w;
}

long long solution(int w, int h) {
    //w<h·Î ¼³Á¤
    if (w > h) {
        long long tmp = w;
        w = h;
        h = tmp;
    }

    long long answer = 1;

    long long nw = w / GCD(h, w);
    long long nh = h / GCD(h, w);
    answer = (long long)w * (long long)h - (nh + nw - 1) * GCD(h, w);

    return answer;
}
