func searchInsert(nums []int, target int) int {
    mid, found := bsearch(nums, target)
    if found {
        return mid
    } 
    
    if nums[mid] < target {
        return mid + 1
    } 
    return mid 
}


func bsearch(nums []int, target int) (int, bool) {
    var mid, high, low int
    for low, high = 0, len(nums)-1; low<=high;{
         mid = (low + high)/2
         if nums[mid] == target {
            return mid, true
         } else if nums[mid] > target {
             high = mid - 1
         } else {
             low = mid + 1
         }
    }
    return mid, false
}

