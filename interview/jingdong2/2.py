def canWin(graph, node, target):
    # 如果当前结点是叶子结点，则返回False，表示当前玩家失败
    if len(graph[node]) == 1 and node != target:
        return False
    
    # 递归遍历子结点，如果存在一个子结点使得对方无法获胜，则当前玩家能获胜
    canWinCurrentPlayer = False
    for neighbor in graph[node]:
        if neighbor != target:
            canWinCurrentPlayer |= not canWin(graph, neighbor, node)
    
    return canWinCurrentPlayer

def main():
    t = int(input())
    for _ in range(t):
        n, target = map(int, input().split())
        graph = [[] for _ in range(n + 1)]
        for _ in range(n - 1):
            u, v = map(int, input().split())
            graph[u].append(v)
            graph[v].append(u)
        
        if canWin(graph, target, 0):
            print("lose")
        else:
            print("win")

if __name__ == "__main__":
    main()
