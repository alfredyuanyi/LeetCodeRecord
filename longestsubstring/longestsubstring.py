#! /usr/bin/python
class Solution(object):
    def lengthOfLongestSubstring(self, s):
        """
        :type s: str
        :rtype: int
        """
        if len(s) == 0:
            return 0
        left = right = length = 0
        result = [0,0,1]
        while right < len(s) - 1:
            if s[right + 1] in s[left:right + 1] :
                left = s[left:right + 1].index(s[right + 1]) + 1 + left
                right += 1
            elif right - left + 2 > result[2]:
                right += 1
                result[0] = left
                result[1] = right
                result[2] = right -left + 1
                pass
            else:
                right += 1
                pass
            pass
        return result[2]
        pass
    pass
