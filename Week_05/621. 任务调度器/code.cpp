bool cmp(int &a, int &b) {
    return a > b;
}
class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        if (!n) return tasks.size();
        vector<int> nums(26,0);
        for (char task: tasks) {
            nums[task-'A'] += 1;
        }
        sort(nums.begin(), nums.end(), cmp);
        int total = (n+1)*(nums[0]-1)+1;
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] == nums[0]) {
                total++;
            }
        }
        return total > tasks.size() ? total:tasks.size();
    }
};