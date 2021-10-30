// LeetCode 8. String to Integer (atoi) in Rust

use super::Solution;

impl Solution {
    pub fn my_atoi(s: String) -> i32 {
        let mut chars = s.trim_start().chars().peekable();
        let positive = match chars.peek() {
            Some('+') => {
                chars.next();
                true
            }
            Some('-') => {
                chars.next();
                false
            }
            _ => true,
        };
        let mut ans: i64 = 0;
        for ch in chars {
            ans = match ch.to_digit(10) {
                Some(bit) if positive => ans * 10 + bit as i64,
                Some(d) => ans * 10 - d as i64,
                _ => break,
            };
            if ans > i32::MAX.into() {
                ans = i32::MAX as i64;
            }
            if ans < i32::MIN.into() {
                ans = i32::MIN as i64;
            }
        }
        ans as i32
    }
}

#[cfg(test)]
mod tests {
    use super::Solution;

    #[test]
    fn example1() {
        let s = String::from("42");
        let ans = 42;
        assert_eq!(Solution::my_atoi(s), ans);
    }

    #[test]
    fn example2() {
        let s = String::from("-42");
        let ans = -42;
        assert_eq!(Solution::my_atoi(s), ans);
    }

    #[test]
    fn example3() {
        let s = String::from("4193 with words");
        let ans = 4193;
        assert_eq!(Solution::my_atoi(s), ans);
    }

    #[test]
    fn example4() {
        let s = String::from("words and 987");
        let ans = 0;
        assert_eq!(Solution::my_atoi(s), ans);
    }

    #[test]
    fn example5() {
        let s = String::from("-91283472332");
        let ans = -2147483648;
        assert_eq!(Solution::my_atoi(s), ans);
    }
}
