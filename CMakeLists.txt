
cmake_minimum_required(VERSION 2.8)
project(Jac3D)

set(GLES_ROOT ${CMAKE_SOURCE_DIR})

if(WIN32)
   SET(WINDOWS_BIT win32)
 else()
   SET(WINDOWS_BIT win64)
 endif()
 
 if(GLES2)
    set(BINARY_GLES2 ${GLES_ROOT}/External//lib/${WINDOWS_BIT}/libGLESv2.dll)
    set(BINARY_EGL   ${GLES_ROOT}/External/lib/${WINDOWS_BIT}/libEGL.dll)

 else(GLES3)
    set(BINARY_GLES3 ${GLES_ROOT}/External//lib/${WINDOWS_BIT}/libGLESv2.dll)
    set(BINARY_EGL   ${GLES_ROOT}/External/lib/${WINDOWS_BIT}/libEGL.dll)
endif()

include_directories(
	External/include
	External/glm-0.9.6.3
)
link_directories(
	${GLES_ROOT}/External/lib/${WINDOWS_BIT}
)

set(LIBRARY_GLES3 libGLESv2)
set(LIBRARY_EGL   libEGL)


#framework Library
set(FRAMEWORK_LIBRARY Engine)
add_subdirectory(Source/Engine)

#samples
add_subdirectory(Samples/CreateWindow)
