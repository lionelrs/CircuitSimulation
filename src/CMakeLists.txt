add_executable(nts main.cpp)
target_include_directories(nts PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})
target_include_directories(nts PRIVATE ${PROJECT_SOURCE_DIR}/include)

set_target_properties(nts PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/bin
)