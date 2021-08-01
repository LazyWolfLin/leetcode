// LeetCode 1. Two Sum in Rust

use super::Solution;

impl Solution {
    pub fn two_sum(nums: Vec<i32>, target: i32) -> Vec<i32> {
        use std::collections::HashMap;
        let mut indices: HashMap<i32, i32> = HashMap::new();
        for i in 0..nums.len() {
            if let Some(&indice) = indices.get(&(target - nums[i])) {
                return vec![indice, i as i32];
            } else {
                indices.insert(nums[i], i as i32);
            }
        }
        vec![]
    }
}

#[cfg(test)]
mod tests {
    use super::Solution;

    #[test]
    fn example1() {
        let nums = vec![2, 7, 11, 15];
        let target = 9;
        let ans = vec![0, 1];
        assert_eq!(ans, Solution::two_sum(nums, target));
    }

    #[test]
    fn example2() {
        let nums = vec![3, 2, 4];
        let target = 6;
        let ans = vec![1, 2];
        assert_eq!(ans, Solution::two_sum(nums, target));
    }

    #[test]
    fn example3() {
        let nums = vec![3, 3];
        let target = 6;
        let ans = vec![0, 1];
        assert_eq!(ans, Solution::two_sum(nums, target));
    }
}
