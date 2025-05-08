TEMPLATE = app
CONFIG += console c++17
CONFIG -= app_bundle
CONFIG -= qt

INCLUDEPATH += ./gtest/include \
            += ./util/         \

CURRENT_PATH = $$PWD

LIBS += -L $$CURRENT_PATH/gtest/lib \

LIBS += -lgtest \
        -lgmock



SOURCES += \
        LeetCode201_250/SubArray_209.cpp \
        LeetCode500_550/500_510.cpp \
        LeetCode_ByFunctionType/Array1.cpp \
        LeetCode_ByFunctionType/DP1.cpp \
        LeetCode_ByFunctionType/Hash.cpp \
        LeetCode_ByFunctionType/Linkedlist.cpp \
        LeetCode_ByFunctionType/SlidingWindow.cpp \
        huawei_od/CpuAllocate.cpp \
        huawei_od/MiddleListNode.cpp \
        huawei_od/MostColorCar.cpp \
        huawei_od/NotContain101.cpp \
        huawei_od/NucleicAcidTesters.cpp \
        huawei_od/StringReRangeAndReOrder.cpp \
        huawei_od/logsystem.cpp \
        huawei_od/perfectPosition.cpp \
        huawei_od/schoolPlace.cpp \
        huawei_od/task_mixed_scheduling.cpp \
        huawei_od/wordReverse.cpp \
        main.cpp \
        util/stringUtil.cpp

HEADERS += \
    LeetCode_ByFunctionType/Linkedlist.h \
    util/stringUtil.h
