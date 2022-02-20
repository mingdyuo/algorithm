func singleNumber(nums []int) int {
    numMap := make(map[int]struct{})
    result := 0
    for _, num := range nums {
        if _, exist := numMap[num]; exist {
            result -= num
        } else {
            numMap[num] = struct{}{}
            result += num
        }
    }
    return result
} 