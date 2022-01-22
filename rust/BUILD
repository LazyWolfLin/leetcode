load("@rules_rust//rust:defs.bzl", "rust_library", "rust_test")

rust_library(
    name = "solutions",
    srcs = [
        "src/lib.rs",
        "src/common.rs",
    ] + glob(["src/solutions/*.rs"]),
)

rust_test(
    name = "solutions_test",
    crate = ":solutions",
    deps = [":solutions"],
)
