// LeetCode 1. Two Sum in Go

package solutions

import (
	"reflect"
	"testing"
)

func twoSum(nums []int, target int) []int {
	indices := make(map[int]int)
	for i, num := range nums {
		if indice, ok := indices[target-num]; !ok {
			indices[num] = i
		} else {
			return []int{indice, i}
		}
	}
	return nil
}

func TestTwoSum(t *testing.T) {
	var tests = []struct {
		nums   []int
		target int
		ans    []int
	}{
		{[]int{2, 7, 11, 15}, 9, []int{0, 1}},
		{[]int{3, 2, 4}, 6, []int{1, 2}},
		{[]int{3, 3}, 6, []int{0, 1}},
	}

	for _, test := range tests {
		if !reflect.DeepEqual(twoSum(test.nums, test.target), test.ans) {
			t.Errorf("twoSum(%v, %d) != %v", test.nums, test.target, test.ans)
		}
	}
}
