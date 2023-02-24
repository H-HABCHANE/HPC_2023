from numba import jit, prange

@jit(nopython=True, parallel=True)
def calculate_sum():
    sum = 0
    n = 1

    for i in prange(1, 100000):
        term = 1 / (n ** 2)
        sum += term
        n += 1

    return sum

