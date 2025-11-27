cmake_minimum_required(VERSION 3.13 FATAL_ERROR)


project(APPLOG VERSION 0.1.0
        DESCRIPTION "Yet another application logging/journal tool"
        LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(WORK "applog")
set(TARGET_DIR ${WORK})




#if(${CMAKE_VERSION} VERSION_GREATER_EQUAL "3.11.0")
file(GLOB_RECURSE HEADERS CONFIGURE_DEPENDS  include/${TARGET_DIR}/*.h) # note: append any other non-.h header
file(GLOB_RECURSE SOURCES CONFIGURE_DEPENDS  c/*.cxx)
#else()
#    file(GLOB HEADERS ${TARGET_DIR}/*.h) # note: append any other non-.h header
#    file(GLOB_RECURSE SOURCES  ${WORK}/c/*.cxx)
#endif()
#message("Headers: " ${HEADERS})


#set(HEADERS
#    ${TARGET_DIR}/defaults.h
#    ${TARGET_DIR}/lang.h
#    ${TARGET_DIR}/lexer.h
#    ${TARGET_DIR}/strscan.h
#    ${TARGET_DIR}/strscan.numeric_data.value.h
#    ${TARGET_DIR}/token_rec.h
#)


add_library(${WORK} STATIC

    ${HEADERS}
    ${SOURCES}
)

target_include_directories(${WORK} PUBLIC
                           $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include/>
                           $<INSTALL_INTERFACE:include/${PROJECT_NAME}/>
)






message("build and include dir:" ${CMAKE_CURRENT_SOURCE_DIR}/include/${WORK})
#set_target_properties(${WORK} PROPERTIES OUTPUT_NAME ${FRAME}.${WORK})



target_compile_definitions("${WORK}" PUBLIC "${WORK}_DEBUG=$<CONFIG:Debug>")
include(GenerateExportHeader)
generate_export_header(${WORK} EXPORT_FILE_NAME "${WORK}_export")

IF (EXISTS "${CMAKE_CURRENT_BINARY_DIR}/compile_commands.json")
    EXECUTE_PROCESS(COMMAND ${CMAKE_COMMAND} -E copy_if_different
                    ${CMAKE_CURRENT_BINARY_DIR}/compile_commands.json
    )
ENDIF ()


target_link_libraries(${WORK} ${CMAKE_DL_LIBS} sqlite3) # and other system dependencies...





install(TARGETS ${WORK}
        EXPORT ${WORK}
        LIBRARY DESTINATION lib
        ARCHIVE DESTINATION lib
        RUNTIME DESTINATION bin
)

INSTALL(FILES ${HEADERS} DESTINATION ${CMAKE_INSTALL_PREFIX}/include/${TARGET_DIR})


add_custom_target("uninstall_${WORK}" COMMENT "Uninstall installed files")
add_custom_command(
    TARGET "uninstall_${WORK}"
    POST_BUILD
    COMMENT "Uninstall ${WORK} files under include and lib"
    COMMAND rm -vrf ${CMAKE_INSTALL_PREFIX}/include/${WORK} ${CMAKE_INSTALL_PREFIX}/lib/lib${WORK}*.* || echo Nothing in install_manifest.txt to be uninstalled!
)

add_executable(app.exe c/main.cxx)
target_link_libraries(app.exe applog)
#add_subdirectory(test.app)
