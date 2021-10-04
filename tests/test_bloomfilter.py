# import cppimport.import_hook

from pyblossom import BloomFilter

def test_ctor():
    bf = BloomFilter(10, 1000)
    assert bf is not None

def test_add_one_element():
    bf = BloomFilter(10, 1000)
    bf.add("word1")

    assert bf.mightContain("word1") is True
    assert bf.mightContain("word4") is False