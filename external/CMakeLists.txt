if(MSVC AND NOT "${MSVC_VERSION}" LESS 1400)
    add_definitions( "/MP" )
endif()


add_definitions(
    -DTW_STATIC
    -DTW_NO_LIB_PRAGMA
    -DTW_NO_DIRECT3D
    -DGLEW_STATIC
    -D_CRT_SECURE_NO_WARNINGS
)

### GLFW ###

add_subdirectory (glfw-3.0.3)

include_directories(
    glfw-3.0.3/include/GLFW/
    glad/include/glad/
    assimp/include/
)

if(${CMAKE_SYSTEM_NAME} MATCHES "Linux")
set(OPENGL_LIBRARY
    ${OPENGL_LIBRARY}
    -lGL -lGLU -lXrandr -lXext -lX11 -lrt
    ${CMAKE_DL_LIBS}
    ${GLFW_LIBRARIES}
)
elseif(${CMAKE_SYSTEM_NAME} MATCHES "Darwin")
set(OPENGL_LIBRARY
    ${OPENGL_LIBRARY}
    ${CMAKE_DL_LIBS}
    ${GLFW_LIBRARIES}
)
endif(${CMAKE_SYSTEM_NAME} MATCHES "Linux")

### glad ###

set(GLAD_SOURCE
    glad/src/glad.c
)

set(GLAD_HEADERS

)


add_library( GLAD STATIC
    ${GLAD_SOURCE}
    ${GLAD_INCLUDE}
)

target_link_libraries(GLAD
    ${OPENGL_LIBRARY}
    ${EXTRA_LIBS}
)

### ASSIMP ###

set(ZLIB_LIBRARIES zlibstatic)
set(ENABLE_BOOST_WORKAROUND ON)
set(BUILD_STATIC_LIB ON)
set(BUILD_ASSIMP_TOOLS  ON)
set(ASSIMP_BUILD_STATIC_LIB ON)

add_subdirectory (assimp-3.3.1)
