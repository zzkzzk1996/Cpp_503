cmake_minimum_required(VERSION 3.12)
project(Final_Project)

set(CMAKE_CXX_STANDARD 14)

#set(INC_DIR /Users/zekunzhang/Applications/MATLAB_R2018b.app/include)
#set(LINK_DIR /Users/zekunzhang/Applications/MATLAB_R2018b.app/lib)
#
#include_directories(${INC_DIR})
#link_directories(${LINK_DIR})
#link_libraries(libmx.lib, libmex.lib, libeng.lib)

add_executable(Final_Project Main_Zekun.cpp Account_Zekun.cpp Account_Zekun.h StockAccount_Zekun.cpp StockAccount_Zekun.h BankAccount_Zekun.cpp BankAccount_Zekun.h Linkedlist_Zekun.cpp Linkedlist_Zekun.h Sort_Zekun.cpp Sort_Zekun.h Filer_Zekun.cpp Filer_Zekun.h Timer_Zekun.cpp Timer_Zekun.h StockAccount_Matlab_Zekun.cpp Node_Zekun.h)

#target_link_libraries(StockAccount_Zekun.h libmx.lib libmex.lib, libeng.lib)