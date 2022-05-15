load("@io_bazel_rules_go//go:def.bzl", "go_library", "go_test")

go_library(
    name = "solutions",
    importpath = "github.com/LazyWolfLin/leetcode/go/src/solutions",
    srcs = glob(["src/solutions/*.go"]),
)

go_test(
    name = "solutions_test",
    embed = [ ":solutions" ],
)