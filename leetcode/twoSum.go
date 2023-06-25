package main

import (
    "fmt"
)

func twoSum(nums []int, target int) []int {
    var numMap = make(map[int]int, len(nums))
    for idx, value := range nums {
        left := target - value
        if _, ok := numMap[left]; ok {
            return []int{idx, numMap[left]}
        } else {
            numMap[value] = idx
        }
    }
    return []int{}
}


func main() {
    var input = []int{1, 3, 4, 5}
    fmt.Println(twoSum(input, 4))
}

