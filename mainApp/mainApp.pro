#####################################################################################
# Automatically generated by qmake (2.01a) Tue 2. Dec 10:46:50 2014
#####################################################################################
QT        += core gui opengl network
greaterThan(QT_MAJOR_VERSION, 4): QT         += widgets

TEMPLATE = app

greaterThan(QT_MAJOR_VERSION, 4) {
    QT *= printsupport
}

#~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

TARGET +=
DEPENDPATH += .
INCLUDEPATH += .
INCLUDEPATH += ../lc_lib/common ../lc_lib/qt ../quazip ../ldrawini

lessThan(QT_MAJOR_VERSION, 5): CONFIG += precompile_header c++11
greaterThan(QT_MAJOR_VERSION, 4): CONFIG += precompile_header

#~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

win32 {

    PRECOMPILED_HEADER += ../lc_lib/common/lc_global.h
    QMAKE_CXXFLAGS_WARN_ON += -Wno-unused-parameter
    DEFINES += _CRT_SECURE_NO_WARNINGS _CRT_SECURE_NO_DEPRECATE=1 _CRT_NONSTDC_NO_WARNINGS=1
    QMAKE_EXT_OBJ = .obj
    win32:RC_FILE = lpub.rc
    PRECOMPILED_SOURCE = ../lc_lib/common/lc_global.cpp
    CONFIG += windows
    CONFIG += debug_and_release
    LIBS += -ladvapi32 -lshell32
greaterThan(QT_MAJOR_VERSION, 4): LIBS += -lz
greaterThan(QT_MAJOR_VERSION, 4): LIBS += -lopengl32

} else {
        PRECOMPILED_HEADER += ../lc_lib/common/lc_global.h
        LIBS += -lz
        QMAKE_CXXFLAGS_WARN_ON += -Wno-unused-parameter
}

#~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

lessThan(QT_MAJOR_VERSION, 5) {
        unix {
                GCC_VERSION = $$system(g++ -dumpversion)
                greaterThan(GCC_VERSION, 4.6) {
                        QMAKE_CXXFLAGS += -std=c++11
                } else {
                        QMAKE_CXXFLAGS += -std=c++0x
                }
             }
}

#~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

isEmpty(QMAKE_LRELEASE) {
        win32:QMAKE_LRELEASE = $$[QT_INSTALL_BINS]\\lrelease.exe
        else:QMAKE_LRELEASE = $$[QT_INSTALL_BINS]/lrelease
        unix {
                !exists($$QMAKE_LRELEASE) { QMAKE_LRELEASE = lrelease-qt4 }
        } else {
                !exists($$QMAKE_LRELEASE) { QMAKE_LRELEASE = lrelease }
        }
}

TSFILES = ../lc_lib/resources/leocad_fr.ts ../lc_lib/resources/leocad_pt.ts
lrelease.input = TSFILES
lrelease.output = ${QMAKE_FILE_PATH}/${QMAKE_FILE_BASE}.qm
lrelease.commands = $$QMAKE_LRELEASE -silent ${QMAKE_FILE_IN} -qm ${QMAKE_FILE_PATH}/${QMAKE_FILE_BASE}.qm
lrelease.CONFIG += no_link target_predeps
QMAKE_EXTRA_COMPILERS += lrelease

system($$QMAKE_LRELEASE -silent $$TSFILES)

#~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

unix:!macx {
        TARGET = lpub3d
} else {
        TARGET = LPub3D
}

#~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

CONFIG(debug, debug|release) {
        message("~~~ DEBUG build ~~~")
        #CONFIG += shared
        DESTDIR = build/debug
        LIBS += -L$$DESTDIR/../../../quazip/build/debug -lquazip
        LIBS += -L$$DESTDIR/../../../ldrawini/build/debug -lldrawini
}

