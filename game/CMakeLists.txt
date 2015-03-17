project(Arcomage)

# BOOST
find_package(Boost REQUIRED COMPONENTS system filesystem regex thread)
link_directories(${Boost_LIBRARY_DIRS})
include_directories(${Boost_INCLUDE_DIRS})

# SDL
find_package(SDL REQUIRED)
include_directories(SYSTEM ${SDL_INCLUDE_DIR})
find_package(SDL_image REQUIRED)
include_directories(SYSTEM ${SDLIMAGE_INCLUDE_DIR})
find_package(SDL_ttf REQUIRED)
include_directories(SYSTEM ${SDLTTF_INCLUDE_DIR})
find_package(SDL_mixer REQUIRED)
include_directories(SYSTEM ${SDLMIXER_INCLUDE_DIR})

# LUA
find_package(Lua51 REQUIRED)
include_directories(SYSTEM ${LUA_INCLUDE_DIR})

# Minizip
include_directories(SYSTEM ${minizip_INCLUDE_DIRS})

include_directories(Include Include/txml Include/Lua Include/System Include/UI)
file(GLOB_RECURSE _HDRS Include *.h *.cpp)
file(GLOB_RECURSE _SRCS Source *.cpp)

add_executable(${PROJECT_NAME} ${_HDRS} ${_SRCS})
target_link_libraries(
  ${PROJECT_NAME} minizip
  ${Boost_LIBRARIES}
  ${SDL_LIBRARY} ${SDLIMAGE_LIBRARY} ${SDLTTF_LIBRARY} ${SDLMIXER_LIBRARY} ${SDLMAIN_LIBRARY}
  ${LUA_LIBRARIES}
)


