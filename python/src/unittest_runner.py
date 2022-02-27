import sys
import unittest


if __name__ == '__main__':
    discover = unittest.defaultTestLoader.discover("./", pattern="*_test.py")

    suite = unittest.TestSuite()
    suite.addTest(discover)

    runner = unittest.TextTestRunner()
    result = runner.run(suite)

    sys.exit(0 if result.wasSuccessful() else 1)