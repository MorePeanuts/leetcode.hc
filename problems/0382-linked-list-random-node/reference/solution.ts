class Solution {
    private readonly head: ListNode;

    constructor(head: ListNode | null) {
        this.head = head!;
    }

    getRandom(): number {
        let result = this.head.val;
        let count = 0;
        for (let node: ListNode | null = this.head; node !== null; node = node.next) {
            if (Math.floor(Math.random() * ++count) === 0) {
                result = node.val;
            }
        }
        return result;
    }
}
