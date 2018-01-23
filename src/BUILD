cc_library(
    name = "card",
    srcs = ["card.cc"],
    hdrs = ["card.h"],
    linkopts = select({
        "//conditions:default": ["-pthread"],
    }),
    visibility = ["//visibility:public"],
    deps = ["@com_google_absl//absl/strings"],
)

cc_test(
    name = "card_test",
    srcs = ["card_test.cc"],
    visibility = ["//visibility:public"],
    deps = ["card"],
)

cc_library(
    name = "deck",
    srcs = ["deck.cc"],
    hdrs = ["deck.h"],
    visibility = ["//visibility:public"],
    deps = ["card"],
)

cc_test(
    name = "deck_test",
    srcs = ["deck_test.cc"],
    visibility = ["//visibility:public"],
    deps = ["deck"],
)

cc_library(
    name = "hand",
    srcs = ["hand.cc"],
    hdrs = ["hand.h"],
    visibility = ["//visibility:public"],
    deps = [
        "card",
        "deck",
    ],
)

cc_test(
    name = "hand_test",
    srcs = ["hand_test.cc"],
    visibility = ["//visibility:public"],
    deps = ["hand"],
)

cc_library(
    name = "pile",
    srcs = ["pile.cc"],
    hdrs = ["pile.h"],
    visibility = ["//visibility:public"],
    deps = [
        "card",
    ],
)

cc_test(
    name = "pile_test",
    srcs = ["pile_test.cc"],
    visibility = ["//visibility:public"],
    deps = ["pile"],
)

cc_library(
    name = "tableau",
    srcs = ["tableau.cc"],
    hdrs = ["tableau.h"],
    visibility = ["//visibility:public"],
    deps = [
        "card",
        "@com_google_absl//absl/strings",
    ],
)

cc_test(
    name = "tableau_test",
    srcs = ["tableau_test.cc"],
    visibility = ["//visibility:public"],
    deps = ["tableau"],
)

cc_library(
    name = "player",
    hdrs = ["player.h"],
    visibility = ["//visibility:public"],
    deps = [
        "card",
        "deck",
        "hand",
        "pile",
        "tableau",
    ],
)

cc_library(
    name = "player-console",
    srcs = ["player-console.cc"],
    hdrs = ["player-console.h"],
    visibility = ["//visibility:public"],
    deps = [
        "card",
        "deck",
        "hand",
        "pile",
        "player",
        "tableau",
    ],
)

cc_library(
    name = "player-dumb",
    srcs = ["player-dumb.cc"],
    hdrs = ["player-dumb.h"],
    visibility = ["//visibility:public"],
    deps = [
        "card",
        "deck",
        "hand",
        "pile",
        "player",
        "tableau",
    ],
)

cc_library(
    name = "game-state",
    srcs = ["game-state.cc"],
    hdrs = ["game-state.h"],
    visibility = ["//visibility:public"],
    deps = [
        "card",
        "deck",
        "hand",
        "pile",
        "player",
        "player-console",
        "player-dumb",
        "tableau",
    ],
)

cc_binary(
    name = "lost-cities-genalg",
    srcs = ["main.cc"],
    deps = [
        "game-state",
        "player-dumb",
    ],
)
