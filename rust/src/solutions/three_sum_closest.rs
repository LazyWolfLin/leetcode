// LeetCode 16. 3Sum Closest

use super::Solution;

impl Solution {
    pub fn three_sum_closest(nums: Vec<i32>, target: i32) -> i32 {
        let mut nums = nums;
        nums.sort();
        let mut ans = nums[0] + nums[1] + nums[2];
        for i in 0..nums.len() {
            let (mut j, mut k) = (i + 1, nums.len() - 1);
            while j < k {
                let tmp = nums[i] + nums[j] + nums[k];
                if tmp == target {
                    return tmp;
                }
                if (ans - target).abs() > (tmp - target).abs() {
                    ans = tmp;
                }
                if tmp > target {
                    k -= 1;
                } else {
                    j += 1;
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
        let nums = vec![-1, 2, 1, -4];
        let (target, ans) = (1, 2);
        assert_eq!(Solution::three_sum_closest(nums, target), ans);
    }

    #[test]
    fn example2() {
        let nums = vec![0, 0, 0];
        let (target, ans) = (1, 0);
        assert_eq!(Solution::three_sum_closest(nums, target), ans);
    }
}
