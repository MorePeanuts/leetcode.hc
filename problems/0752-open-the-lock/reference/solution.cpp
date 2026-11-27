class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        array<bool, 10000> seen{};
        for (const string& dead : deadends) seen[stoi(dead)] = true;
        if (seen[0]) return -1;
        int goal = stoi(target);
        queue<int> pending;
        pending.push(0);
        seen[0] = true;
        for (int turns = 0; !pending.empty(); turns++) {
            for (int count = pending.size(); count > 0; count--) {
                int state = pending.front();
                pending.pop();
                if (state == goal) return turns;
                for (int place = 1; place <= 1000; place *= 10) {
                    int digit = state / place % 10;
                    int up = state + (digit == 9 ? -9 : 1) * place;
                    int down = state + (digit == 0 ? 9 : -1) * place;
                    for (int next : {up, down}) {
                        if (!seen[next]) {
                            seen[next] = true;
                            pending.push(next);
                        }
                    }
                }
            }
        }
        return -1;
    }
};
