// LeetCode 12. Integer to Roman

use super::Solution;

impl Solution {
    pub fn int_to_roman(num: i32) -> String {
        let table = [
            ["", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX"],
            ["", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC"],
            ["", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM"],
            ["", "M", "MM", "MMM", "", "", "", "", "", ""],
        ];
        let mut ans = String::new();
        let (mut num, mut bit) = (num, 0);
        while num > 0 {
            ans = String::from(table[bit][(num % 10) as usize]) + &ans;
            bit += 1;
            num = num / 10;
        }
        ans
    }
}

#[cfg(test)]
mod tests {
    use super::Solution;

    #[test]
    fn example1() {
        let nums = 3;
        let ans = String::from("III");
        assert_eq!(Solution::int_to_roman(nums), ans);
    }

    #[test]
    fn example2() {
        let nums = 4;
        let ans = String::from("IV");
        assert_eq!(Solution::int_to_roman(nums), ans);
    }

    #[test]
    fn example3() {
        let nums = 9;
        let ans = String::from("IX");
        assert_eq!(Solution::int_to_roman(nums), ans);
    }

    #[test]
    fn example4() {
        let nums = 58;
        let ans = String::from("LVIII");
        assert_eq!(Solution::int_to_roman(nums), ans);
    }

    #[test]
    fn example5() {
        let nums = 1994;
        let ans = String::from("MCMXCIV");
        assert_eq!(Solution::int_to_roman(nums), ans);
    }
}
