# HashMap相关实例

## **242. 有效的字母异位词**

给定两个字符串 s 和 t，编写一个函数来判断 t 是否是 s 的字母异位词。

**进阶:**

如果输入字符串包含 unicode 字符怎么办？你能否调整你的解法来应对这种情况？

**思路**


* 标签：哈希映射
* 首先判断两个字符串长度是否相等，不相等则直接返回 false
* 若相等，则初始化 26 个字母哈希表，遍历字符串 s 和 t
* s 负责在对应位置增加，t 负责在对应位置减少
* 如果哈希表的值都为 0，则二者是字母异位词
  #### 

### C++ 解法

#### **解法一：暴力解决**

```java
class Solution {
    public boolean isAnagram(String s, String t) {
        if (s.length() != t.length())
            return false;
        int [] alpha = new int[26];
        for(int i = 0; i < s.length(); i++) {
            alpha[s.charAt(i) - 'a']++;
            alpha[t.charAt(i) - 'a']--;
        }
        for (int i = 0; i < 26; i++) {
            if (alpha[i] != 0) {
                return false;
            }
        }
        return true;
    }
}
```

#### **解法二、**[sort排序](https://blog.csdn.net/liuzuyi200/article/details/8974326)

```c++
class Solution {
public:
    bool isAnagram(string s, string t) {
        sort(s.begin(), s.end());
        sort(t.begin(), t.end());
        return s == t;
    }
};
```

#### **解法三、map1**

```c++
class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.size() != t.size()) return false;
        unordered_map<char, int> map;
        for (char c: s) map[c] ++;
        for (char c: t) {
            if (--map[c] == -1) {
                return false;
            }
        }
        return true;
    }
};
```

#### **解法三、map2**

```c++
class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char, int> map;
        for (int i = 0; i < max(s.size(), t.size()); i++) {
            map[s[i]]++, map[t[i]]--;
        }
        for (auto it : map) {
            if (it.second != 0) return false;
        }
        return true;
    }
};
```

#### 解法四、数组

```c++
class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.size() != t.size()) return false;
        int hash[26] = {0};
        for (char c: s) hash[c - 'a']++;
        for (char c: t) {
            if (--hash[c-'a'] == -1) return false;
        }
        return true;
    }
};
```

### Python解法

#### 解法一：collections

```python
class Solution(object):
    def isAnagram(self, s, t):
        """
        :type s: str
        :type t: str
        :rtype: bool
        """
        return collections.Counter(s) == collections.Counter(t)
```

#### 解法二：字典法

```python
class Solution(object):
    def isAnagram(self, s, t):
        """
        :type s: str
        :type t: str
        :rtype: bool
        """
        dic1, dic2 = {}, {}
        for item in s:
            dic1[item] = dic1.get(item, 0) + 1
        for item in t:
            dic2[item] = dic2.get(item, 0) + 1
        return dic1 == dic2
```

## [49. 字母异位词分组](https://leetcode-cn.com/problems/group-anagrams/)

**说明**


* 所有输入均为小写字母
* 不考虑答案输出的顺序

### C++解法

#### 解法一：HashMap

```c++
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> mp;
        for (string s : strs) {
            string t = s; 
            sort(t.begin(), t.end());
            mp[t].push_back(s);
        }
        vector<vector<string>> anagrams;
        for (auto p : mp) { 
            anagrams.push_back(p.second);
        }
        return anagrams;
    }
};
```

### Python解法

#### 解法一：collect the groups

```python
class Solution(object):
    def groupAnagrams(self, strs):
        """
        :type strs: List[str]
        :rtype: List[List[str]]
        """
        groups = collections.defaultdict(list)
        for s in strs:
            groups[tuple(sorted(s))].append(s)
        return map(sorted, groups.values())
```

#### 解法二：sort和group方法


* collections.Counter创建一个计数器对象。计数器对象就像是用于计数的特定种类的字典（哈希为相同值的对象）
* 在此使用tuple（sorted（s）），以便将字谜散列为相同的值。使用元组是因为sorted返回一个列表，该列表不能被散列，但是元组可以被散列
* filter：根据给定函数选择列表中的某些元素（第一个参数-此处给出lambda函数）
* 如果该元素的字anagrams大于1，则此处定义的lambda函数将返回True。

```python
class Solution(object):
def anagrams(self, strs):
count = collections.Counter([tuple(sorted(s)) for s in strs])
return filter(lambda x: count[tuple(sorted(x))]>1, strs)
```

#### 解法三：HashMap

```python
class Solution(object):
    def groupAnagrams(self, strs):
        hashmap = {}
        for st in strs:
            key = ''.join(sorted(st))
            if key not in hashmap:
                hashmap[key] = [st]
            else:
                hashmap[key] += [st]
        return hashmap.values()
```

## [1. 两数之和](https://leetcode-cn.com/problems/two-sum/)

### C++解法

#### Python解法

#### **解法一、hashMap**

熟悉Python中的[enumerate](https://www.runoob.com/python/python-func-enumerate.html)基本用法

```python
class Solution(object):
    def twoSum(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: List[int]
        """
        d = {}
        for i, n in enumerate(nums):
            m = target - n
            if m in d:
                return [d[m], i]
            else:
                d[n] = i
```

#### 解法二、Mapy中使用buffer处理

```python
class Solution(object):
    def twoSum(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: List[int]
        """
        if len(nums) <= 1:
            return False
        buff_dict = {}
        for i in range(len(nums)):
            if nums[i] in buff_dict:
                return [buff_dict[nums[i]], i]
            else:
                buff_dict[target -nums[i]] = i 
```

### Java解法

# 二叉树相关实例

## [429. N叉树的层序遍历](https://leetcode-cn.com/problems/n-ary-tree-level-order-traversal/)

### Python解法

#### 解法一：BFS solution

```python
class Solution(object):
    def levelOrder(self, root):
        output, queue = [], [root] if root else []
        while queue:
            output.append([node.val for node in queue])
            queue = [child for node in queue for child in node.children]
        return output
```

### C++解法

解法一：

```c++
class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        if (root == NULL) {
            return vector<vector<int>>();
        }
        vector<vector<int>> res;
        queue<Node*> q;
        q.push(root);
        while (!q.empty()) {
            int size = q.size();
            vector<int> curLevel;
            for (int i = 0; i < size; i++) {
                Node* tmp = q.front();
                q.pop();
                curLevel.push_back(tmp -> val);
                for (auto n: tmp -> children) {
                    q.push(n);
                }
            }
            res.push_back(curLevel);
        }
        return res;
    }
};
```

