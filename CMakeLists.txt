cmake_minimum_required( VERSION 3.1 )

project( Rendering-Pipeline )

find_package( OpenGL REQUIRED )

include_directories( ${OPENGL_INCLUDE_DIRS} )

set( GLFW_BUILD_DOCS OFF CACHE BOOL  "GLFW lib only" )
set( GLFW_INSTALL OFF CACHE BOOL  "GLFW lib only" )

add_subdirectory( Dependencies/glfw )

if( MSVC )
    SET( CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} /ENTRY:mainCRTStartup" )
endif()

set( Rendering-Pipeline-Src
     Rendering-Pipeline/Main.cpp
     )
     
add_executable( Rendering-Pipeline WIN32 ${Rendering-Pipeline-Src} )
target_compile_features(Rendering-Pipeline PRIVATE cxx_std_17)
target_link_libraries( Rendering-Pipeline ${OPENGL_LIBRARIES} glfw )
if( MSVC )
    if(${CMAKE_VERSION} VERSION_LESS "3.6.0") 
        message( "\n\t[ WARNING ]\n\n\tCMake version lower than 3.6.\n\n\t - Please update CMake and rerun; OR\n\t - Manually set 'Rendering-Pipeline' as StartUp Project in Visual Studio.\n" )
    else()
        set_property( DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} PROPERTY VS_STARTUP_PROJECT Rendering-Pipeline )
    endif()
endif()

# EVERYTHING PAST THIS POINT WAS ADDED==================================================================================================================================

# ASSIMP #
option(ASSIMP_BUILD_ASSIMP_TOOLS OFF)
option(ASSIMP_BUILD_SAMPLES OFF)
option(ASSIMP_BUILD_TESTS OFF)
option(BUILD_SHARED_LIBS OFF)
add_subdirectory(Dependencies/assimp)

include_directories(Dependencies/assimp/include)
target_link_libraries(Rendering-Pipeline assimp)

# STBi #
include_directories(Dependencies/stb)

# glm #
include_directories(Dependencies/glm)

# entt #
include_directories(Dependencies/entt/src)

# imgui #
include_directories(Dependencies/imgui)
