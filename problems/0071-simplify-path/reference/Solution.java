import java.util.ArrayList;
import java.util.List;

class Solution {
    public String simplifyPath(String path) {
        List<String> parts = new ArrayList<>();
        for (String part : path.split("/")) {
            if (part.equals("..")) {
                if (!parts.isEmpty()) {
                    parts.remove(parts.size() - 1);
                }
            } else if (!part.isEmpty() && !part.equals(".")) {
                parts.add(part);
            }
        }
        return "/" + String.join("/", parts);
    }
}
