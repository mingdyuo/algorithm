func findPairs(nums []int, k int) int {
    sortedMap, unique := getSortedMap(nums)
    result := 0
    
    if k == 0 {
        for _, counts := range sortedMap{
            if counts > 1 {
                result += 1
            }
        }    
        return result
    }
    
    
    for left, right := 0, 1; left <= right && right < len(unique);{
        diff := unique[right] - unique[left]
        if diff == k {
            result += 1
            left += 1
            right += 1
        } else if diff < k {
            right += 1
        } else if diff > k {
            left += 1
        }
    }
    return result
}

func getSortedMap(nums []int) (map[int]int, []int) {
    sortedMap := map[int]int{}
    for _, num := range nums{
        sortedMap[num]+=1
    }
    unique := make([]int, 0, len(sortedMap))
    for num, _ := range sortedMap{
        unique = append(unique, num)
    }
    sort.Ints(unique)
    return sortedMap, unique
}

func min(a, b int)int{
    if a < b {
        return a
    }
    return b
}

