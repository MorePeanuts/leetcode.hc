class Solution {
    public String minWindow(String s, String t) {
        int length = s.length();
        int missing = t.length();
        int[] need = new int[128];
        for (int i = 0; i < missing; i++) need[t.charAt(i)]++;
        int left = 0;
        int bestStart = 0;
        int bestLength = length + 1;
        for (int right = 0; right < length; right++) {
            if (need[s.charAt(right)]-- > 0) missing--;
            if (missing == 0) {
                while (need[s.charAt(left)] < 0) {
                    need[s.charAt(left)]++;
                    left++;
                }
                int windowLength = right - left + 1;
                if (windowLength < bestLength) {
                    bestLength = windowLength;
                    bestStart = left;
                }
                need[s.charAt(left)]++;
                missing++;
                left++;
            }
        }
        return bestLength <= length ? s.substring(bestStart, bestStart + bestLength) : "";
    }
}
