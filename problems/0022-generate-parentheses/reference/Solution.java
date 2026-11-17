import java.util.ArrayList;
import java.util.List;

class Solution {
    public List<String> generateParenthesis(int n) {
        List<String> result = new ArrayList<>();
        generate(n, 0, 0, new char[2 * n], result);
        return result;
    }

    private void generate(int n, int opened, int closed, char[] path, List<String> result) {
        if (closed == n) {
            result.add(new String(path));
            return;
        }
        int index = opened + closed;
        if (opened < n) {
            path[index] = '(';
            generate(n, opened + 1, closed, path, result);
        }
        if (closed < opened) {
            path[index] = ')';
            generate(n, opened, closed + 1, path, result);
        }
    }
}
