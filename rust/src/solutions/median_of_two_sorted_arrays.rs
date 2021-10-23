// LeetCode 4. Median of Two Sorted Arrays in Rust

use super::Solution;

impl Solution {
    pub fn find_median_sorted_arrays(nums1: Vec<i32>, nums2: Vec<i32>) -> f64 {
        let (nums1, nums2) = if nums1.len() > nums2.len() {
            (nums2, nums1)
        } else {
            (nums1, nums2)
        };
        let m = nums1.len();
        let n = nums2.len();
        let half = (m + n + 1) / 2;
        let mut l = 0;
        let mut r = m + 1;
        let mut i = 0;
        let mut j = 0;
        while l < r {
            i = (l + r) / 2;
            j = half - i;
            if i > 0 && nums1[i - 1] > nums2[j] {
                r = i;
            } else if i < m && nums1[i] < nums2[j - 1] {
                l = i;
            } else {
                break;
            }
        }
        let mut ans = if i == 0 {
            nums2[j - 1]
        } else if j == 0 {
            nums1[i - 1]
        } else {
            std::cmp::max(nums1[i - 1], nums2[j - 1])
        };
        if (m + n) % 2 == 0 {
            if i == m {
                ans += nums2[j];
            } else if j == n {
                ans += nums1[i];
            } else {
                ans += std::cmp::min(nums1[i], nums2[j]);
            }
        }else{
            ans += ans;
        }
        ans as f64 / 2f64
    }
}

#[cfg(test)]
mod tests {
    use super::Solution;

    #[test]
    fn example1() {
        let nums1 = vec![1, 3];
        let nums2 = vec![2];
        let ans = 2.0;
        assert_eq!(Solution::find_median_sorted_arrays(nums1, nums2), ans);
    }

    #[test]
    fn example2() {
        let nums1 = vec![1, 2];
        let nums2 = vec![3, 4];
        let ans = 2.5;
        assert_eq!(Solution::find_median_sorted_arrays(nums1, nums2), ans);
    }

    #[test]
    fn example3() {
        let nums1 = vec![0, 0];
        let nums2 = vec![0, 0];
        let ans = 0.0;
        assert_eq!(Solution::find_median_sorted_arrays(nums1, nums2), ans);
    }

    #[test]
    fn example4() {
        let nums1 = vec![];
        let nums2 = vec![1];
        let ans = 1.0;
        assert_eq!(Solution::find_median_sorted_arrays(nums1, nums2), ans);
    }

    #[test]
    fn example5() {
        let nums1 = vec![2];
        let nums2 = vec![];
        let ans = 2.0;
        assert_eq!(Solution::find_median_sorted_arrays(nums1, nums2), ans);
    }
}
