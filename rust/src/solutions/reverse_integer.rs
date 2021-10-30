// LeetCode 7. Reverse Integer in Rust

use super::Solution;

impl Solution {
    pub fn reverse(x: i32) -> i32 {
        let (mut x, mut ans) = (x, 0);
        while x != 0 {
            if ans > std::i32::MAX / 10 || ans < std::i32::MIN / 10 {
                return 0;
            }
            ans *= 10;
            ans += x % 10;
            x /= 10;
        }
        ans
    }
}

#[cfg(test)]
mod tests {
    use super::Solution;

    #[test]
    fn example1() {
        let x = 123;
        let ans = 321;
        assert_eq!(Solution::reverse(x), ans);
    }

    #[test]
    fn example2() {
        let x = -123;
        let ans = -321;
        assert_eq!(Solution::reverse(x), ans);
    }

    #[test]
    fn example3() {
        let x = 120;
        let ans = 21;
        assert_eq!(Solution::reverse(x), ans);
    }

    #[test]
    fn example4() {
        let x = 0;
        let ans = 0;
        assert_eq!(Solution::reverse(x), ans);
    }
}
