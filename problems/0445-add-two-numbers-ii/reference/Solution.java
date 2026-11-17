class Solution {
    public ListNode addTwoNumbers(ListNode l1, ListNode l2) {
        int[] first = new int[100];
        int[] second = new int[100];
        int a = 0;
        int b = 0;
        for (ListNode node = l1; node != null; node = node.next) {
            first[a++] = node.val;
        }
        for (ListNode node = l2; node != null; node = node.next) {
            second[b++] = node.val;
        }
        int carry = 0;
        ListNode result = null;
        while (a > 0 || b > 0 || carry != 0) {
            int sum = carry;
            if (a > 0) {
                sum += first[--a];
            }
            if (b > 0) {
                sum += second[--b];
            }
            carry = sum / 10;
            result = new ListNode(sum % 10, result);
        }
        return result;
    }
}
