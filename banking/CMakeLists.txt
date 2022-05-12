cmake_minimum_required(VERSION 3.0)
project(banking)
file(GLOB CPPS "*.cpp")
add_library(banking STATIC ${CPPS} "Account.h" "Transaction.h")
