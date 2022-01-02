var numberOfBeams = function(bank) {
    let lastDevices = 0
    let currDevices = 0
    let m = bank.length
    let n = bank[0].length
    let answer = 0
    
    for (let i = 0; i < m; ++i) {
        for (let j = 0; j < n; ++j) {
            if(bank[i][j] === '1')
                currDevices = currDevices + 1
        }
        if(currDevices > 0) {
            answer = answer + currDevices * lastDevices
            lastDevices = currDevices
        }
        currDevices = 0    
    }
    
    return answer
};