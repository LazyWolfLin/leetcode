// LeetCode 704. Binary Search

use super::Solution;

impl Solution {
    pub fn search(nums: Vec<i32>, target: i32) -> i32 {
        let mut ans = -1;
        let (mut l, mut r) = (0, nums.len());
        while l < r {
            let mid = l + (r - l) / 2;
            if nums[mid] == target {
                ans = mid as i32;
                break;
            } else if nums[mid] < target {
                l = mid + 1;
            } else {
                r = mid;
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
        let nums = vec![-1, 0, 3, 5, 9, 12];
        let target = 9;
        let ans = 4;
        assert_eq!(Solution::search(nums, target), ans);
    }

    #[test]
    fn example2() {
        let nums = vec![-1, 0, 3, 5, 9, 12];
        let target = 2;
        let ans = -1;
        assert_eq!(Solution::search(nums, target), ans);
    }
}
