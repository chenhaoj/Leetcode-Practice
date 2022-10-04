# from re import L

# class Solution:
#     def strStr(self, haystack: str, needle: str) -> int:
#         # 建立偏移表
#         if not needle : return 0
#         n = len(haystack)
#         m = len(needle)        
#         if m > n : return -1

#         # 偏移表预处理
#         dic = {
#             v : m-k for k, v in enumerate(needle)
#         }

#         # 遍历Str查找
#         idx = 0
#         while idx <= (n-m):
#             subStr = haystack[idx: idx+m]
#             if subStr == needle:
#                 return idx
#             elif idx+m == n:
#                 return -1
#             else:
#                 # 匹配不成功
#                 nextc = haystack[idx+m]
#                 idx += dic[nextc] if dic.get(nextc) else m+1
        
#         return -1

class Solution:
    def strStr(self, haystack: str, needle: str) -> int:
        if not needle: return 0
        lnd = len(needle)
        lnf = len(haystack)
        if lnd > lnf: return -1

        # 偏移表预处理    
        dic ={v:lnd-k for k,v in enumerate(needle)}
        idx = 0

        while idx+lnd <= lnf:
            # 待匹配字符串
            str_cut = haystack[idx:idx+lnd]
            # 判断是否匹配
            if str_cut == needle:
                return idx
            elif idx+lnd == lnf:
                return -1
            else:
                # 不匹配情况下，根据下一个字符的偏移，移动idx
                nextc = haystack[idx+lnd]
                idx += dic[nextc] if dic.get(nextc) else lnd+1
        return -1

if __name__ == '__main__':
    test = Solution()
    print(test.strStr("hello", "ll"))


# class Solution(object):
#     def strStr(self, haystack, needle):
#         """
#         :type haystack: str
#         :type needle: str
#         :rtype: int
#         """