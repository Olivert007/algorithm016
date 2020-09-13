class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.empty()) return 0;
        int slowIndex = 0;
        for(int fastIndex = 0; fastIndex < (nums.size()-1); fastIndex++) {
            if (nums[fastIndex] != nums[fastIndex+1]) {
                nums[++slowIndex] = nums[fastIndex+1];
            }
        }
        return slowIndex+1;
        
    }
};