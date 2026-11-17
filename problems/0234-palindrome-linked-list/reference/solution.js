function isPalindrome(head) {
    let slow = head;
    let fast = head;
    while (fast !== null && fast.next !== null) {
        slow = slow.next;
        fast = fast.next.next;
    }
    let previous = null;
    while (slow !== null) {
        let next = slow.next;
        slow.next = previous;
        previous = slow;
        slow = next;
    }
    let left = head;
    while (previous !== null) {
        if (left.val !== previous.val) return false;
        left = left.next;
        previous = previous.next;
    }
    return true;
}
