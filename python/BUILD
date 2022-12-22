py_library(
    name = "solutions",
    srcs = glob(["src/solutions/*.py"]),
    deps = [":common"],
)

py_library(
    name = "common",
    srcs = glob(["src/common/*.py"]),
)

py_test(
    name = "solutions_test",
    srcs = ["src/unittest_runner.py"],
    main = "unittest_runner.py",
    deps = [":solutions"],
)
