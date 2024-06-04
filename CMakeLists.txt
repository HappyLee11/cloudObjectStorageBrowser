cmake_minimum_required(VERSION 3.28)
project(cloudObjectStorageBrowser)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

set(CMAKE_PREFIX_PATH "G:/Qt/6.7.1/mingw_64")

find_package(Qt6 COMPONENTS
        Core
        Gui
        Widgets
        REQUIRED)
#添加mac端图标文件
set(APP_ICON_MACOS "resources/icons/mac_icon.icns")
set_source_files_properties(${APP_ICON_MACOS} PROPERTIES
MACOS_PACKAGE_LOCATION "Resources")

add_executable(cloudObjectStorageBrowser main.cpp
        hellocosbrowsers.cpp
        hellocosbrowsers.h
        hellocosbrowsers.ui
        hellocosbrowsers.h
        resources/icons/resources.rc
        ${APP_ICON_MACOS}#包括.icns图标文件
)

#设置Mac os 的应用图标
set_target_properties(cloudObjectStorageBrowser PROPERTIES
MACOSX_BUNDLE_ICON_FILE mac_icon.icns
MACOSX_BUNDLE TRUE
MACOSX_FRAMEWORK_IDENTIFIER org.zjl.cloudObjectStorageBrowser
        RESOURCE "${APP_ICON_MACOS}")

target_link_libraries(cloudObjectStorageBrowser
        Qt::Core
        Qt::Gui
        Qt::Widgets
)

if (WIN32 AND NOT DEFINED CMAKE_TOOLCHAIN_FILE)
    set(DEBUG_SUFFIX)
    if (MSVC AND CMAKE_BUILD_TYPE MATCHES "Debug")
        set(DEBUG_SUFFIX "d")
    endif ()
    set(QT_INSTALL_PATH "${CMAKE_PREFIX_PATH}")
    if (NOT EXISTS "${QT_INSTALL_PATH}/bin")
        set(QT_INSTALL_PATH "${QT_INSTALL_PATH}/..")
        if (NOT EXISTS "${QT_INSTALL_PATH}/bin")
            set(QT_INSTALL_PATH "${QT_INSTALL_PATH}/..")
        endif ()
    endif ()
    if (EXISTS "${QT_INSTALL_PATH}/plugins/platforms/qwindows${DEBUG_SUFFIX}.dll")
        add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
                COMMAND ${CMAKE_COMMAND} -E make_directory
                "$<TARGET_FILE_DIR:${PROJECT_NAME}>/plugins/platforms/")
        add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
                COMMAND ${CMAKE_COMMAND} -E copy
                "${QT_INSTALL_PATH}/plugins/platforms/qwindows${DEBUG_SUFFIX}.dll"
                "$<TARGET_FILE_DIR:${PROJECT_NAME}>/plugins/platforms/")
    endif ()
    foreach (QT_LIB Core Gui Widgets)
        add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
                COMMAND ${CMAKE_COMMAND} -E copy
                "${QT_INSTALL_PATH}/bin/Qt6${QT_LIB}${DEBUG_SUFFIX}.dll"
                "$<TARGET_FILE_DIR:${PROJECT_NAME}>")
    endforeach (QT_LIB)
endif ()
