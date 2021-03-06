import unittest

def no_duplicates(str_):
    """ Determine if str_ has all unique characters """
    return len(str_) == len(set(str_))

def no_duplicates_no_structures(str_):
    """ Now without using additional data structures """
    for letter in str_:
        if str_.count(letter) > 1:
            print('false')
    else:
        print("true")

class NoDuplicatesTest(unittest.TestCase):

    # Two-element tuples: input string and expected result

    TEST_DATA = [
        ('a', True),
        ('aa', False),
        ('ab', True),
        ('ab ', True),
        ('', True),
        (' ', True),
        ('  ', False),
        ('qwerty', True),
        ('qwerte', False)]

    def test_no_duplicates_both_versions(self):
        for str_, expected_result in self.TEST_DATA:
            result1 = no_duplicates(str_)
            self.assertEqual(result1, expected_result)

            # Test the version without additional data structures too
            result2 = no_duplicates_no_structures(str_)
            self.assertEqual(result2, expected_result)

if __name__ == "__main__":
    #unittest.main()
    no_duplicates_no_structures('deb')
