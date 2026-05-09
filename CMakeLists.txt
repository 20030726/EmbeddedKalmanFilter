cmake_minimum_required(VERSION 3.16)
project(EmbeddedKalmanFilter VERSION 0.1.0 LANGUAGES C CXX)

include(CTest)

add_library(embedded_kalman_filter STATIC
    src/kf.c
    src/ekf.c
    src/ukf.c
)

target_include_directories(embedded_kalman_filter
    PUBLIC include
)

if(BUILD_TESTING)
    add_executable(embedded_kalman_filter_smoke_tests
        tests/smoke_test.cpp
    )
    target_link_libraries(embedded_kalman_filter_smoke_tests PRIVATE embedded_kalman_filter)
    target_compile_features(embedded_kalman_filter_smoke_tests PRIVATE cxx_std_17)

    add_test(NAME embedded_kalman_filter_smoke_tests COMMAND embedded_kalman_filter_smoke_tests)
endif()
