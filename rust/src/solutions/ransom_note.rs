// LeetCode 383. Ransom Note

use super::Solution;

impl Solution {
    pub fn can_construct(ransom_note: String, magazine: String) -> bool {
        let mut flag = vec![0; 26];
        for ch in ransom_note.bytes() {
            flag[ch as usize - 'a' as usize] += 1;
        }
        for ch in magazine.bytes() {
            flag[ch as usize - 'a' as usize] -= 1;
        }
        flag.iter().filter(|&x| *x > 0).count() == 0
    }
}

#[cfg(test)]
mod tests {
    use super::Solution;

    #[test]
    fn example1() {
        let (ransom_note, magazine) = (String::from("a"), String::from("b"));
        let ans = false;
        assert_eq!(Solution::can_construct(ransom_note, magazine), ans);
    }

    #[test]
    fn example2() {
        let (ransom_note, magazine) = (String::from("aa"), String::from("ab"));
        let ans = false;
        assert_eq!(Solution::can_construct(ransom_note, magazine), ans);
    }

    #[test]
    fn example3() {
        let (ransom_note, magazine) = (String::from("aa"), String::from("aab"));
        let ans = true;
        assert_eq!(Solution::can_construct(ransom_note, magazine), ans);
    }
}
