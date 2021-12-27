// The complement of an integer is the integer you get when you flip all the 0 and 1 to 1 and 0 in its binary form
var findComplement = function(num) {
    var a = 0
    while(a < num) {
        a = a * 2 + 1
    }
    return a - num
};