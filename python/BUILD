py_library(
    name = "solutions",
    deps = [":common"],
    srcs = glob(["src/solutions/*.py"]),
)

py_library(
    name = "common",
    srcs = glob(["src/common/*.py"]),
)

py_test(
    name = "solutions_test",
    deps = [":solutions"],
    srcs = ["src/unittest_runner.py"],
    main = "unittest_runner.py",
)