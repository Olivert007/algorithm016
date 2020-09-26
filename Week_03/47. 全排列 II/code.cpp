class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> v;
        vector<int> r;
        map<int, int> map;
        for (int i: nums) {
            if (map.find(i) == map.end()) map[i] = 0;
            map[i]++;
        }        
        permuteUnique(v, r, map, nums.size());
        return v;
    }

    void permuteUnique(vector<vector<int>> &v, vector<int> &r, map<int, int> &map, int n)
    {
        if (n <= 0) {
            v.push_back(r);
            return;
        }
        for (auto &p: map) {
            if (p.second <= 0) continue;
            p.second--;
            r.push_back(p.first);
            permuteUnique(v, r, map, n-1);
            r.pop_back();
            p.second++;
        }
    }
};