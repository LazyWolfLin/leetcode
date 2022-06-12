// LeetCode 17. Letter Combinations of a Phone Number in Rust

use super::Solution;

impl Solution {
    pub fn letter_combinations(digits: String) -> Vec<String> {
        let letters = vec![
            "", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz",
        ];
        let mut ans = Vec::new();
        if digits.len() == 0 {
            return ans;
        }
        ans.push(String::from(""));
        for digit in digits.as_bytes() {
            let mut tmp = Vec::new();
            let letter = letters[(digit - b'0') as usize];
            for string in &ans {
                for ch in letter.chars() {
                    tmp.push(string.to_owned() + &ch.to_string());
                }
            }
            ans = tmp;
        }
        ans
    }
}

#[cfg(test)]
mod tests {
    use super::Solution;

    #[test]
    fn example1() {
        let digits = String::from("23");
        let ans: Vec<String> = vec![
            "ad".to_string(),
            "ae".to_string(),
            "af".to_string(),
            "bd".to_string(),
            "be".to_string(),
            "bf".to_string(),
            "cd".to_string(),
            "ce".to_string(),
            "cf".to_string(),
        ];
        assert_eq!(Solution::letter_combinations(digits), ans);
    }

    #[test]
    fn example2() {
        let digits = String::from("");
        let ans: Vec<String> = vec![];
        assert_eq!(Solution::letter_combinations(digits), ans);
    }

    #[test]
    fn example3() {
        let digits = String::from("2");
        let ans: Vec<String> = vec!["a".to_string(), "b".to_string(), "c".to_string()];
        assert_eq!(Solution::letter_combinations(digits), ans);
    }
}
