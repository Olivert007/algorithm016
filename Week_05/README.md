学习笔记

## 爬楼梯
### 第一种思路：动态规划

'''c++
class Solution {
public:
    int climbStairs(int n) {
        int p = 0, q = 0, r = 1;
        for (int i = 1; i <= n; ++i) {
            p = q; 
            q = r; 
            r = p + q;
        }
        return r;
    }
};

'''
### 第二种思路：数学

'''c++
    int climbStairs(int n) {
        double sqrt_5 = sqrt(5);
        double fib_n = pow((1+sqrt_5) / 2, n+1) - pow((1-sqrt_5) / 2, n+1);
        return (int) (fib_n / sqrt_5);
    }
'''

### 第三种思路：递归


## 120. 三角形最小路径和

### 第一种思路：动态规划

'''c++
class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        vector<vector<int>> f(n, vector<int>(n));
        f[0][0] = triangle[0][0];
        for (int i = 1; i < n; ++i) {
            f[i][0] = f[i-1][0] + triangle[i][0];
            for (int j = 1; j < i; ++j) {
                f[i][j] = min(f[i-1][j-1], f[i-1][j]) + triangle[i][j];
            }
            f[i][i] = f[i-1][i-1] + triangle[i][i];
        }
        return *min_element(f[n-1].begin(), f[n-1].end());
    }
};
'''
min_element 函数使用https://blog.csdn.net/CrazyQiQi/article/details/82886427

### 第二种思路：递归

'''c++
    int minimumTotal(vector<vector<int>>& triangle) {
        vector<int> dp(triangle.back());
        for(int i = triangle.size()-2; i >= 0; i--) {
            for (int j = 0; j <= i; j++) {
                dp[j] = min(dp[j], dp[j+1]) + triangle[i][j];
            }
        }
        return dp[0];
    }
'''


## 198. 打家劫舍



### Python 
#### 解法一：动态规划
'''python
class Solution:
    def rob(self, nums: List[int]) -> int:
        cur, pre = 0, 0
        for num in nums:
            cur , pre = max(pre+num, cur), cur
        return cur 
'''

### C++
#### 解法一：动态规划
(1) if-else
'''c++
class Solution {
public:
    int rob(vector<int>& nums) {
        int sumOdd = 0;
        int sumEven = 0;

        for (int i = 0; i < nums.size(); i++) {
            if (i%2 == 0) {
                sumEven += nums[i];
                sumEven = max(sumOdd, sumEven);
            }
            else {
                sumOdd += nums[i];
                sumOdd = max(sumOdd, sumEven);
            }
        }
        return max(sumOdd, sumEven);
    }
};
'''
(2) dp 解法

'''c++
class Solution {
public:
    int rob(vector<int>& nums) {
        int len = nums.size();
        if (len == 0) {
            return 0;
        }
        vector<int> dp(len+1, 0);

        dp[0] = 0;
        dp[1] = nums[0];
        for (int i = 2; i <= len; i++) {
            dp[i] = max(dp[i-1], dp[i-2] + nums[i-1]);
        }
        return dp[len];
    }
};
'''
(3) 空间优化
空间复杂度也从 O(n) 降到了 O(1)
'''c++
class Solution {
public:
    int rob(vector<int>& nums) {
        int prev = 0;
        int curr = 0; 
        for (int i : nums) {
            int temp = max (curr, prev+i);
            prev = curr;
            curr = temp;
        }
        return curr;
    }  
};
'''

## 213. 打家劫舍 II

### Python
(1) 解法一：动态规划
'''c++
class Solution:
    def rob(self, nums: [int]) -> int:
        def my_rob(nums):
            cur, pre = 0, 0
            for num in nums: 
                cur, pre = max(pre+num, cur), cur
            return cur
        return max(my_rob(nums[:-1]),my_rob(nums[1:])) if len(nums) != 1 else nums[0]
'''

### C++
（1）解法一：动态规划
'''c++
class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return 0;
        if (n == 1) return nums[0];
        int Max1 = rob1(nums, 0, n-1);
        int Max2 = rob1(nums, 1, n) ;
        return max(Max1, Max2);
    }
    int rob1(vector<int> & nums, int start, int end) {
        int preMax = 0;
        int currMax = 0;
        for (int i = start; i < end; i++) {
            int temp = currMax;
            currMax = max(nums[i]+preMax, currMax);
            preMax = temp;
        }
        return currMax;
    }
};
'''

## 53. 最大子序和

### C语言
#### 解法一：动态规划
'''c
#define MAX(a, b) (((a)>(b)) ? (a) : (b))
int maxSubArray(int* nums, int numsSize){
    int pre = 0, maxAns = nums[0];
    for(int i = 0; i < numsSize; i++) {
        pre = MAX(pre+ nums[i], nums[i]);
        maxAns = MAX(maxAns, pre);
    }
    return maxAns;
}
'''
### C++
#### 解法一、动态规划
'''c++
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int pre = 0, maxAns = nums[0];
        for (const auto &x:nums) {
            pre = max(pre+x, x);
            maxAns = max(maxAns, pre);
        }
        return maxAns;
    }
};
'''
#### 解法二、贪心算法
'''c++
class Solution
{
public:
    int maxSubArray(vector<int> &nums)
    {
        //类似寻找最大最小值的题目，初始值一定要定义成理论上的最小最大值
        int result = INT_MIN;
        int numsSize = int(nums.size());
        int sum = 0;
        for (int i = 0; i < numsSize; i++)
        {
            sum += nums[i];
            result = max(result, sum);
            //如果sum < 0，重新开始找子序串
            if (sum < 0)  {
                sum = 0;
            }
        }
        return result;
    }
};

'''
## 152. 乘积最大子数组
### C++ 
（1）解法一：动态规划
'''c++
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        vector <int> maxF(nums), minF(nums);
        for (int i = 1; i < nums.size(); ++i) {
            maxF[i] = max(maxF[i - 1] * nums[i], max(nums[i], minF[i - 1] * nums[i]));
            minF[i] = min(minF[i - 1] * nums[i], min(nums[i], maxF[i - 1] * nums[i]));
        }
        return *max_element(maxF.begin(), maxF.end());
    }
};

'''
(2) 空间优化
'''c++
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int maxF = nums[0], minF = nums[0], ans = nums[0];
        for (int i = 1; i < nums.size(); ++i) {
            int mx = maxF, mn = minF;
            maxF = max(mx * nums[i], max(nums[i], mn * nums[i]));
            minF = min(mn * nums[i], min(nums[i], mx * nums[i]));
            ans = max(maxF, ans);
        }
        return ans;
    }
};
'''
### Python
(1) 动态规划
'''python
'''