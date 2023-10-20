int maxCost(vector<int> cost, vector<string> labels, int dailyCount) {
    int ret = 0;
    
    int cnt = 0;
    int cost_sum = 0;
    for(int i=0; i<labels.size(); ++i) {
        cost_sum += cost[i];
        if(labels[i] == "legal") ++cnt;
        if(cnt >= dailyCount) {
            ret = max(ret, cost_sum);
            cost_sum = 0;
            cnt = 0;
        }
    }
    
    return ret;
}
