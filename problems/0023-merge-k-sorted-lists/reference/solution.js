function mergeKLists(lists) {
    function mergeTwo(a, b) {
        const dummy = new ListNode(0);
        let tail = dummy;
        while (a !== null && b !== null) {
            if (a.val <= b.val) {
                tail.next = a;
                a = a.next;
            } else {
                tail.next = b;
                b = b.next;
            }
            tail = tail.next;
        }
        tail.next = a !== null ? a : b;
        return dummy.next;
    }
    const n = lists.length;

    for (let step = 1; step < n; step *= 2) {
        for (let i = 0; i + step < n; i += 2 * step) {
            lists[i] = mergeTwo(lists[i], lists[i + step]);
        }
    }
    return n === 0 ? null : lists[0];
}
