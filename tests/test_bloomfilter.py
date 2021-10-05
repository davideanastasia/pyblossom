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

def test_add_one_element():
    bf = BloomFilter(10, 1000)
    bf.add("word1")

    assert bf.mightContain("word1") is True
    assert bf.mightContain("word4") is False

def test_merge():
    bf1 = BloomFilter(10, 1000)
    bf1.add("word1")

    bf2 = BloomFilter(10, 1000)
    bf2.add("word2")

    bf3 = bf1.merge(bf2)

    assert bf3 is not None
    assert bf3.mightContain("word1") is True
    assert bf3.mightContain("word2") is True
    assert bf3.mightContain("word3") is False
