add_executable(nts 
    main.cpp
    InputComponent.cpp
    OutputComponent.cpp
    ClockComponent.cpp
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
    Gate4069.cpp
    Gate4071.cpp
    Gate4081.cpp
)
target_include_directories(nts PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})
target_include_directories(nts PRIVATE ${PROJECT_SOURCE_DIR}/include)

set_target_properties(nts PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/bin
)