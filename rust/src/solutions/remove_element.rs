// LeetCode 27. Remove Element in Rust

use super::Solution;

impl Solution {
    pub fn remove_element(nums: &mut Vec<i32>, val: i32) -> i32 {
        for index in (0..nums.len()).rev() {
            if nums[index] == val {
                nums.swap_remove(index);
            }
        }
        nums.len() as i32
    }
}

#[cfg(test)]
mod tests {
    use super::Solution;

    #[test]
    fn example1() {
        let mut nums = vec![3, 2, 2, 3];
        let val = 3;
        let ans = 2;
        assert_eq!(Solution::remove_element(&mut nums, val), ans);
        nums.sort();
        assert_eq!(nums, [2, 2]);
    }

    #[test]
    fn example2() {
        let mut nums = vec![0, 1, 2, 2, 3, 0, 4, 2];
        let val = 2;
        let ans = 5;
        assert_eq!(Solution::remove_element(&mut nums, val), ans);
        nums.sort();
        assert_eq!(nums, [0, 0, 1, 3, 4]);
    }
}
