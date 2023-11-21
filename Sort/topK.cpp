/* topk问题:
1. 全局排序, 快排O(nlogn)
2. 局部排序, 冒泡找k大O(n*k)
3. 堆排序, 只排前k个O(nlogk)
4. 分治法, 每个分支都递归, 快排O(nlogn)
5. 减治法, 只递归一个分支, 二分查找O(logn), 随机选择O(n)
6. topk问题的另一个解法: 随机选择+partition
参考链接: https://zhuanlan.zhihu.com/p/76734219
 */