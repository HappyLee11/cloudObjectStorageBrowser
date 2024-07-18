@echo off
SetLocal EnableDelayedExpansion
(set PATH=C:\QT5\5.15.2\mingw81_64\bin;!PATH!)
if defined QT_PLUGIN_PATH (
    set QT_PLUGIN_PATH=C:\QT5\5.15.2\mingw81_64\plugins;!QT_PLUGIN_PATH!
) else (
    set QT_PLUGIN_PATH=C:\QT5\5.15.2\mingw81_64\plugins
)
%*
EndLocal
