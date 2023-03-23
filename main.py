def restoreMatrix(self, rowSum: list[int], colSum: list[int]) -> list[list[int]]:
    n = len(rowSum)
    m = len(colSum)
    ans = []
    for i in range(0, n):
        ans.append([])
        for j in range(0, m):
            mi = min(rowSum[i], colSum[j])
            ans[i].append(mi)
            rowSum[i] -= mi
            rowSum[j] -= mi


if __name__ == '__main__':
    while (True):
        a = int(input())
        # print(bin(a).replace('0b', ''))
        print(bin(2 ** 7 + a))
    pass
