class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int len=s1.size();
        int n=s2.size();
        map<char, int> freq1;
        map<char, int> freq2;
        if(len>n)
        {
            return false;
        }
        for(int i=0;i<len;i++)
        {
            freq1[s1[i]]++;
        }
        int left=0;
        int right=len-1;
        for(int i=left;i<=right;i++)
        {
            freq2[s2[i]]++;
        }
        while(right<n)
        {
            if(freq1==freq2)
            {
                return true;
            }
            freq2[s2[left]]--;
            if (freq2[s2[left]] == 0) {
                freq2.erase(s2[left]);
            }
            left++;
            right++;
            if (right < n) {
                freq2[s2[right]]++;
            }
        }
        return false;
    }
};
