
# Visibility:  please choose a more appropriate default for the package,
# and update any rules that should be different.
# See: http://goto/package-visibility
package(default_visibility = ["//visibility:legacy_public"])

## Quote example -- this part of the BUILD is complete and functional.

## For python, this makes a schwag_pb module.
proto_library(name = "schwag_proto",
              py_api_version = 1,
              cc_api_version = 1,
              java_api_version = 1,
              srcs = [ "schwag.proto" ],
              )
              
## Module quote_lib containing the Quote class
py_library(name = "quote_lib",
           srcs = ["quote_lib.py"],
           deps = [":schwag_proto",
                   "//pyglib",  ## basic google python: app, flags, logging
                   
                   ## google3 file on local and gfs filesystems
                   "//file/base:pywrapfile",
                   "//file/localfile",
                   "//file/gfs",
                   ]
          )

## Test code for Quote class
py_test(name = "quote_lib_test",
        srcs = ["quote_lib_test.py" ],
        deps = [":quote_lib",
                "//pyglib", 
                "//testing/pybase",
                ],
        )

## Main() that calls Quote
py_binary(name = "quote",
          srcs = ["quote.py" ],
          deps = [":quote_lib",
                  "//pyglib",
                ],
        )

# =========================================================

## Image Puzzle exercise
## +++Your Code+++
## Fill in the deps sections.

## Image puzzle lib
py_library(name = "imagepuzzle_lib",
          srcs = ["imagepuzzle_lib.py",
                  ],
          deps = [
                  ],
          )


## Image puzzle main()
py_binary(name = "imagepuzzle",
          srcs = ["imagepuzzle.py",
                  ],
          deps = [
                  ],
          )

## For python, this makes a twitter_pb module
## (this works as is)
proto_library(name = "twitter_proto",
              py_api_version = 1,
              cc_api_version = 1,
              java_api_version = 1,
              srcs = [ "twitter.proto" ],
              )
