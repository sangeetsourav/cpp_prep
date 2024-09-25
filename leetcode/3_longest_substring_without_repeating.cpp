class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int left{0};
        int right{0};
        std::set<int> window_set; 
        int maxLength = 0;

        while(left < s.size())
        {
            int windowLength = right - left + 1;
            if(window_set.count(s[right]) == 0)
            {
                window_set.insert(s[right]);
            }

            if(windowLength == window_set.size())
            {
                // is a valid window
                maxLength = std::max(maxLength, windowLength);
                if(right<s.size()-1)
                {
                    right++;
                    window_set.insert(s[right]);
                }
                else
                {
                    return maxLength;
                }
            }
            else
            {
                window_set.erase(s[left]);
                left++;
            }
        }

        return maxLength;
    }
};