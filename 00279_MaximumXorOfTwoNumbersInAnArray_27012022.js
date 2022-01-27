const invert = ch => {
    return ch === '0' ? '1' : '0'
  }
  
class Trie {
    constructor() {
      this.nodes = new Map()
}
    
add(num) {
    let nodes = this.nodes
    for (const ch of num) {
        const next = nodes.get(ch) ?? new Map()
        nodes.set(ch, next)
        nodes = next
    }
}
    
maxXor(num) {
    let ret = []
    let nodes = this.nodes
    for (const ch of num) {
        const key = nodes.has(invert(ch)) ? invert(ch) : ch
        ret.push(key)
        nodes = nodes.get(key)
    }
    ret = ret.join('')
    ret = parseInt(ret, 2)
    num = parseInt(num, 2)
    return ret ^ num
}}
  
const findMaximumXOR = nums => {
    let ret = 0
    const len = Math.max(...nums).toString(2).length
    let trie = new Trie()
    for (let i = 0; i < nums.length; i++) {
        nums[i] = nums[i].toString(2).padStart(len, 0)
        trie.add(nums[i])
    }
    for (const num of nums) {
        ret = Math.max(trie.maxXor(num), ret)
    }  
    return ret
}

//https://leetcode.com/problems/maximum-xor-of-two-numbers-in-an-array/