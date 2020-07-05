import re 
class Solution:
    def myAtoi(self, str: str) -> int:
        str_strip = str.strip()
        str_strip = re.findall(r"(^[\+\-0]*\d+)\D*", str_strip)

        try:
            out = int("".join(str_strip))
            MAX_INT=2**32-1
            MIN_INT=-(2**32)
            if out > MAX_INT:
                return MAX_INT
            elif out < MIN_INT:
                return MIN_INT
            else:
                return out
        except: 
            return 0

def re_sample():
    #findall()
    regular_v1 = re.findall(r"docs","https://docs.python.org/3/whatsnew/3.6.html")
    regular_v2 = re.findall(r"^http","https://docs.python.org/3/whatsnew/3.6.html")
    regular_v3 = re.findall(r"html$","https://docs.python.org/3/whatsnew/3.6.html")
    regular_v4 = re.findall(r"[t, w]h","https://docs.python.org/3/whatsnew/3.6.html")
    regular_v5 = re.findall(r"\d","https://docs.python.org/3/whatsnew/3.6.html") #數字
    regular_v6 = re.findall(r"\D","https://docs.python.org/3/whatsnew/3.6.html") #除了數字
    regular_v7 = re.findall(r"\w","https://docs.python.org/3/whatsnew/3.6.html") #文字
    regular_v8 = re.findall(r"\W","https://docs.python.org/3/whatsnew/3.6.html") #符號
    print(regular_v1)
    print(regular_v2)
    print(regular_v3)
    print(regular_v4)
    print(regular_v5)
    print(regular_v6)
    print(regular_v7)
    print(regular_v8)



if __name__ == "__main__":
    #re_sample()          (^[\+\-0]*\d+)\D*
    ## 正則符號解釋https://kknews.cc/zh-tw/code/n6ayvyg.html
    re_test = re.findall(r"(^[\+\-0]*\d+)\D*","+--01234560    ghjghk+")
    print(re_test)
    print("1".join(re_test)) #join 到間隔的位置中
    str1 = str("+00001111  woow")
    a = Solution()
    res = a.myAtoi(str1)
    print(res)

    rawtest = re.findall(r"(^[\+\-0]*\d+)\D*",str1.strip())
    print(int("".join(rawtest)))  #int()可以消除+000123 or -01354 前面+-0的問題


