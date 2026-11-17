import java.util.ArrayList;
import java.util.List;

class Solution {
    private void visit(String s, int start, int count, String path, List<String> result) {
        int left = 4 - count;
        if (s.length() - start < left || s.length() - start > 3 * left) {
            return;
        }
        if (left == 0) {
            result.add(path);
            return;
        }
        int value = 0;
        for (int length = 1; length <= 3 && start + length <= s.length(); ++length) {
            value = value * 10 + s.charAt(start + length - 1) - '0';
            if (value > 255 || (length > 1 && s.charAt(start) == '0')) {
                break;
            }
            String next = path + (count == 0 ? "" : ".") + s.substring(start, start + length);
            visit(s, start + length, count + 1, next, result);
        }
    }

    public List<String> restoreIpAddresses(String s) {
        List<String> result = new ArrayList<>();
        visit(s, 0, 0, "", result);
        return result;
    }
}
