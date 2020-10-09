class Solution {
public:
	int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> d(wordList.begin(), wordList.end());
        if (d.count(endWord) == 0) return 0;
        queue<string> q;
        q.push(beginWord);
        int res = 0;
        while(!q.empty()) {
            res++;
            int q_size = q.size();
            for (int i = 0; i < q_size; i++) {
                auto curr = q.front();
                if (curr == endWord) return res;
                q.pop();
                for (int j = 0; j < curr.size(); j++) {
                        auto tmp = curr[j];
                        for (char c = 'a'; c <= 'z'; c++) {
                            curr[j] = c;
                            if (d.count(curr) != 0) {
                                d.erase(curr);
                                q.push(curr);
                            }
                        }
                        curr[j] = tmp;
                    }
                }
            }
            return 0;
        }
    
};