QT       += core gui

# Add ******************************************************
INCLUDEPATH += D:\Develop\python\include
LIBS += -LD:\Develop\python\libs -lpython312
# **********************************************************

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    evaluatewindow.cpp \
    main.cpp \
    mainwindow.cpp \
    predictwindow.cpp \
    processevalutionwindow.cpp \
    trainwindow.cpp

HEADERS += \
    evaluatewindow.h \
    mainwindow.h \
    predictwindow.h \
    processevalutionwindow.h \
    trainwindow.h

FORMS += \
    evaluatewindow.ui \
    mainwindow.ui \
    predictwindow.ui \
    processevalutionwindow.ui \
    trainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
    res/algorithm/algorithmEvaluationMethodTotalFile.py \
    res/algorithm/algorithmTotalFile.py \
    res/scripts/cross_validation.py \
    res/scripts/data_preprocessing.py \
    res/scripts/evaluation.py \
    res/scripts/feature_combinations.py \
    res/scripts/main.py \
    res/scripts/model_training.py \
    res/scripts/models.py \
    res/system/algorithmEvaluationMethodNames.txt \
    res/system/algorithmNames.txt

RESOURCES += \
    res.qrc
