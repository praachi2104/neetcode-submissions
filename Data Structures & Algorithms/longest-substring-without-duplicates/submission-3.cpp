class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n=s.size();
        unordered_set<char> store;
        int left=0;
        int maxLen=0;
        for(int right=0;right<n;right++)
        {
            while (store.count(s[right])) {
                store.erase(s[left]);
                left++;
            }

            store.insert(s[right]);

            int len = right - left + 1;
            maxLen = max(maxLen, len);
        }
        return maxLen;
    }
};
