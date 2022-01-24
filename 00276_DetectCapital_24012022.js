var detectCapitalUse = function(word) {
    if (word === word.toUpperCase()) return true;
    if (word === word.toLowerCase()) return true;
    
    if (word[0] === word[0].toUpperCase()) {
        let leftOutStr = word.slice(1);
        if (leftOutStr === leftOutStr.toLowerCase()) return true;
    }
    
    return false;
};
// https://leetcode.com/problems/detect-capital/submissions/