# Install script for directory: /home/fabien/Documents/github/goodnightkiss1972/learnC/tdd/cmocka_ubuntu/cmocka-1.1.5

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "/usr")
endif()
string(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
if(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  if(BUILD_TYPE)
    string(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  else()
    set(CMAKE_INSTALL_CONFIG_NAME "Debug")
  endif()
  message(STATUS "Install configuration: \"${CMAKE_INSTALL_CONFIG_NAME}\"")
endif()

# Set the component getting installed.
if(NOT CMAKE_INSTALL_COMPONENT)
  if(COMPONENT)
    message(STATUS "Install component: \"${COMPONENT}\"")
    set(CMAKE_INSTALL_COMPONENT "${COMPONENT}")
  else()
    set(CMAKE_INSTALL_COMPONENT)
  endif()
endif()

# Install shared libraries without execute permission?
if(NOT DEFINED CMAKE_INSTALL_SO_NO_EXE)
  set(CMAKE_INSTALL_SO_NO_EXE "1")
endif()

# Is this installation the result of a crosscompile?
if(NOT DEFINED CMAKE_CROSSCOMPILING)
  set(CMAKE_CROSSCOMPILING "FALSE")
endif()

# Set default install directory permissions.
if(NOT DEFINED CMAKE_OBJDUMP)
  set(CMAKE_OBJDUMP "/usr/bin/objdump")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xpkgconfigx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/x86_64-linux-gnu/pkgconfig" TYPE FILE FILES "/home/fabien/Documents/github/goodnightkiss1972/learnC/tdd/cmocka_ubuntu/cmocka-1.1.5/cmake/cmocka.pc")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xdevelx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/x86_64-linux-gnu/cmake/cmocka" TYPE FILE FILES
    "/home/fabien/Documents/github/goodnightkiss1972/learnC/tdd/cmocka_ubuntu/cmocka-1.1.5/cmake/cmocka-config.cmake"
    "/home/fabien/Documents/github/goodnightkiss1972/learnC/tdd/cmocka_ubuntu/cmocka-1.1.5/cmake/cmocka-config-version.cmake"
    )
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for each subdirectory.
  include("/home/fabien/Documents/github/goodnightkiss1972/learnC/tdd/cmocka_ubuntu/cmocka-1.1.5/cmake/include/cmake_install.cmake")
  include("/home/fabien/Documents/github/goodnightkiss1972/learnC/tdd/cmocka_ubuntu/cmocka-1.1.5/cmake/src/cmake_install.cmake")
  include("/home/fabien/Documents/github/goodnightkiss1972/learnC/tdd/cmocka_ubuntu/cmocka-1.1.5/cmake/doc/cmake_install.cmake")
  include("/home/fabien/Documents/github/goodnightkiss1972/learnC/tdd/cmocka_ubuntu/cmocka-1.1.5/cmake/example/cmake_install.cmake")

endif()

if(CMAKE_INSTALL_COMPONENT)
  set(CMAKE_INSTALL_MANIFEST "install_manifest_${CMAKE_INSTALL_COMPONENT}.txt")
else()
  set(CMAKE_INSTALL_MANIFEST "install_manifest.txt")
endif()

string(REPLACE ";" "\n" CMAKE_INSTALL_MANIFEST_CONTENT
       "${CMAKE_INSTALL_MANIFEST_FILES}")
file(WRITE "/home/fabien/Documents/github/goodnightkiss1972/learnC/tdd/cmocka_ubuntu/cmocka-1.1.5/cmake/${CMAKE_INSTALL_MANIFEST}"
     "${CMAKE_INSTALL_MANIFEST_CONTENT}")
