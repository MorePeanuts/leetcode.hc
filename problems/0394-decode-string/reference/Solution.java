import java.util.ArrayDeque;

class Solution {
    private record Frame(StringBuilder prefix, int repeat) {}

    public String decodeString(String s) {
        ArrayDeque<Frame> stack = new ArrayDeque<>();
        StringBuilder current = new StringBuilder();
        int repeat = 0;
        for (int i = 0; i < s.length(); i++) {
            char ch = s.charAt(i);
            if (ch >= '0' && ch <= '9') {
                repeat = repeat * 10 + ch - '0';
            } else if (ch == '[') {
                stack.push(new Frame(current, repeat));
                current = new StringBuilder();
                repeat = 0;
            } else if (ch == ']') {
                Frame frame = stack.pop();
                String part = current.toString();
                current = frame.prefix();
                for (int j = 0; j < frame.repeat(); j++) current.append(part);
            } else {
                current.append(ch);
            }
        }
        return current.toString();
    }
}
