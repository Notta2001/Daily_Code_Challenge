var strStr = (hayStack, needle) => {
    let nLen = needle.length, hLen = hayStack.length
    if (!nLen) return 0
    if (nLen > hLen) return -1

    let split = hayStack.split(needle)[0]
    return split.length == hLen ? -1 : split.length
}