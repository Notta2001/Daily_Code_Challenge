var numPairsDivisibleBy60 = (time) => {
    let store = []
    let mod = 0
    let pairs = 0

    time.forEach(duration => {
        mod = duration % 60
        if (mod === 0) mod = 60
        if (store[60-mod]) pairs += store[60-mod]
        mod = duration % 60
        if (!store[mod]) {
            store[mod] = 1
        } else {
            store[mod] += 1
        }
    })
    return pairs
}

// https://leetcode.com/problems/pairs-of-songs-with-total-durations-divisible-by-60/discuss/1160442/javascript-two-sum