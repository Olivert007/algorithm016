class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        int count = 0;
        int gi = 0, si = 0;
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        while(gi < g.size() && si < s.size()) {
            if (s[si] >= g[gi]) {
                count += 1;
                si += 1;
                gi += 1;
            }
            else if (s[si] < g[gi]) {
                si += 1;
            }
        }
        return count;
    }
};