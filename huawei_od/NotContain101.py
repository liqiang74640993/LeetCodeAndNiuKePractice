# This Python file uses the following encoding: utf-8

# if__name__ == "__main__":
#     pass

# 算法实现
def dfs(p, limit, f, arr, pre, prepre):
    if p == len(arr):
        return 1

    if not limit and f[p][pre][prepre] > 0:
        return f[p][pre][prepre]

    maxV = arr[p] if limit else 1
    count = 0

    for i in range(maxV + 1):
        if i == 1 and pre == 0 and prepre == 1:
            continue
        count += dfs(p + 1, limit and i == maxV, f, arr, i, pre)

    if not limit:
        f[p][pre][prepre] = count

    return count


def digitSearch(num):
    arr = list(map(int, list(format(num, 'b'))))
    f = [[[0 for k in range(2)] for j in range(2)] for i in range(len(arr))]
    return dfs(0, True, f, arr, 0, 0)


# 输入获取
L, R = map(int, input().split())

# 算法调用
print(digitSearch(R) - digitSearch(L - 1))    # 算法实现
def dfs(p, limit, f, arr, pre, prepre):
    if p == len(arr):
        return 1

    if not limit and f[p][pre][prepre] > 0:
        return f[p][pre][prepre]

    maxV = arr[p] if limit else 1
    count = 0

    for i in range(maxV + 1):
        if i == 1 and pre == 0 and prepre == 1:
            continue
        count += dfs(p + 1, limit and i == maxV, f, arr, i, pre)

    if not limit:
        f[p][pre][prepre] = count

    return count


def digitSearch(num):
    arr = list(map(int, list(format(num, 'b'))))
    f = [[[0 for k in range(2)] for j in range(2)] for i in range(len(arr))]
    return dfs(0, True, f, arr, 0, 0)


# 输入获取
L, R = map(int, input().split())

# 算法调用
print(digitSearch(R) - digitSearch(L - 1))
