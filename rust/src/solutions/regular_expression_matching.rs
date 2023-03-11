// LeetCode 10. Regular Expression Matching

use super::Solution;

impl Solution {
    pub fn is_match(s: String, p: String) -> bool {
        let (s, p) = (s.as_bytes(), p.as_bytes());
        let mut dp = vec![vec![false; p.len() + 1]; s.len() + 1];
        dp[s.len()][p.len()] = true;
        for i in (0..s.len() + 1).rev() {
            for j in (0..p.len()).rev() {
                let matched = i < s.len() && (p[j] == s[i] || p[j] == b'.');
                if j + 1 < p.len() && p[j + 1] == b'*' {
                    dp[i][j] = dp[i][j + 2] || (matched && dp[i + 1][j]);
                } else {
                    dp[i][j] = matched && dp[i + 1][j + 1];
                }
            }
        }
        dp[0][0]
    }
}

#[cfg(test)]
mod tests {
    use super::Solution;

    #[test]
    fn example1() {
        let (s, p) = (String::from("aa"), String::from("a"));
        let ans = false;
        assert_eq!(Solution::is_match(s, p), ans);
    }

    #[test]
    fn example2() {
        let (s, p) = (String::from("aa"), String::from("a*"));
        let ans = true;
        assert_eq!(Solution::is_match(s, p), ans);
    }

    #[test]
    fn example3() {
        let (s, p) = (String::from("ab"), String::from(".*"));
        let ans = true;
        assert_eq!(Solution::is_match(s, p), ans);
    }

    #[test]
    fn example4() {
        let (s, p) = (String::from("aab"), String::from("c*a*b"));
        let ans = true;
        assert_eq!(Solution::is_match(s, p), ans);
    }

    #[test]
    fn example5() {
        let (s, p) = (String::from("mississippi"), String::from("mis*is*p*."));
        let ans = false;
        assert_eq!(Solution::is_match(s, p), ans);
    }
}
