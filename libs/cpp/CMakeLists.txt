add_library(cppgen INTERFACE)
target_compile_features(cppgen INTERFACE cxx_std_20)
target_include_directories(cppgen INTERFACE include)
