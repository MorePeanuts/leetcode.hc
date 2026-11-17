class Solution {
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        vector<int> first, second;
        for (ListNode * node = l1; node != nullptr; node = node->next) {
            first.push_back(node->val);
        }
        for (ListNode * node = l2; node != nullptr; node = node->next) {
            second.push_back(node->val);
        }
        int carry = 0;
        ListNode * result = nullptr;
        while (!first.empty() || !second.empty() || carry != 0) {
            int sum = carry;
            if (!first.empty()) {
                sum += first.back();
                first.pop_back();
            }
            if (!second.empty()) {
                sum += second.back();
                second.pop_back();
            }
            carry = sum / 10;
            result = new ListNode(sum % 10, result);
        }
        return result;
    }
};
