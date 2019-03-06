go_library(
    name = "situations",
    srcs = [
        "InTransition.go",
        "NoSabbatical.go",
        "OtherGjobAwesome.go",
        "OtherGjobNotGood.go",
        "TransitionDone.go",
        "TransitionFailed.go",
        "situation_factory.go",
    ],
)

go_test(
    name = "situations_test",
    size = "small",
    srcs = ["InTransition_test.go"],
    library = ":situations",
)
