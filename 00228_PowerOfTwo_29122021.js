var isPowerOfTwo = function(n) {
    let max = 31
    let initialValue = 1
    for (var i = 0; i < max; ++i) {
        if (initialValue === n) 
            return true;
        initialValue = initialValue << 1
    }
    return false
}