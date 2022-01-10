var reverseWords = function(s) {
    const _reverseSingleWord = (word) => {
        const arr = Array.from(word)
        let i = 0, j = arr.length - 1
        while (i < j) {
           [arr[i++], arr[j--]] = [arr[j], arr[i]]
        }
        return arr.join('')
    }
    
    const words = s.split(' ')
    const reversed = []
    for (const word of words) {
        reversed.push(_reverseSingleWord(word))
    }
    return reversed.join(' ')
};