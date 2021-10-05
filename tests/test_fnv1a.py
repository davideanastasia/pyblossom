from pyblossom import fnv1a

_LETTERS = 'abcdefghijklmnopqrstuvwxyz'

def test_fnv1a_basic():
    values = set()
    values.add(fnv1a("a_string"))
    for i in range(10):
        values.add(fnv1a("a_string", _LETTERS[i]))

    assert len(values) == 11