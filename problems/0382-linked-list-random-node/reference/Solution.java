import java.util.concurrent.ThreadLocalRandom;

class Solution {
    private final ListNode head;

    public Solution(ListNode head) {
        this.head = head;
    }

    public int getRandom() {
        int result = head.val;
        int count = 0;
        for (ListNode node = head; node != null; node = node.next) {
            if (ThreadLocalRandom.current().nextInt(++count) == 0) {
                result = node.val;
            }
        }
        return result;
    }
}
