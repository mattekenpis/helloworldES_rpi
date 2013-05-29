# Make sure the compiler can find include files from our Hello library. 
include_directories (${HELLO_SOURCE_DIR}/Hello) 
include_directories (/opt/vc/include) 
include_directories (/opt/vc/include/interface/vcos/pthreads)
include_directories (/usr/include/SDL)

# Make sure the linker can find the Hello library once it is built. 
link_directories (${HELLO_BINARY_DIR}/Hello) 
link_directories (/opt/vc/lib) 

# Add executable called "helloDemo" that is built from the source files 
# "demo.cxx" and "demo_b.cxx". The extensions are automatically found. 
add_executable (helloDemo demo.cxx demo_b.cxx) 


find_package(SDL REQUIRED)
include_directories(${SDL_INCLUDE_DIR})
target_link_libraries (helloDemo ${SDL_LIBRARY})

# Link the executable to the Hello library. 
target_link_libraries (helloDemo GLESv2 EGL)
target_link_libraries (helloDemo Hello) 
