load("@rules_rust//rust:defs.bzl", "rust_library", "rust_test")

rust_library(
    name = "solutions",
    srcs = [
        "src/lib.rs",
        "src/common.rs",
    ] + glob(["src/solutions/*.rs"]),
    edition = "2021",
)

rust_test(
    name = "solutions_test",
    crate = ":solutions",
    edition = "2021",
    deps = [":solutions"],
)
