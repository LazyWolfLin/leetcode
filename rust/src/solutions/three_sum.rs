// LeetCode 15. 3Sum

use super::Solution;

impl Solution {
    pub fn three_sum(nums: Vec<i32>) -> Vec<Vec<i32>> {
        let mut nums = nums;
        nums.sort();
        let mut ans = Vec::<Vec<i32>>::new();
        for i in 0..nums.len() {
            if i > 0 && nums[i] == nums[i - 1] {
                continue;
            }
            let (mut j, mut k) = (i + 1, nums.len() - 1);
            while j < k {
                let (x, y, z) = (nums[i], nums[j], nums[k]);
                match x + y + z {
                    i32::MIN..=-1i32 => j += 1,
                    0 => {
                        ans.push(vec![x, y, z]);
                        while j < k && y == nums[j] {
                            j += 1;
                        }
                        while j < k && z == nums[k] {
                            k -= 1;
                        }
                    }
                    1i32..=i32::MAX => k -= 1,
                }
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
        let nums = vec![-1, 0, 1, 2, -1, -4];
        let ans = vec![vec![-1, -1, 2], vec![-1, 0, 1]];
        assert_eq!(Solution::three_sum(nums), ans);
    }

    #[test]
    fn example2() {
        let nums = Vec::new();
        let ans = Vec::<Vec<i32>>::new();
        assert_eq!(Solution::three_sum(nums), ans);
    }

    #[test]
    fn example3() {
        let nums = vec![0];
        let ans = Vec::<Vec<i32>>::new();
        assert_eq!(Solution::three_sum(nums), ans);
    }
}
