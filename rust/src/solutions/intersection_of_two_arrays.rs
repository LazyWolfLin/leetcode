// LeetCode 349. Intersection of Two Arrays in Rust

use super::Solution;
use std::collections::HashSet;

impl Solution {
    pub fn intersection(nums1: Vec<i32>, nums2: Vec<i32>) -> Vec<i32> {
        let mut ans = Vec::new();
        let mut flag = HashSet::new();
        for num in nums1 {
            flag.insert(num);
        }
        for num in nums2.iter() {
            if flag.get(num).is_some() {
                ans.push(*num);
                flag.remove(num);
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
        let nums1 = vec![1, 2, 2, 1];
        let nums2 = vec![2, 2];
        let ans = vec![2];
        let mut nums = Solution::intersection(nums1, nums2);
        nums.sort();
        assert_eq!(nums, ans);
    }

    #[test]
    fn example2() {
        let nums1 = vec![4, 9, 5];
        let nums2 = vec![9, 4, 9, 8, 4];
        let ans = vec![4, 9];
        let mut nums = Solution::intersection(nums1, nums2);
        nums.sort();
        assert_eq!(nums, ans);
    }
}
