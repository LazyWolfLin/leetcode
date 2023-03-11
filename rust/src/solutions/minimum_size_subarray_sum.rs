// LeetCode 209. Minimum Size Subarray Sum

use super::Solution;

impl Solution {
    pub fn min_sub_array_len(target: i32, nums: Vec<i32>) -> i32 {
        let (mut ans, mut sum) = (nums.len() + 1, 0);
        let mut l = 0;
        for (r, num) in nums.iter().enumerate() {
            sum += num;
            while sum >= target {
                ans = std::cmp::min(r - l + 1, ans);
                sum -= nums[l];
                l += 1;
            }
        }
        if ans > nums.len() {
            0
        } else {
            ans as i32
        }
    }
}

#[cfg(test)]
mod tests {
    use super::Solution;

    #[test]
    fn example1() {
        let nums = vec![2, 3, 1, 2, 4, 3];
        let target = 7;
        let ans = 2;
        assert_eq!(Solution::min_sub_array_len(target, nums), ans);
    }

    #[test]
    fn example2() {
        let nums = vec![1, 4, 4];
        let target = 4;
        let ans = 1;
        assert_eq!(Solution::min_sub_array_len(target, nums), ans);
    }

    #[test]
    fn example3() {
        let nums = vec![1, 1, 1, 1, 1, 1, 1, 1];
        let target = 11;
        let ans = 0;
        assert_eq!(Solution::min_sub_array_len(target, nums), ans);
    }
}
