// LeetCode 18. 4Sum in Rust

use super::Solution;

impl Solution {
    pub fn four_sum(nums: Vec<i32>, target: i32) -> Vec<Vec<i32>> {
        let mut nums = nums;
        nums.sort();
        let mut ans = Vec::new();
        for i in 0..nums.len() {
            if i > 0 && nums[i] == nums[i - 1] {
                continue;
            }
            for j in i + 1..nums.len() {
                if j > i + 1 && nums[j] == nums[j - 1] {
                    continue;
                }
                let (mut k, mut l) = (j + 1, nums.len() - 1);
                while k < l {
                    if nums[i] + nums[j] + nums[k] + nums[l] == target {
                        ans.push(vec![nums[i], nums[j], nums[k], nums[l]]);
                        k += 1;
                        l -= 1;
                        while k < l && nums[k] == nums[k - 1] {
                            k += 1;
                        }
                        while k < l && nums[l] == nums[l + 1] {
                            l -= 1;
                        }
                    } else if nums[i] + nums[j] + nums[k] + nums[l] > target {
                        l -= 1;
                    } else {
                        k += 1;
                    }
                }
            }
        }
        ans
    }
}

#[cfg(test)]
mod tests {
    use super::Solution;

    #[test]
    fn example1() {
        let nums = vec![1, 0, -1, 0, -2, 2];
        let target = 0;
        let ans = vec![vec![-2, -1, 1, 2], vec![-2, 0, 0, 2], vec![-1, 0, 0, 1]];
        assert_eq!(Solution::four_sum(nums, target), ans);
    }

    #[test]
    fn example2() {
        let nums = vec![2, 2, 2, 2];
        let target = 8;
        let ans = vec![vec![2, 2, 2, 2]];
        assert_eq!(Solution::four_sum(nums, target), ans);
    }
}
