class Solution {
public:
    int minMutation(string startGene, string endGene, vector<string>& bank) {
        queue<string> pending;
        pending.push(startGene);
        unordered_set<string> seen{startGene};
        for (int steps = 0; !pending.empty(); steps++) {
            for (int count = pending.size(); count > 0; count--) {
                string current = pending.front();
                pending.pop();
                if (current == endGene) return steps;
                for (const string& next : bank) {
                    if (seen.count(next)) continue;
                    int differences = 0;
                    for (int i = 0; i < 8; i++) {
                        if (current[i] != next[i]) differences++;
                    }
                    if (differences == 1) {
                        seen.insert(next);
                        pending.push(next);
                    }
                }
            }
        }
        return -1;
    }
};
