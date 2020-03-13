#设置可执行文件名称
set(BIN_NAME gtest_demo)
set(CMAKE_CXX_FLAGS "-pthread ${CMAKE_CXX_FLAGS}")
#头文件路径
include_directories(../inc/func
                    )
#源文件路径
aux_source_directory(./func FUNC_SRC_LISTS)
aux_source_directory(./funcTest FUNCTEST_SRC_LISTS)
aux_source_directory(./ MAIN_SRC_LISTS)
#库文件路径
link_directories(${PROJECT_SOURCE_DIR}/lib)
#要生成的可执行文件名及其依赖的源文件
add_executable(${BIN_NAME} ${FUNC_SRC_LISTS} ${FUNCTEST_SRC_LISTS} ${MAIN_SRC_LISTS})
#要生成的可执行文件名及其依赖的库文件
target_link_libraries(${BIN_NAME} gtest)
#设置可执行文件生成路径
set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)
#set install dir
if(CMAKE_INSTALL_PREFIX) 
    message("CMAKE_INSTALL_PREFIX:${CMAKE_INSTALL_PREFIX}")
else()
    set(CMAKE_INSTALL_PREFIX /usr/local)
endif()
install(TARGETS ${BIN_NAME}
        RUNTIME DESTINATION bin)
