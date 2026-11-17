class Solution {
public:
    bool isNStraightHand(vector<int> &hand, int groupSize) {
        if (hand.size() % groupSize != 0) {
            return false;
        }
        unordered_map<int, int> counts;
        for (int value : hand) {
            counts[value]++;
        }
        sort(hand.begin(), hand.end());
        for (int first : hand) {
            int amount = counts[first];
            if (amount == 0) {
                continue;
            }
            for (int value = first; value < first + groupSize; value++) {
                auto entry = counts.find(value);
                if (entry == counts.end() || entry->second < amount) {
                    return false;
                }
                entry->second -= amount;
            }
        }
        return true;
    }
};
