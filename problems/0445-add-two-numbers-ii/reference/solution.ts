function addTwoNumbers(l1: ListNode | null, l2: ListNode | null): ListNode | null {
    const first: number[] = [];
    const second: number[] = [];
    for (let node = l1; node !== null; node = node.next) {
        first.push(node.val);
    }
    for (let node = l2; node !== null; node = node.next) {
        second.push(node.val);
    }
    let carry = 0;
    let result: ListNode | null = null;
    while (first.length > 0 || second.length > 0 || carry !== 0) {
        let sum = carry;
        if (first.length > 0) {
            sum += first.pop()!;
        }
        if (second.length > 0) {
            sum += second.pop()!;
        }
        carry = Math.floor(sum / 10);
        result = new ListNode(sum % 10, result);
    }
    return result;
}
