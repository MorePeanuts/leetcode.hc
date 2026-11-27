class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        vector<int> parent(accounts.size());
        iota(parent.begin(), parent.end(), 0);
        auto root = [&](int i) {
            while (parent[i] != i) {
                parent[i] = parent[parent[i]];
                i = parent[i];
            }
            return i;
        };
        unordered_map<string, int> owner;
        for (int i = 0; i < accounts.size(); ++i) {
            for (int j = 1; j < accounts[i].size(); ++j) {
                auto [it, added] = owner.emplace(accounts[i][j], i);
                if (!added) {
                    parent[root(i)] = root(it->second);
                }
            }
        }
        unordered_map<int, vector<string>> groups;
        for (const auto& [email, i] : owner) {
            groups[root(i)].push_back(email);
        }
        vector<vector<string>> result;
        for (auto& [i, emails] : groups) {
            sort(emails.begin(), emails.end());
            emails.insert(emails.begin(), accounts[i][0]);
            result.push_back(move(emails));
        }
        return result;
    }
};
