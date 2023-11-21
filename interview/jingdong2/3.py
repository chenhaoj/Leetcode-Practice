def find_operations(x, y):
    x_bin = bin(x)[2:]
    y_bin = bin(y)[2:]
    
    if len(x_bin) > len(y_bin):
        return -1  # 无解
    
    operations = []
    
    for i in range(len(x_bin) - 1, -1, -1):
        if x_bin[i] != y_bin[i]:
            if y_bin[i] == '1':
                return -1  # 无解
            
            if x_bin[i] == '1':
                operations.append('- ' + str(2**i))
            else:
                operations.append('+ ' + str(2**i))
    print(operations)

    return operations

def main():
    x, y = map(int, input().split())
    operations = find_operations(x, y)
    
    if operations == -1:
        print(-1)
    else:
        print(len(operations))
        for op in operations:
            print(op)

if __name__ == "__main__":
    main()
