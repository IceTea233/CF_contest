if __name__ == "__main__":
    t = int(input())
    for _ in range(t):
        ans = 0
        x = input()
        b = 10
        n = len(x)
        for i in range(0, n-1):
            l = x[0:i]
            m = str(int(x[i]) + int(x[i+1]))
            r = x[i+2:n]
            num = int(l + m + r)
            # print("num = ", num)
            if (num > ans):
                ans = num
        print(ans)
