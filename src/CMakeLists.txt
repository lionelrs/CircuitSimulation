add_executable(nts 
    main.cpp
    AndComponent.cpp
    NandComponent.cpp
    FalseComponent.cpp
    TrueComponent.cpp
    NotComponent.cpp
    OrComponent.cpp
    XorComponent.cpp
    NorComponent.cpp
    Gate4001.cpp
    Gate4011.cpp
    Gate4030.cpp
)
target_include_directories(nts PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})
target_include_directories(nts PRIVATE ${PROJECT_SOURCE_DIR}/include)

set_target_properties(nts PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/bin
)