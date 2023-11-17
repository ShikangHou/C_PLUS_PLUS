project(OOP)


include_directories(template_func_class/include)
# message(${CMAKE_SOURCE_DIR}/template_func_class/include)
add_executable(template_func_class template_func_class/src/main.cpp template_func_class/src/myswap_int.cpp)

add_executable(copy_constructors copy_constructors/main.cpp)

add_executable(operator_overloading operator_overloading/main.cpp)

add_executable(virtual_function virtual_function/main.cpp)

add_executable(friend_functions_classes friend_functions_classes/main.cpp)