// LeetCode 9. Palindrome Number

use super::Solution;

impl Solution {
    pub fn is_palindrome(x: i32) -> bool {
        let mut y = 0;
        let mut tmp = x as i64;
        while tmp > 0 {
            y *= 10;
            y += tmp % 10;
            tmp /= 10;
        }
        x as i64 == y
    }
}

#[cfg(test)]
mod tests {
    use super::Solution;

    #[test]
    fn example1() {
        let x = 121;
        let ans = true;
        assert_eq!(Solution::is_palindrome(x), ans);
    }

    #[test]
    fn example2() {
        let x = 1121;
        let ans = false;
        assert_eq!(Solution::is_palindrome(x), ans);
    }

    #[test]
    fn example3() {
        let x = 10;
        let ans = false;
        assert_eq!(Solution::is_palindrome(x), ans);
    }

    #[test]
    fn example4() {
        let x = -101;
        let ans = false;
        assert_eq!(Solution::is_palindrome(x), ans)
    }
}
