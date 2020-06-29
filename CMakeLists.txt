cmake_minimum_required(VERSION 3.14)
project(alogrithm)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++17 -g -Wall")
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(SRC_test
        test/leetcode/leetcode_test.h
        test/leetcode/leetcode_test.cpp
        test/leetcode/hash_test.cpp
        test/leetcode/math_test.cpp
        test/leetcode/two-pointer_test.cpp
        test/leetcode/list_test.cpp
        test/leetcode/dc_test.cpp
)

set(SRC_leetcode
        leetcode/data-struct.h

        leetcode/hash/hash.h
        leetcode/hash/two-sum.cpp

        leetcode/math/math.h
        leetcode/math/single-number.cpp

        leetcode/two_pointer/two-pointer.h
        leetcode/two_pointer/happy-number.cpp
        leetcode/two_pointer/three-sum.cpp
        leetcode/two_pointer/longest-substring.cpp

        leetcode/list/list.h
        leetcode/list/add-two-numbers.cpp

        leetcode/dc/dc.h
        leetcode/dc/median-twoSortedArray.cpp
        )

set(SRC_util
        util/util.h
        util/util.cpp
)

set(SRC_main
        main.cpp
)

add_executable(main
        ${SRC_test}
        ${SRC_leetcode}
        ${SRC_main}
        ${SRC_util}
        )

