cmake_minimum_required(VERSION 3.16.0)

project(imosm)

set(IMOSM_SRC
    src/ImOsmTile.cpp
    src/ImOsmTileLoader.cpp
    src/ImOsmTileSourceAsync.cpp
    src/ImOsmTileSourceUrl.cpp
    src/ImOsmTileGrabberUrl.cpp
    src/ImOsmTileGrabber.cpp
    src/ImOsmMapPlot.cpp
    src/ImOsmTileLoaderUrl.cpp
    src/ImOsmTileTexture.cpp
    src/ImOsmRichMarkItem.cpp
    src/ImOsmRichMarkStorage.cpp
    src/ImOsmRichMarkEditorWidget.cpp
    src/ImOsmRichMarkItemWidget.cpp
    src/ImOsmRichDestinationCalcWidget.cpp
    src/ImOsmRichDistanceCalcWidget.cpp
    src/ImOsmRichMapPlot.cpp
    src/ImOsmTileGrabberWidget.cpp
    src/ImOsmTileSourceWidget.cpp
    src/ImOsmTileSourceUrlImpl.cpp
    src/ImOsmTileSourceFs.cpp
    src/ImOsmTileSaver.cpp
    include/ImOsmCoords.h
    include/ImOsmIRichItem.h
    include/ImOsmITile.h
    include/ImOsmITileLoader.h
    include/ImOsmITileSaver.h
    include/ImOsmITileSource.h
    include/ImOsmMapPlot.h
    include/ImOsmRichDestinationCalcWidget.h
    include/ImOsmRichDistanceCalcWidget.h
    include/ImOsmRichMapPlot.h
    include/ImOsmRichMarkEditorWidget.h
    include/ImOsmRichMarkItem.h
    include/ImOsmRichMarkItemWidget.h
    include/ImOsmRichMarkStorage.h
    include/ImOsmRichMarkStyleWidget.h
    include/ImOsmTile.h
    include/ImOsmTileAsync.h
    include/ImOsmTileDummy.h
    include/ImOsmTileGrabber.h
    include/ImOsmTileGrabberUrl.h
    include/ImOsmTileGrabberWidget.h
    include/ImOsmTileLoader.h
    include/ImOsmTileLoaderImpl.h
    include/ImOsmTileLoaderUrl.h
    include/ImOsmTileSaver.h
    include/ImOsmTileSourceAsync.h
    include/ImOsmTileSourceFs.h
    include/ImOsmTileSourceUrl.h
    include/ImOsmTileSourceUrlImpl.h
    include/ImOsmTileSourceWidget.h
    include/ImOsmTileTexture.h)

add_library(${PROJECT_NAME} ${IMOSM_SRC})
target_include_directories(${PROJECT_NAME} PUBLIC .)
target_include_directories(${PROJECT_NAME} PUBLIC ./include)
target_include_directories(${PROJECT_NAME} PUBLIC ../latlon)
target_include_directories(${PROJECT_NAME} PUBLIC ../mINI/src/mini)
target_include_directories(${PROJECT_NAME} PUBLIC ${Stb_INCLUDE_DIR})
target_link_libraries(${PROJECT_NAME} PUBLIC imgui::imgui)
target_link_libraries(${PROJECT_NAME} PUBLIC implot::implot)
