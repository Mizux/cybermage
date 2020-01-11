project(CyberMage)

#####################
##  DOCUMENTATION  ##
#####################
add_subdirectory(doc)

###################
##  COMPILATION  ##
###################
# Qt Setting
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTORCC ON)
find_package(Qt5Core REQUIRED)
find_package(Qt5Gui REQUIRED)
find_package(Qt5Widgets REQUIRED)
find_package(Qt5Qml REQUIRED)

file(GLOB_RECURSE _HDRS include *.hpp)
file(GLOB_RECURSE _SRCS src *.hpp *.cpp)
file(GLOB_RECURSE _QRCS data *.qrc)

add_executable(${PROJECT_NAME} ${_HDRS} ${_SRCS} ${_QRCS})
target_link_libraries(${PROJECT_NAME} PRIVATE Qt5::Core Qt5::Gui Qt5::Widgets Qt5::Qml)
target_include_directories(${PROJECT_NAME} PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
    $<INSTALL_INTERFACE:include>)

if(ENABLE_TESTING)
#  add_subdirectory(test)
endif()

install(
  TARGETS ${PROJECT_NAME}
  EXPORT CybermageTargets
  DESTINATION bin)
