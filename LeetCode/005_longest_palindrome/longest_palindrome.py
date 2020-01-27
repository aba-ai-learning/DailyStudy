class Solution(object):
    def check_palindrome(self, s, i, j):
        length = 0
        while True:
            i = i - 1
            j = j + 1
            if i < 0 or j > len(s) - 1:
                break
            if s[i] == s[j]:
                length += 1
            else:
                break

        return length

    def longestPalindrome(self, s):
        """
        :type s: str
        :rtype: str
        """
        if len(s) <= 1:
            return s

        maxstrfinal = ''
        maxlength = 0
        for i in range(len(s) - 1):
            begin = i
            end = i
            sublen = self.check_palindrome(s, begin, end)
            maxstr = s[begin-sublen:end+sublen+1]

            if s[i] == s[i+1]:
                begin = i
                end = i + 1
                sublen2 = self.check_palindrome(s, begin, end)
                if sublen2 >= sublen:
                    maxstr = s[begin-sublen2:end+sublen2+1]

            if len(maxstr) > maxlength:
                maxstrfinal = maxstr
                maxlength = len(maxstr)

        return maxstrfinal
