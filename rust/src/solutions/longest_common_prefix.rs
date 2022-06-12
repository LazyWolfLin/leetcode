// LeetCode 14. Longest Common Prefix in Rust

use super::Solution;

impl Solution {
    pub fn longest_common_prefix(strs: Vec<String>) -> String {
        if strs.len() == 0 {
            return String::new();
        }

        let mut ans = String::new();
        for ch in strs[0].chars() {
            for str in &strs {
                if ch != str.chars().nth(ans.len()).unwrap_or_default() {
                    return ans;
                }
            }
            ans.push(ch)
        }
        ans
    }
}

#[cfg(test)]
mod tests {
    use super::Solution;

    #[test]
    fn example1() {
        let strs = vec![
            "flower".to_string(),
            "flow".to_string(),
            "flight".to_string(),
        ];
        let ans = String::from("fl");
        assert_eq!(Solution::longest_common_prefix(strs), ans);
    }

    #[test]
    fn example2() {
        let strs = vec!["dog".to_string(), "racecar".to_string(), "car".to_string()];
        let ans = String::from("");
        assert_eq!(Solution::longest_common_prefix(strs), ans);
    }
}
