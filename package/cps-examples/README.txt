For separate build

cmake -G "Visual Studio 17 2022" -DCMAKE_TOOLCHAIN_FILE="C:/vcpkg/scripts/buildsystems/vcpkg.cmake" -DCMAKE_INSTALL_PREFIX=../install/zwrap ../../src/cmake/zdemo/zwrap

// CMAKE_PREFIX_PATH does not support relative paths
https://gitlab.kitware.com/cmake/cmake/-/issues/16644
# cmake -G "Visual Studio 17 2022" -DCMAKE_TOOLCHAIN_FILE="C:/vcpkg/scripts/buildsystems/vcpkg.cmake" -DCMAKE_PREFIX_PATH="${CMAKE_CURRENT_BINARY_DIR}/../install/zwrap" -Wno-dev ../../src/cmake/zdemo/ztest
cmake -G "Visual Studio 17 2022" -DCMAKE_TOOLCHAIN_FILE="C:/vcpkg/scripts/buildsystems/vcpkg.cmake" -Wno-dev ../../src/cmake/zdemo/ztest