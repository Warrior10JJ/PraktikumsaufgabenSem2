cmake_minimum_required(VERSION 4.2)
project(Praktikum)

set(CMAKE_CXX_STANDARD 17)
set(BOOST_ROOT "C:/boost_1_90_0/")


include_directories(${BOOST_ROOT})


add_executable(pa1
            #pa1/pa1_main.cpp
            pa1/ufosim.cpp
            pa1/ufosim.h
            pa1/vertical.cpp
            pa1/vertical.h
        pa3/pa3_utest.cpp
)
#
#include <boost/test/unit_test.hpp>
#muss in jede boost geändert werden

add_executable(pa2
        #pa2/pa2_main.cpp
        pa2/vertical.h
        pa2/vertical.cpp
        pa2/ufo.h
        pa2/ufo.cpp
        pa2/ufosim.h
        pa2/ufosim.cpp
        pa2/ballistic.cpp
        pa2/ballistic.h
        pa2/pa2_main.cpp


)


#unit Tests keine main class

add_executable(pa1_ut
        test_runner.cpp
        pa1/pa1_utest.cpp
        pa1/ufosim.cpp
        pa1/ufosim.h
        pa1/vertical.cpp
        pa1/vertical.h
)

add_executable(pa2_ut
        test_runner.cpp
        pa2/vertical.cpp
        pa2/vertical.h
        pa2/pa2_utest.cpp
        pa2/ufo.cpp
        pa2/ufo.h
        pa2/ufosim.h
        pa2/ufosim.cpp
        pa2/ballistic.cpp
        pa2/ballistic.h
)









target_include_directories(pa1_ut PRIVATE ${BOOST_ROOT})
#target_include_directories(pa2_ut PRIVATE ${BOOST_ROOT})


