
def check_palindrome(s, i, j):
    length = 0
    while True:
        i = i - 1
        j = j + 1
        if i < 0 or j > len(s)-1:
            return length
        if s[i] == s[j]:
            length += 1
        else:
            return length



def longestPalindrome(s):
    """
    :type s: str
    :rtype: str
    """
    length = len(s)
    sublen = 0

    if length <= 1:
        return s
    
    max_length = 0
    maxstrfinal = ''
    for i in range(length-1):
        begin = i
        end = i
        sublen = check_palindrome(s, begin, end)
        maxstr = s[begin-sublen:end+sublen+1]
        if s[i] == s[i+1]:
            begin = i
            end = i + 1
            sublen2 = check_palindrome(s, begin, end)
            if sublen2 >=  sublen:
                maxstr = s[begin-sublen2:end+sublen2+1]

        if len(maxstr) > max_length:
            max_length = len(maxstr)
            maxstrfinal = maxstr

    return maxstrfinal

                    

if __name__ == "__main__":
    s = "ac"
    res = check_palindrome(s, 3, 3)
    respalindrome = longestPalindrome(s)
    print(res)
    print(respalindrome)
