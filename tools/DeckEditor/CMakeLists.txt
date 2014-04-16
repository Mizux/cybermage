project(DeckEditor)

include_directories("Include")

# Qt Setting
find_package(Qt4 COMPONENTS QtCore QtGui REQUIRED)
include(${QT_USE_FILE})
add_definitions(${QT_DEFINITIONS})

file(GLOB_RECURSE _HDRS Include/*.h)
file(GLOB_RECURSE _SRCS Source/*.cpp)

add_executable(${PROJECT_NAME} ${_HDRS} ${_SRCS})
