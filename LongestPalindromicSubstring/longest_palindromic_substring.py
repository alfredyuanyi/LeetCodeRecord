class Solution(object):
    def longestPalindrome(self, s):
        """
        :type s: str
        :rtype: str
        """
        result = [0, 0]
        start = 0
        end = 0
        length = len(s)
        if length < 2:
            return s
        if length == 2:
            return s if s[0] == s[1] else s[0]
        for index in range(1, len(s)):
            start = index - 1
            end = index + 1
            while start >= 0 and end <= length and s[start:index][::-1] == s[index + 1:end + 1]:
                if end - start < result[1] - result[0]:
                    start -= 1
                    end += 1
                    continue
                result[0] = start
                result[1] = end
                start -= 1
                end += 1
            start = index
            end = index + 1
            while start >= 0 and end <= length \
                  and s[start:index + 1][::-1] == s[index + 1:end + 1]:
                if end - start < result[1] - result[0]:
                    start -= 1
                    end += 1
                    continue
                result[0] = start
                result[1] = end
                start -= 1
                end += 1
        if result[1] - result[0] == 0:
            return s[result[0]:result[1] + 1] if s[0] != s[1] else s[:2]
        else:
            return s[result[0]:result[1] + 1]


if __name__ == '__main__':
    so = Solution()
    print so.longestPalindrome('babad')
