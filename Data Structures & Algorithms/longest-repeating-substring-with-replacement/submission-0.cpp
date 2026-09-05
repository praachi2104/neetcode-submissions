class Solution {
public:
    int characterReplacement(string s, int k) {
        map<char, int> freq;
        int n=s.size();
        int left=0;
        int maxLen=0;
        int maxFreq=0;

        for(int right=0;right<n;right++)
        {
            freq[s[right]]++;
            maxFreq=max(maxFreq, freq[s[right]]);
            int winLen = right-left+1;
            while(winLen-maxFreq > k)
            {
                freq[s[left]]--;
                left++;

                winLen=right-left+1;
            }
            maxLen=max(maxLen, winLen);
        }
        return maxLen;
    }
};
