// LeetCode 20. Valid Parentheses

use super::Solution;

impl Solution {
    pub fn is_valid(s: String) -> bool {
        let mut stack = Vec::new();
        for ch in s.chars() {
            match ch {
                '(' | '{' | '[' => {
                    stack.push(ch);
                }
                ')' if stack.last() == Some(&'(') => {
                    stack.pop();
                }
                '}' if stack.last() == Some(&'{') => {
                    stack.pop();
                }
                ']' if stack.last() == Some(&'[') => {
                    stack.pop();
                }
                _ => return false,
            }
        }
        stack.is_empty()
    }
}

#[cfg(test)]
mod tests {
    use super::Solution;

    #[test]
    fn example1() {
        let s = String::from("()");
        let ans = true;
        assert_eq!(Solution::is_valid(s), ans);
    }

    #[test]
    fn example2() {
        let s = String::from("()[]{}");
        let ans = true;
        assert_eq!(Solution::is_valid(s), ans);
    }

    #[test]
    fn example3() {
        let s = String::from("(]");
        let ans = false;
        assert_eq!(Solution::is_valid(s), ans);
    }

    #[test]
    fn example4() {
        let s = String::from("([)]");
        let ans = false;
        assert_eq!(Solution::is_valid(s), ans);
    }

    #[test]
    fn example5() {
        let s = String::from("{[]}");
        let ans = true;
        assert_eq!(Solution::is_valid(s), ans);
    }
}
