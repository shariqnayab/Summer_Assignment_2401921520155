class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n = s1.size(), m = s2.size();

        if (n > m) return false;

        vector<int> cnt(26, 0);

        for (char c : s1)
            cnt[c - 'a']++;

        int left = 0, right = 0, need = n;

        while (right < m) {
            if (cnt[s2[right] - 'a'] > 0)
                need--;

            cnt[s2[right] - 'a']--;
            right++;

            if (need == 0)
                return true;

            if (right - left == n) {
                if (cnt[s2[left] - 'a'] >= 0)
                    need++;

                cnt[s2[left] - 'a']++;
                left++;
            }
        }

        return false;
    }
};
