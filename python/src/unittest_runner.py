import unittest


if __name__ == '__main__':
    discover = unittest.defaultTestLoader.discover("./", pattern="*_test.py")

    suite = unittest.TestSuite()
    suite.addTest(discover)

    runner = unittest.TextTestRunner()
    runner.run(suite)
