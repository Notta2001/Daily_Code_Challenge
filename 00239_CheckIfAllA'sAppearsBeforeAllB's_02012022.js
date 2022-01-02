var checkString = function(s) {
    let appear = false
    for (let i = 0; i < s.length; ++i) {
        if (s[i] === 'a' && appear === true)
            return false
        else if (s[i] === 'b')
            appear = true
    }
    return true
};