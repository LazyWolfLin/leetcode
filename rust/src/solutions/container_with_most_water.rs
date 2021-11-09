// LeetCode 11. Container With Most Water in Rust

use super::Solution;

impl Solution {
    pub fn max_area(height: Vec<i32>) -> i32 {
        let (mut l, mut r, mut ans) = (0, height.len() - 1, 0);
        while l < r {
            let low = height[l].min(height[r]);
            let width = (r - l) as i32;
            ans = ans.max(width * low);
            while l < r && height[l] <= low {
                l += 1;
            }
            while l < r && height[r] <= low {
                r -= 1;
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
        let height = vec![1, 8, 6, 2, 5, 4, 8, 3, 7];
        let ans = 49;
        assert_eq!(Solution::max_area(height), ans);
    }

    #[test]
    fn example2() {
        let height = vec![1, 1];
        let ans = 1;
        assert_eq!(Solution::max_area(height), ans);
    }

    #[test]
    fn example3() {
        let height = vec![4, 3, 2, 1, 4];
        let ans = 16;
        assert_eq!(Solution::max_area(height), ans);
    }

    #[test]
    fn example4() {
        let height = vec![1, 2, 1];
        let ans = 2;
        assert_eq!(Solution::max_area(height), ans);
    }
}
