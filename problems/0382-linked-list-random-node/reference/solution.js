class Solution {
    constructor(head) {
        this.head = head;
    }

    getRandom() {
        let result = this.head.val;
        let count = 0;
        for (let node = this.head; node !== null; node = node.next) {
            if (Math.floor(Math.random() * ++count) === 0) {
                result = node.val;
            }
        }
        return result;
    }
}
