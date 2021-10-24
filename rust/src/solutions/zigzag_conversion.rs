// LeetCode 6. ZigZag Conversion in Rust

use super::Solution;

impl Solution {
    pub fn convert(s: String, num_rows: i32) -> String {
        let num_rows = num_rows as usize;
        if num_rows == 1 || num_rows > s.len() {
            return s;
        }
        let t = s.as_bytes();
        let mut ans = String::with_capacity(t.len());
        for i in 0..num_rows {
            let key = (num_rows - i - 1) * 2;
            let mut j = i;
            while j < t.len() {
                ans.push(t[j] as char);
                if i != 0 && key != 0 && j + key < t.len() {
                    ans.push(t[j + key] as char);
                }
                j += key + 2 * i;
            }
        }
        ans
    }
}

#[cfg(test)]
mod tests {
    use super::Solution;

    #[test]
    fn example1() {
        let s = String::from("PAYPALISHIRING");
        let ans = String::from("PAHNAPLSIIGYIR");
        let num_rows = 3;
        assert_eq!(Solution::convert(s, num_rows), ans);
    }

    #[test]
    fn example2() {
        let s = String::from("PAYPALISHIRING");
        let ans = String::from("PINALSIGYAHRPI");
        let num_rows = 4;
        assert_eq!(Solution::convert(s, num_rows), ans);
    }

    #[test]
    fn example3() {
        let s = String::from("A");
        let ans = String::from("A");
        let num_rows = 1;
        assert_eq!(Solution::convert(s, num_rows), ans);
    }
}
