# import cppimport.import_hook
import pytest

from pyblossom import BloomFilter
from pyblossom.utils import compute_bloom_filter_sizes, compute_bloom_filter_size

def test_sizing_1():
    m, k = compute_bloom_filter_sizes(4000, 1e-6)
    assert m == 115021
    assert k == 20

def test_sizing_2():
    m = compute_bloom_filter_size(4000, 1e-6, 5)
    assert m == 306871

def test_ctor():
    bf = BloomFilter(10, 1000)
    assert bf is not None

@pytest.fixture
def bloomfilter():
    bf = BloomFilter(10, 1000)
    bf.add("word1")
    return bf

def test_add_one_element(bloomfilter):
    assert bloomfilter.mightContain("word1") is True
    assert bloomfilter.mightContain("word4") is False