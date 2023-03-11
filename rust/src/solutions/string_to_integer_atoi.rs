// LeetCode 8. String to Integer (atoi)

use super::Solution;

impl Solution {
    pub fn my_atoi(s: String) -> i32 {
        let mut chars = s.trim_start().bytes().peekable();
        let positive = match chars.peek() {
            Some(b'+') => {
                chars.next();
                true
            }
            Some(b'-') => {
                chars.next();
                false
            }
            _ => true,
        };
        let mut ans: i32 = 0;
        for ch in chars {
            if ch.is_ascii_digit() {
                let bit = ch - b'0';
                ans = ans.saturating_mul(10);
                ans = if positive {
                    ans.saturating_add(bit.into())
                } else {
                    ans.saturating_sub(bit.into())
                };
            } else {
                break;
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
