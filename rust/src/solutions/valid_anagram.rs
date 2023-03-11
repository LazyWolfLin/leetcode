// LeetCode 242. Valid Anagram

use super::Solution;

impl Solution {
    pub fn is_anagram(s: String, t: String) -> bool {
        let mut flag = vec![0; 26];
        for ch in s.bytes() {
            flag[ch as usize - 'a' as usize] += 1;
        }
        for ch in t.bytes() {
            flag[ch as usize - 'a' as usize] -= 1;
        }
        flag.iter().filter(|&x| *x != 0).count() == 0
    }
}

#[cfg(test)]
mod tests {
    use super::Solution;

    #[test]
    fn example1() {
        let s = String::from("anagram");
        let t = String::from("nagaram");
        let ans = true;
        assert_eq!(Solution::is_anagram(s, t), ans);
    }

    #[test]
    fn example2() {
        let s = String::from("rat");
        let t = String::from("car");
        let ans = false;
        assert_eq!(Solution::is_anagram(s, t), ans);
    }
}
