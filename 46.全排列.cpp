/*
 * @lc app=leetcode.cn id=46 lang=cpp
 *
 * [46] 全排列
 */

#include <vector>
using namespace std;

// @lc code=start

/**
 * @brief 解法1：使用标志位标记重复元素
 *
 */
class Solution1 {
    vector<vector<int>> res;

    void backtrack(const vector<int> &nums, vector<int> &cur) {
        if (nums.size() == cur.size()) {
            res.push_back(cur);
            return;
        }

        for (auto &num : nums) {
            bool unused_num = true;  // 当前数据是否还未加入排列

            for (auto &var : cur) {
                if (var == num) {
                    unused_num = false;
                    break;
                }
            }

            if (unused_num) {
                cur.push_back(num);    // 将还未加入排列的元素添加进去
                backtrack(nums, cur);  // 回溯
                cur.pop_back();        // 删除此元素，继续下一个循环
            }
        }
    }

public:
    vector<vector<int>> permute(vector<int> &nums) {
        vector<int> cur;
        backtrack(nums, cur);
        return res;
    }
};

/**
 * @brief 解法2：使用索引划分使用/未使用的数据
 *
 */
class Solution2 {
    vector<vector<int>> res;

    void backtrack(vector<int> &nums, vector<int> &cur, size_t index) {
        if (nums.size() == index) {
            res.push_back(cur);
            return;
        }

        for (size_t i = index; i < nums.size(); ++i) {
            cur.push_back(nums[i]);           // 将还未加入排列的元素添加进去
            swap(nums[i], nums[index]);       // 交换顺序，保证index之后都是未使用的
            backtrack(nums, cur, index + 1);  // 回溯
            cur.pop_back();                   // 删除此元素，继续下一个循环
            swap(nums[i], nums[index]);       // 交换回来
        }
    }

public:
    vector<vector<int>> permute(vector<int> &nums) {
        vector<int> cur;
        backtrack(nums, cur, 0);
        return res;
    }
};

/**
 * @brief 原地交换
 *        仅使用nums而不再使用cur数组
 *
 */
class Solution {
    vector<vector<int>> res;

    void backtrack(vector<int> &nums, size_t index) {
        if (nums.size() == index) {
            res.push_back(nums);
            return;
        }

        for (size_t i = index; i < nums.size(); ++i) {
            swap(nums[i], nums[index]);  // 交换顺序，保证index之后都是未使用的
            backtrack(nums, index + 1);  // 回溯
            swap(nums[i], nums[index]);  // 交换回来
        }
    }

public:
    vector<vector<int>> permute(vector<int> &nums) {
        vector<int> cur;
        backtrack(nums, 0);
        return res;
    }
};
// @lc code=end
