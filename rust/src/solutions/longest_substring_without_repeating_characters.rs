// LeetCode 3. Longest Substring Without Repeating Characters

use super::Solution;

impl Solution {
    pub fn length_of_longest_substring(s: String) -> i32 {
        let mut letter = [0; 128];
        let mut l = 0;
        let mut ans = 0;
        for (r, ch) in s.chars().enumerate() {
            l = std::cmp::max(l, letter[ch as usize]);
            ans = std::cmp::max(ans, r - l + 1);
            letter[ch as usize] = r + 1;
        }
        ans as i32
    }
}

#[cfg(test)]
mod tests {
    use super::Solution;

    #[test]
    fn example1() {
        let s: String = "abcabcbb".into();
        let ans: i32 = 3;
        assert_eq!(Solution::length_of_longest_substring(s), ans);
    }

    #[test]
    fn example2() {
        let s: String = "bbbbb".into();
        let ans: i32 = 1;
        assert_eq!(Solution::length_of_longest_substring(s), ans);
    }

    #[test]
    fn example3() {
        let s: String = "pwwkew".into();
        let ans: i32 = 3;
        assert_eq!(Solution::length_of_longest_substring(s), ans);
    }

    #[test]
    fn example4() {
        let s: String = "".into();
        let ans: i32 = 0;
        assert_eq!(Solution::length_of_longest_substring(s), ans);
    }
}
