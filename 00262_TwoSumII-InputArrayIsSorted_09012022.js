var twoSum = (numbers, target) => {
    let firstIndex = 0, secondIndex = numbers.length - 1;
    let currSum = numbers[firstIndex] + numbers[secondIndex];

    while (currSum != target) {
        if (currSum < target) 
            firstIndex ++;
        else 
            secondIndex --;
        currSum = numbers[firstIndex] + numbers[secondIndex];
    }
    
    return [firstIndex + 1, secondIndex + 1];
};