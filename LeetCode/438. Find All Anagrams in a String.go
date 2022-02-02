func findAnagrams(s string, p string) []int {
    var anagramIndexes []int
    targetSize := len(p)
    
    if targetSize > len(s){
        return anagramIndexes
    }
    
    targetMap := GetAlphabetMap(p)
    sampleMap := GetAlphabetMap(s[:targetSize])
    
    if Equal(targetMap, sampleMap){
        anagramIndexes = append(anagramIndexes, 0)
    }
    
    for i:=targetSize; i< len(s);i++{
        pastChar, newChar := s[i-len(p)], s[i]
        sampleMap[pastChar - 'a']--
        sampleMap[newChar - 'a']++
        if Equal(targetMap, sampleMap){
            anagramIndexes = append(anagramIndexes, i - targetSize + 1)
        }
        fmt.Println(string(newChar))
    }
    
    return anagramIndexes
}

func GetAlphabetMap(str string) []int{
    alphaMap := make([]int, 26)
    for _, ch := range str{
        alphaMap[ch - 'a']++
    }
    return alphaMap
}

func Equal(a, b []int) bool {
    for i, v := range a {
        if v != b[i] {
            return false
        }
    }
    return true
}
