cc_library(
    name = "solutions",
    deps = [
        ":common",
        "@com_google_googletest//:gtest_main",
    ],
    srcs = glob(["src/solutions/*.cpp"]),
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