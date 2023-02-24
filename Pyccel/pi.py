from pyccel.decorators import types
from pyccel.epyccel import epyccel

@types('int')
def calculate_pi(n):
    pi = 0.0
    sign = 1.0

    for i in range(1, n+1):
        term = sign / (2.0 * i - 1.0)
        pi += term
        sign = -sign

    return 4.0 * pi

calculate_pi = epyccel(calculate_pi)

# Example usage:
print(calculate_pi(1000000))

