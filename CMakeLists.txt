cmake_minimum_required(VERSION 3.12)
project(CyberMageMeta VERSION 1.0 LANGUAGES CXX)

# Include file check macros honor CMAKE_REQUIRED_LIBRARIES.
if(POLICY CMP0075)
  cmake_policy(SET CMP0075 NEW)
endif()

# Force default build type to Release
if(NOT CMAKE_BUILD_TYPE)
  set(CMAKE_BUILD_TYPE "Debug" CACHE STRING
    "Choose the type of build, options are: Debug Release RelWithDebInfo MinSizeRel."
    FORCE)
endif(NOT CMAKE_BUILD_TYPE)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
if(APPLE)
  set(CMAKE_INSTALL_RPATH "@loader_path;@loader_path/../lib")
else()
  set(CMAKE_INSTALL_RPATH "$ORIGIN:$ORIGIN/../lib")
endif()

if(UNIX)
  set(CMAKE_BUILD_WITH_INSTALL_RPATH TRUE)
  set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/lib)
  set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/lib)
  set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/bin)
  set(CMAKE_DOCUMENTATION_OUTPUT_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/share/doc)
  option(BUILD_SHARED_LIBS "Build shared libraries(.so or .dylib)." ON)
else()
  # only support for static build on Windows.
  set(BUILD_SHARED_LIBS OFF)
  set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/${CMAKE_BUILD_TYPE}/bin)
  set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/${CMAKE_BUILD_TYPE}/bin)
  set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/${CMAKE_BUILD_TYPE}/bin)
  set(CMAKE_DOCUMENTATION_OUTPUT_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/${CMAKE_BUILD_TYPE}/share/doc)
endif()

include(CTest)
include(FetchContent)
if(BUILD_TESTING)
	#FetchContent_Declare(
  #  googletest
  #  GIT_REPOSITORY https://github.com/google/googletest.git
  #  GIT_TAG release-1.10.0)
  #set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
endif()

add_subdirectory(cybermage)

# Install
include(GNUInstallDirs)
install(
	EXPORT CybermageTargets
	NAMESPACE Cybermage::
	DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/Cybermage
  COMPONENT Devel)
include(CMakePackageConfigHelpers)
configure_package_config_file(cmake/CybermageConfig.cmake.in
	"${PROJECT_BINARY_DIR}/CybermageConfig.cmake"
	INSTALL_DESTINATION "${CMAKE_INSTALL_LIBDIR}/cmake/Cybermage"
  NO_SET_AND_CHECK_MACRO
  NO_CHECK_REQUIRED_COMPONENTS_MACRO)
write_basic_package_version_file(
	"${PROJECT_BINARY_DIR}/CybermageConfigVersion.cmake"
  COMPATIBILITY SameMajorVersion)
install(
  FILES
	"${PROJECT_BINARY_DIR}/CybermageConfig.cmake"
	"${PROJECT_BINARY_DIR}/CybermageConfigVersion.cmake"
	DESTINATION "${CMAKE_INSTALL_LIBDIR}/cmake/Cybermage"
  COMPONENT Devel)
