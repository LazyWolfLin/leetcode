// LeetCode 5. Longest Palindromic Substring in Rust
// Manacher Algorithms

use super::Solution;

impl Solution {
    pub fn longest_palindrome(s: String) -> String {
        let mut t = vec!['#'; s.len() * 2 + 3];
        *t.first_mut().unwrap()= '$';
        for (i, ch) in s.chars().enumerate() {
            t[2 * i + 2] = ch;
        }
        *t.last_mut().unwrap() = '!';
        let mut f = vec![1; t.len()];
        let (mut current_center, mut current_right, mut ans_len, mut ans_center) = (0, 0, 0, 0);
        for i in 1..t.len() - 1 {
            if current_right > i {
                f[i] = std::cmp::min(f[2 * current_center - i], current_right - i);
            }
            while t[i + f[i]] == t[i - f[i]] {
                f[i] += 1;
            }
            if i + f[i] > current_right {
                current_right = i + f[i];
                current_center = i;
            }
            if f[i] > ans_len {
                ans_len = f[i];
                ans_center = i;
            }
        }
        String::from(&s[(ans_center - ans_len) / 2..(ans_center + ans_len) / 2 - 1])
    }
}

#[cfg(test)]
mod tests {
    use super::Solution;

    #[test]
    fn example1() {
        let s = String::from("babad");
        let ans = String::from("bab");
        assert_eq!(Solution::longest_palindrome(s), ans);
    }

    #[test]
    fn example2() {
        let s = String::from("cbbd");
        let ans = String::from("bb");
        assert_eq!(Solution::longest_palindrome(s), ans);
    }

    #[test]
    fn example3() {
        let s = String::from("a");
        let ans = String::from("a");
        assert_eq!(Solution::longest_palindrome(s), ans);
    }

    #[test]
    fn example4() {
        let s = String::from("ac");
        let ans = String::from("a");
        assert_eq!(Solution::longest_palindrome(s), ans);
    }
}
