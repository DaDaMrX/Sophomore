from random import randint

def Miller_Rabin(n):
    if n == 2: return True
    if n == 1 or n % 2 == 0: return False
    for time in range(20):
        m = n - 1
        q = 0
        while m % 2 == 0:
            q += 1
            m /= 2
        a = randint(2, n - 1)
        x = a**m % n
        for i in range(q):
            x2 = x**2 % n
            if x != 1 and x != n - 1 and x2 == 1: return False
            x = x2
        if x != 1: return False
    return True
