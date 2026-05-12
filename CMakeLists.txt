cmake_minimum_required(VERSION 4.2)
project(Praktikum)

set(CMAKE_CXX_STANDARD 17)
set(BOOST_ROOT "C:/boost_1_90_0/")


include_directories(${BOOST_ROOT})

add_executable(inclass
        inclassuebung/sortetdata.cpp
)
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

add_executable(pa3
        pa3/vertical.cpp
        pa3/vertical.h
        pa3/ufo.cpp
        pa3/ufo.h
        pa3/ufosim.h
        pa3/ufosim.cpp
        pa3/ballistic.cpp
        pa3/ballistic.h
        pa3/route.cpp
        pa3/route.h
        #pa3/pa3_main.cpp
)

add_executable(pa4
        pa4/vertical.cpp
        pa4/vertical.h
        pa4/ufo.cpp
        pa4/ufo.h
        pa4/ufosim.h
        pa4/ufosim.cpp
        pa4/ballistic.cpp
        pa4/ballistic.h
        pa4/route.cpp
        pa4/route.h
        pa4/ufo_thread.cpp
        pa4/ufo_thread.h
        #pa4/pa4_main.cpp
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

add_executable(pa3_ut
        test_runner.cpp
        pa3/vertical.cpp
        pa3/vertical.h
        pa3/pa3_utest.cpp
        pa3/ufo.cpp
        pa3/ufo.h
        pa3/ufosim.h
        pa3/ufosim.cpp
        pa3/ballistic.cpp
        pa3/ballistic.h
        pa3/route.cpp
        pa3/route.h
)

add_executable(pa4_ut
        test_runner.cpp
        pa4/vertical.cpp
        pa4/vertical.h
        pa4/pa4_utest.cpp
        pa4/ufo.cpp
        pa4/ufo.h
        pa4/ufosim.h
        pa4/ufosim.cpp
        pa4/ballistic.cpp
        pa4/ballistic.h
        pa4/route.cpp
        pa4/route.h
        pa4/ufo_thread.cpp
        pa4/ufo_thread.h
)





target_include_directories(pa1_ut PRIVATE ${BOOST_ROOT})
#target_include_directories(pa2_ut PRIVATE ${BOOST_ROOT})


