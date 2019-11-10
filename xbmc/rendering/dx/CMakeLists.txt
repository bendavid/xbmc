set(SOURCES DeviceResources.cpp
            GUIWindowTestPatternDX.cpp
            RenderSystemDX.cpp
            ScreenshotSurfaceWindows.cpp)

set(HEADERS DeviceResources.h
            DirectXHelper.h
            GUIWindowTestPatternDX.h
            RenderContext.h
            RenderSystemDX.h
            ScreenshotSurfaceWindows.h)

core_add_library(rendering_dx)
