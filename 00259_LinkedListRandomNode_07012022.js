var Solution = (head) => {
    this.listArray = []; // public variable
    let curr = head;

    while (curr !== null) {
        this.listArray.push(curr);
        curr = curr.next;
    }

    this.length = this.listArray.length;
};

Solution.prototype.getRandom = () => {
    return this.listArray[Math.floor(Math.random() * this.length)].val;
};