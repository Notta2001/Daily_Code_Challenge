var findJudge = (n, trust) => {
    if (!trust.length && n === 1) return 1
    if (trust.length === 1) return trust[0][1]
    let adjacencyList = {}
    let persons = new Set()
    for (let [person, possibleJudge] of trust) {
        if (!adjacencyList[possibleJudge]) adjacencyList[possibleJudge] = 1
        else {
            adjacencyList[possibleJudge] += 1
        }
        // store all noin judge person's in a set
        persons.add(person)
    }
    for (let i = 1; i <= n; ++i) if (!persons.has(i) && adjacencyList[i] === n - 1) return i
    return -1
}