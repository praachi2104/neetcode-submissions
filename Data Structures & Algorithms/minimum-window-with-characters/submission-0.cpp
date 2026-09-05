class Solution {
public:
    string minWindow(string s, string t) {
        if (t.size() > s.size())
            return "";
        
        map<char, int> need;
        map<char, int> window;

        for (char c : t) {
            need[c]++;
        }

        int required = need.size();
        int formed = 0;

        int left = 0;
        int minLen = INT_MAX;
        int start = 0;

        for (int right = 0; right < s.size(); right++)
        {
            window[s[right]]++;

            if (need.count(s[right]) &&
                window[s[right]] == need[s[right]]) {
                formed++;
            }

            while (formed == required)
            {
                if (right - left + 1 < minLen) {
                    minLen = right - left + 1;
                    start = left;
                }

                window[s[left]]--;

                if (need.count(s[left]) &&
                    window[s[left]] < need[s[left]]) {
                    formed--;
                }

                left++;
            }
        }
        if (minLen == INT_MAX)
            return "";

        return s.substr(start, minLen);
    }
};
