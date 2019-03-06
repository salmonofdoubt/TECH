# Visibility:  please choose a more appropriate default for the package,
# and update any rules that should be different.
# See: http://goto/package-visibility
package(default_visibility = ["//visibility:legacy_public"])

## Image puzzle lib
py_library(name = "imagepuzzle_lib",
          srcs = ["imagepuzzle_lib.py",
                  ],
          deps = ["//codelab/pyquick/accelerated:twitter_proto",
                  "//pyglib",
                  
                  ## google3 file on local and gfs filesystems
                  "//file/base:pywrapfile",
                  "//file/localfile",
                  "//file/gfs",
                  ],
          )


## Image puzzle test
py_test(name = "imagepuzzle_lib_test",
        srcs = ["imagepuzzle_lib_test.py" ],
        deps = [":imagepuzzle_lib",
                "//pyglib",
                "//testing/pybase",
                ],
        )


## Image puzzle main()
py_binary(name = "imagepuzzle",
          srcs = ["imagepuzzle.py",
                  ],
          deps = [":imagepuzzle_lib",
                  "//pyglib",
                  "//file/base:pywrapfile",
                  ],
          )
