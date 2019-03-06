# Visibility:  please choose a more appropriate default for the package,
# and update any rules that should be different.
# See: http://goto/package-visibility
package(default_visibility = ["//visibility:legacy_public"])

# The runnable program lists the source file because we use main()
# and itself as a library because everything else is our namespace
py_binary(name = "machinewords",
          srcs = ["machinewords.py",
                  ],
          deps = [":machinewords_lib",
                  ],
          )

# Declare the source file as a library and specify its dependencies
py_library(name = "machinewords_lib",
           srcs = ["machinewords.py",
                   ],
           deps = ["//pyglib",
                   "//production/mdb:mdbclient",
                   ],
           )

# Unit tests tend to depend on the library and the test framework
py_test(name = "machinewords_test",
        srcs = ["machinewords_test.py",
                ],
        deps = [":machinewords_lib",
                "//testing/pybase",
                "//third_party/py/mox:mox",
                ],
        )

# Unit tests tend to depend on the library and the test framework
py_test(name = "student_test",
        srcs = ["student_test.py",
                ],
        deps = ["//codelab/pyquick/mdbregex:machinewords_lib",
                "//testing/pybase",
                "//third_party/py/mox:mox",
                ],
        )
