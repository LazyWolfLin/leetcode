// LeetCode 977. Squares of a Sorted Array in Rust

use super::Solution;

impl Solution {
    pub fn sorted_squares(nums: Vec<i32>) -> Vec<i32> {
        let squares: Vec<i32> = nums.iter().map(|x| x * x).collect();
        let mut ans = Vec::with_capacity(nums.len());
        let (mut l, mut r) = (0, squares.len() - 1);
        while l <= r {
            if squares[l] >= squares[r] {
                ans.push(squares[l]);
                l += 1;
            } else {
                ans.push(squares[r]);
                r -= 1;
            }
        }
        ans.reverse();
        ans
    }
}

#[cfg(test)]
mod tests {
    use super::Solution;

    #[test]
    fn example1() {
        let nums = vec![-4, -1, 0, 3, 10];
        let ans = vec![0, 1, 9, 16, 100];
        assert_eq!(Solution::sorted_squares(nums), ans);
    }

    #[test]
    fn example2() {
        let nums = vec![-7, -3, 2, 3, 11];
        let ans = vec![4, 9, 9, 49, 121];
        assert_eq!(Solution::sorted_squares(nums), ans);
    }
}
