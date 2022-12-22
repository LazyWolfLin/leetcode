cc_library(
    name = "solutions",
    srcs = glob(["src/solutions/*.cpp"]),
    deps = [
        ":common",
        "@com_google_googletest//:gtest_main",
    ],
)

cc_library(
    name = "common",
    srcs = glob(["src/common/*.cpp"]),
    hdrs = glob(["src/common/*.h"]),
)

cc_test(
    name = "solutions_test",
    deps = [":solutions"],
)
