// LeetCode 454. 4Sum II in rust

use super::Solution;
use std::collections::HashMap;

impl Solution {
    pub fn four_sum_count(
        nums1: Vec<i32>,
        nums2: Vec<i32>,
        nums3: Vec<i32>,
        nums4: Vec<i32>,
    ) -> i32 {
        let mut ans = 0;
        let mut sum = HashMap::<i32, i32>::new();
        for num1 in nums1.iter() {
            for num2 in nums2.iter() {
                if let Some(count) = sum.insert(num1 + num2, 1) {
                    sum.insert(num1 + num2, count + 1);
                }
            }
        }
        for num3 in nums3.iter() {
            for num4 in nums4.iter() {
                if let Some(count) = sum.get(&-(num3 + num4)) {
                    ans += count;
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
        let nums1 = vec![1, 2];
        let nums2 = vec![-2, -1];
        let nums3 = vec![-1, 2];
        let nums4 = vec![0, 2];
        let ans = 2;
        assert_eq!(Solution::four_sum_count(nums1, nums2, nums3, nums4), ans);
    }

    #[test]
    fn example2() {
        let nums1 = vec![0];
        let nums2 = vec![0];
        let nums3 = vec![0];
        let nums4 = vec![0];
        let ans = 1;
        assert_eq!(Solution::four_sum_count(nums1, nums2, nums3, nums4), ans);
    }
}
