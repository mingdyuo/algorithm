func addDigitsRecur(num int) int {
    if num < 10 {
        return num
    }
    result := 0
    for num > 0 {
        result += num % 10
        num = num / 10
    }
    return addDigitsRecur(result)
}

func addDigits(num int) int {
    return addDigitsRecur(num)
}