long minTime(vector<int> files, int numCores, int limit) {
    long ret = 0;
    
    vector<int> a;
    for(int i=0; i<files.size(); ++i) {
        if(files[i] % numCores == 0) a.push_back(files[i]);
        else ret += files[i];
    }
    
    sort(a.rbegin(), a.rend());
    
    for(int i=0; i<a.size(); ++i) {
        if(i < limit) {
            ret += a[i] / numCores;
        } else {
            ret += a[i];
        }
    }
    
    return ret;
}
