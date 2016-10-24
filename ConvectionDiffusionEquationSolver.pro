TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

unix: CONFIG += link_pkgconfig
unix: PKGCONFIG += gsl

SOURCES += main.cpp \
    limiters/Limiter.cpp \
    limiters/LimiterN2.cpp \
    limiters/LimiterN2BM.cpp \
    limiters/LimiterN3.cpp \
    limiters/LimiterN3BM.cpp \
    limiters/MUSCLLimiter.cpp \
    limiters/MUSCLLimiterBM.cpp \
    streams/GodunovStream.cpp \
    streams/Stream.cpp \
    support/Conditions.cpp \
    support/FileWriter.cpp \
    support/MyMath.cpp \
    support/Problem.cpp \
    support/Solver.cpp \
    support/State.cpp \
    systemMakers/GalerkinSystemMaker.cpp \
    systemMakers/SystemMaker.cpp \
    systemSolvers/EulerSystemSolver.cpp \
    systemSolvers/RungeKuttaSystemSolver.cpp \
    systemSolvers/SystemSolver.cpp \
    support/Polynomial.cpp \
    support/InitialState.cpp \
    streams/EOStream.cpp \
    streams/LFStream.cpp

HEADERS += \
    limiters/Limiter.h \
    limiters/LimiterN2.h \
    limiters/LimiterN2BM.h \
    limiters/LimiterN3.h \
    limiters/LimiterN3BM.h \
    limiters/MUSCLLimiter.h \
    limiters/MUSCLLimiterBM.h \
    streams/GodunovStream.h \
    streams/Stream.h \
    support/Conditions.h \
    support/FileWriter.h \
    support/MyMath.h \
    support/Problem.h \
    support/Solver.h \
    support/State.h \
    systemMakers/GalerkinSystemMaker.h \
    systemMakers/SystemMaker.h \
    systemSolvers/EulerSystemSolver.h \
    systemSolvers/RungeKuttaSystemSolver.h \
    systemSolvers/SystemSolver.h \
    support/Polynomial.h \
    support/InitialState.h \
    streams/EOStream.h \
    streams/LFStream.h

