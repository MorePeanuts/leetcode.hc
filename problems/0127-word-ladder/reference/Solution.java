import java.util.ArrayList;
import java.util.HashMap;
import java.util.HashSet;
import java.util.List;
import java.util.Map;
import java.util.Set;

class Solution {
    private String pattern(String word, int i) {
        return word.substring(0, i) + '*' + word.substring(i + 1);
    }

    public int ladderLength(String beginWord, String endWord, List<String> wordList) {
        if (!wordList.contains(endWord)) return 0;
        Map<String, List<String>> buckets = new HashMap<>();
        for (String word : wordList)
            for (int i = 0; i < word.length(); i++)
                buckets.computeIfAbsent(pattern(word, i), key -> new ArrayList<>()).add(word);

        Set<String> seen = new HashSet<>();
        seen.add(beginWord);
        List<String> queue = new ArrayList<>();
        queue.add(beginWord);
        int distance = 1;
        for (int head = 0; head < queue.size(); distance++) {
            int end = queue.size();
            for (; head < end; head++) {
                String word = queue.get(head);
                if (word.equals(endWord)) return distance;
                for (int i = 0; i < word.length(); i++) {
                    List<String> neighbors = buckets.remove(pattern(word, i));
                    if (neighbors != null)
                        for (String next : neighbors)
                            if (seen.add(next)) queue.add(next);
                }
            }
        }
        return 0;
    }
}
