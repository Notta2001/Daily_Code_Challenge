var myAtoi = function(s) {
    let finalNumber = '';
    let isPositive = true;
    let isLeadingWhiteSpaces = true;
    let seenSign = false;
    let seenNumbers = false;
    
    for (let x = 0; x < s.length; x++) {
        const char = s[x];
        
        if (isNumber(char)) { // Always welcome numbers
            finalNumber += char;
            seenNumbers = true;
        }
        else {
            if (seenNumbers) // If seeing ANY none numerics AFTER seeing number, stop
                break;
            
            // BEFORE seeing number...
            if (char === ' ' && isLeadingWhiteSpaces) // LEADING white spaces, continue...
                continue;
            else if (isLeadingWhiteSpaces) // None LEADING white space character encountered, white spaces no longer welcome
                isLeadingWhiteSpaces = false;
            
            // Welcome signs if you haven't seen before
            if (char === '-' && !seenSign) {
                isPositive = false;
                seenSign = true;
                continue;
            }
            else if (char === '+' && !seenSign) {
                seenSign = true;
                continue;
            }
            
            // BEFORE seeing any numbers, 
            // If we see ANY characters that aren't LEADING white spaces, or first +/- sign occurances
            // Simply stop right there.
            break;
        }
    }
    
    const returnNumber = (isPositive ? Number(finalNumber) : -Number(finalNumber));
    
    if (returnNumber <= -Math.pow(2, 31))
        return -Math.pow(2, 31);
    
    if (returnNumber >= Math.pow(2, 31) - 1)
        return Math.pow(2, 31) - 1;
    
    return returnNumber
};
    

function isNumber(char) {
    return !isNaN(parseInt(char));
}

// https://leetcode.com/problems/string-to-integer-atoi/submissions/