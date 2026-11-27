import java.util.*;

class Solution {
    private int root(int[] parent, int i) {
        while (parent[i] != i) {
            parent[i] = parent[parent[i]];
            i = parent[i];
        }
        return i;
    }

    public List<List<String>> accountsMerge(List<List<String>> accounts) {
        int[] parent = new int[accounts.size()];
        for (int i = 0; i < parent.length; i++) {
            parent[i] = i;
        }
        Map<String, Integer> owner = new HashMap<>();
        for (int i = 0; i < accounts.size(); i++) {
            List<String> account = accounts.get(i);
            for (int j = 1; j < account.size(); j++) {
                Integer first = owner.putIfAbsent(account.get(j), i);
                if (first != null) {
                    parent[root(parent, i)] = root(parent, first);
                }
            }
        }

        Map<Integer, List<String>> groups = new HashMap<>();
        for (var entry : owner.entrySet()) {
            int id = root(parent, entry.getValue());
            groups.computeIfAbsent(id, key -> new ArrayList<>()).add(entry.getKey());
        }
        List<List<String>> result = new ArrayList<>();
        for (var entry : groups.entrySet()) {
            List<String> row = entry.getValue();
            Collections.sort(row);
            row.add(0, accounts.get(entry.getKey()).get(0));
            result.add(row);
        }
        return result;
    }
}
