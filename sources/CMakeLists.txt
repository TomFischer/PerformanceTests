CMAKE_MINIMUM_REQUIRED (VERSION 2.6)

PROJECT(PerformanceTests)

### For GNU C/CXX
IF(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_COMPILER_IS_GNUCC)
        IF( NOT CMAKE_BUILD_TYPE STREQUAL "Debug" )
                MESSAGE(STATUS "Set GCC release flags")
                SET(CMAKE_CXX_FLAGS "-O3 -funroll-loops -march=native -mtune=native -msse4.2 -DNDEBUG")
        ENDIF()
        # -g
        SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wno-deprecated -Wall -Wextra -fno-nonansi-builtins")
        SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fopenmp")
        ADD_DEFINITIONS(
                -DGCC
        )
ENDIF(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_COMPILER_IS_GNUCC)

ADD_SUBDIRECTORY( Base )

INCLUDE_DIRECTORIES(
        .
        ./Base/
)

ADD_EXECUTABLE(scpr 
	scpr.cpp
)
TARGET_LINK_LIBRARIES(scpr
	Base
)

ADD_EXECUTABLE(PowSqrtTest 
	PowSqrtTest.cpp
)
TARGET_LINK_LIBRARIES(PowSqrtTest
	Base
)
