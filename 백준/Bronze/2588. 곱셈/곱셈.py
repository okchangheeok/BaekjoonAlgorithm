import sys
A = int(sys.stdin.readline())
B = int(sys.stdin.readline())

bh = int(B / 100)
bt = int((B-100*bh) / 10)
bo = B - 100*bh - 10*bt

print(A*bo, A*bt, A*bh, A*B)