CONFIG(release, debug|release) {
        message("~~~ RELEASE build ~~~")
        #CONFIG += static
        DESTDIR = build/release
        LIBS += -L$$DESTDIR/../../../quazip/build/release -lquazip
        LIBS += -L$$DESTDIR/../../../ldrawini/build/release -lldrawini
}

#~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

static { # everything in these brackets takes effect with CONFIG += static
    CONFIG += static staticlib
    DEFINES += STATIC
    mac: TARGET = $$join(TARGET,,,_static)
    win32: TARGET = $$join(TARGET,,,static_)
}

#~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

OBJECTS_DIR = $$DESTDIR/.obj
MOC_DIR     = $$DESTDIR/.moc
RCC_DIR     = $$DESTDIR/.qrc
UI_DIR      = $$DESTDIR/.ui

#~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

unix:!macx {
        isEmpty(INSTALL_PREFIX):INSTALL_PREFIX = /usr
        isEmpty(BIN_DIR):BIN_DIR = $$INSTALL_PREFIX/bin
        isEmpty(DOCS_DIR):DOCS_DIR = $$INSTALL_PREFIX/share/doc/leocad
        isEmpty(ICON_DIR):ICON_DIR = $$INSTALL_PREFIX/share/pixmaps
        isEmpty(MAN_DIR):MAN_DIR = $$INSTALL_PREFIX/share/man/man1
        isEmpty(DESKTOP_DIR):DESKTOP_DIR = $$INSTALL_PREFIX/share/applications
        isEmpty(MIME_DIR):MIME_DIR = $$INSTALL_PREFIX/share/mime/packages
        isEmpty(MIME_ICON_DIR):MIME_ICON_DIR = $$INSTALL_PREFIX/share/icons/hicolor/scalable/mimetypes

        target.path = $$BIN_DIR
        docs.path = $$DOCS_DIR
        docs.files = docs/README.txt docs/CREDITS.txt docs/COPYING.txt
        man.path = $$MAN_DIR
        man.files = leocad.1
        desktop.path = $$DESKTOP_DIR
        desktop.files = qt/leocad.desktop
        icon.path = $$ICON_DIR
        icon.files = leocad.png
        mime.path = $$MIME_DIR
        mime.files = qt/leocad.xml
        mime_icon.path = $$MIME_ICON_DIR
        mime_icon.files = ../lc_lib/resources/application-vnd.leocad.svg

        INSTALLS += target docs man desktop icon mime mime_icon

        DEFINES += LC_INSTALL_PREFIX=\\\"$$INSTALL_PREFIX\\\"

        !isEmpty(DISABLE_UPDATE_CHECK) {
                DEFINES += LC_DISABLE_UPDATE_CHECK=$$DISABLE_UPDATE_CHECK
        }

        !isEmpty(LDRAW_LIBRARY_PATH) {
                DEFINES += LC_LDRAW_LIBRARY_PATH=\\\"$$LDRAW_LIBRARY_PATH\\\"
        }
}

macx {

    ICON = LPub.icns
    QMAKE_INFO_PLIST = ../lc_lib/qt/Info.plist

    document_icon.files += ../lc_lib/resources/leocad_document.icns
    document_icon.path = Contents/Resources
    library.files += ../lc_lib/library.bin
    library.path = Contents/Resources

    QMAKE_BUNDLE_DATA += document_icon library
}

#~~ inputs ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
include(../lc_lib/Lc_Lib.pri)
include(../qslog/QsLog.pri)
include(../qsimpleupdater/QSimpleUpdater.pri)

