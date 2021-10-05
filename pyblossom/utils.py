import math
from typing import Tuple

# ref: https://hur.st/bloomfilter/bloomfilter.js

def compute_bloom_filter_sizes(n: int, p: float) -> Tuple[int, int]:
    m = -n * math.log(p) / pow(math.log(2), 2)
    k = (m * math.log(2)) / n

    return round(m), round(k)

def compute_bloom_filter_size(n: int, p: float, k: int) -> int:
    r = -k / math.log(1 - math.exp(math.log(p) / k))
    m = math.ceil(n * r)

    return m