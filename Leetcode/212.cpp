class Solution {
public:
    int N, M;
    int dx[4] = {-1, 1, 0, 0};
    int dy[4] = {0, 0, 1, -1};
    bool chk[15][15];

    struct Trie {
        bool finish;
        Trie* next[26];

        Trie(): finish(false) { memset(next, 0, sizeof(next)); }
        Trie(bool _finish): finish(_finish) { memset(next, 0, sizeof(next)); }
        ~Trie() {
            for (int i = 0; i < 26; i++)
                if (next[i]) delete next[i];
        }

        Trie* insert(char ch) {
            int index = ch - 'a';
            if (next[index] == NULL) {
                next[index] = new Trie(true);
            }
            return next[index];
        }
    
        bool find(string key, int idx) {
            if (idx == key.size()) return finish;
            int cur = key[idx] - 'a';
            if (next[cur] == NULL) return false;
            return next[cur]->find(key, idx+1);
        }
    };

    bool OOB(int x, int y) {
        return x<0 || x>=N || y<0 || y>=M;
    }

    void DFS(vector<vector<char>>& board, Trie* root, int x, int y, int length) {
        if (length >= 10) return;        

        for (int i=0; i<4; i++) {
            int nx = x + dx[i], ny = y + dy[i];
            if (OOB(nx, ny) || chk[nx][ny]) continue;
            chk[nx][ny] = true;
            DFS(board, root->insert(board[nx][ny]), nx, ny, length + 1);
            chk[nx][ny] = false;
        }
    }

    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        vector<string> ret;

        N = board.size();
        M = board[0].size();

        Trie* root = new Trie();

        for (int i=0; i<N; i++) {
            for (int j=0; j<M; j++) {
                chk[i][j] = true;
                DFS(board, root->insert(board[i][j]), i, j, 1);
                chk[i][j] = false;
            }
        }

        for (string& word : words) {
            if (root->find(word, 0)) {
                ret.push_back(word);
            }
        }

        return ret;
    }
};