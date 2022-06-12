// LeetCode 13. Roman to Integer in Rust

use super::Solution;
use std::collections::HashMap;

impl Solution {
    pub fn roman_to_int(s: String) -> i32 {
        let value_map: HashMap<char, i32> = vec![
            ('I', 1),
            ('V', 5),
            ('X', 10),
            ('L', 50),
            ('C', 100),
            ('D', 500),
            ('M', 1000),
        ]
        .into_iter()
        .collect();

        let mut ans = 0;
        let mut last = 0;
        for ch in s.chars().rev() {
            let curr = value_map[&ch];
            if curr < last {
                ans -= curr;
            } else {
                ans += curr;
            }
            last = curr
        }
        ans
    }
}

#[cfg(test)]
mod tests {
    use super::Solution;

    #[test]
    fn example1() {
        let s = String::from("III");
        let ans = 3;
        assert_eq!(Solution::roman_to_int(s), ans);
    }

    #[test]
    fn example2() {
        let s = String::from("IV");
        let ans = 4;
        assert_eq!(Solution::roman_to_int(s), ans);
    }

    #[test]
    fn example3() {
        let s = String::from("IX");
        let ans = 9;
        assert_eq!(Solution::roman_to_int(s), ans);
    }

    #[test]
    fn example4() {
        let s = String::from("LVIII");
        let ans = 58;
        assert_eq!(Solution::roman_to_int(s), ans);
    }

    #[test]
    fn example5() {
        let s = String::from("MCMXCIV");
        let ans = 1994;
        assert_eq!(Solution::roman_to_int(s), ans);
    }
}
