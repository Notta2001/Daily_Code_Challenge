var romanToInt = (str) => {
    let result = 0
    const mapper = new Map()

    mapper.set("I", 1)
    mapper.set("V", 5)
    mapper.set("X", 10)
    mapper.set("L", 50)
    mapper.set("C", 100)
    mapper.set("D", 500)
    mapper.set("M", 1000)

    for (let i = str.length - 1; i >= 0; i--) {
        // Check for substraction - subtrac if previous number is bigger
        if (str[i+1] && mapper.get(str[i+1]) > mapper.get(str[i])) 
            result -= mapper.get(str[i])
        else 
            result += mapper.get(str[i])
    }
    return result
}