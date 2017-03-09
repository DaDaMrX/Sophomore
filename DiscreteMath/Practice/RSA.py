class RSA(object):

    def __init__(self, p, q, w):
        self.__p = p
        self.__q = q
        self.__n = p * q
        self.__phin = (p - 1) * (q - 1)
        self.__w = w
        self.__d = self.__solve(self.__w, 1, self.__phin)

    def __ext_gcd(self, a, b):
        if b == 0: return a, 1, 0
        d, y, x = self.__ext_gcd(b, a % b)
        y -= (a // b) * x
        return d, x, y

    def __solve(self, a, c, m):
        d, x, y = self.__ext_gcd(a, m)
        return x * c // d

    def __pow_mod(self, a, n, m):
        a %= m
        ans = 1
        while n:
            if n % 2: ans = ans * a % m
            a = a * a % m
            n //= 2
        return ans

    def encrypt(self, m):
        return self.__pow_mod(m, self.__w, self.__n)

    def decrypt(self, x):
        return self.__pow_mod(x, self.__d, self.__n)

def main():
    rsa = RSA(5, 7, 7)
    print(rsa.encrypt(18))
    print(rsa.decrypt(32))

if __name__ == '__main__':
    main()