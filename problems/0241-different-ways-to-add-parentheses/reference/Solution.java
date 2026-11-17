import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

class Solution {
    private List<Long> solve(String text, Map<String, List<Long>> memo) {
        List<Long> known = memo.get(text);
        if (known != null) return known;
        List<Long> output = new ArrayList<>();
        for (int i = 0; i < text.length(); i++) {
            char op = text.charAt(i);
            if (op != '+' && op != '-' && op != '*') continue;
            List<Long> left = solve(text.substring(0, i), memo);
            List<Long> right = solve(text.substring(i + 1), memo);
            for (long a : left)
                for (long b : right)
                    output.add(op == '+' ? a + b : op == '-' ? a - b : a * b);
        }
        if (output.isEmpty()) output.add(Long.parseLong(text));
        memo.put(text, output);
        return output;
    }

    public List<Integer> diffWaysToCompute(String expression) {
        List<Long> values = solve(expression, new HashMap<>());
        List<Integer> result = new ArrayList<>(values.size());
        for (long value : values) result.add((int)value);
        return result;
    }
}