HEADERS += \
    aboutdialog.h \
    application.h \
    annotations.h \
    archiveparts.h \
    backgrounddialog.h \
    backgrounditem.h \
    borderdialog.h \
    build.h \
    callout.h \
    calloutbackgrounditem.h \
    color.h \
    commands.h \
    commonmenus.h \
    csiitem.h \
    dependencies.h \
    dialogexportpages.h \
    dividerdialog.h \
    editwindow.h \
    fadestepcolorparts.h \
    globals.h \
    gradients.h \
    highlighter.h \
    hoverpoints.h \
    ldrawfiles.h \
    ldsearchdirs.h \
    lpub.h \
    lpub_preferences.h \
    meta.h \
    metagui.h \
    metaitem.h \
    metatypes.h \
    name.h \
    numberitem.h \
    pagebackgrounditem.h \
    pageattributetextitem.h \
    pageattributepixmapitem.h \
    pairdialog.h \
    pageorientationdialog.h \
    pagesizedialog.h \
    parmshighlighter.h \
    parmswindow.h \
    paths.h \
    placement.h \
    placementdialog.h \
    pli.h \
    pliannotationdialog.h \
    pliconstraindialog.h \
    plisortdialog.h \
    plisubstituteparts.h \
    pointer.h \
    preferencesdialog.h \
    range.h \
    range_element.h \
    ranges.h \
    ranges_element.h \
    ranges_item.h \
    render.h \
    reserve.h \
    resize.h \
    resolution.h \
    rotateiconitem.h \
    rx.h \
    scaledialog.h \
    step.h \
    textitem.h \
    updatecheck.h \
    where.h \
    sizeandorientationdialog.h \
    splashscreen.h \
    threadWorkers.h \
    version.h \
    calloutpointeritem.h


SOURCES += \
    aboutdialog.cpp \
    application.cpp \
    annotations.cpp \
    archiveparts.cpp \
    assemglobals.cpp \
    backgrounddialog.cpp \
    backgrounditem.cpp \
    borderdialog.cpp \
    callout.cpp \
    calloutbackgrounditem.cpp \
    calloutglobals.cpp \
    color.cpp \
    commands.cpp \
    commonmenus.cpp \
    csiitem.cpp \
    dependencies.cpp \
    dialogexportpages.cpp \
    dividerdialog.cpp \
    editwindow.cpp \
    fadestepcolorparts.cpp \
    fadestepglobals.cpp \
    formatpage.cpp \
    gradients.cpp \
    highlighter.cpp \
    hoverpoints.cpp \
    ldrawfiles.cpp \
    ldsearchdirs.cpp \
    lpub.cpp \
    lpub_preferences.cpp \
    meta.cpp \
    metagui.cpp \
    metaitem.cpp \
    multistepglobals.cpp \
    numberitem.cpp \
    openclose.cpp \
    pagebackgrounditem.cpp \
    pageattributetextitem.cpp \
    pageattributepixmapitem.cpp \
    pageglobals.cpp \
    pageorientationdialog.cpp \
    pagesizedialog.cpp \
    pairdialog.cpp \
    parmshighlighter.cpp \
    parmswindow.cpp \
    paths.cpp \
    placement.cpp \
    placementdialog.cpp \
    pli.cpp \
    pliannotationdialog.cpp \
    pliconstraindialog.cpp \
    pliglobals.cpp \
    plisortdialog.cpp \
    plisubstituteparts.cpp \
    preferencesdialog.cpp \
    printpdf.cpp \
    projectglobals.cpp \
    range.cpp \
    range_element.cpp \
    ranges.cpp \
    ranges_element.cpp \
    ranges_item.cpp \
    render.cpp \
    resize.cpp \
    resolution.cpp \
    rotateiconitem.cpp \
    rotate.cpp \
    rx.cpp \
    scaledialog.cpp \
    sizeandorientationdialog.cpp \
    splashscreen.cpp \
    step.cpp \
    textitem.cpp \
    threadWorkers.cpp \
    traverse.cpp \
    updatecheck.cpp \
    undoredo.cpp \
    calloutpointeritem.cpp

FORMS += \
    preferences.ui \
    aboutdialog.ui \
    dialogexportpages.ui

OTHER_FILES += \
    lpub.rc

RESOURCES += \
    lpub.qrc

!win32 {
    TRANSLATIONS = ../lc_lib/resources/leocad_pt.ts
}

#message(FINAL CONFIG:)
#message($$CONFIG)
