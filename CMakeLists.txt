# This file is automatically generated from cmake.toml - DO NOT EDIT
# See https://github.com/build-cpp/cmkr for more information

cmake_minimum_required(VERSION 3.15)

if(CMAKE_SOURCE_DIR STREQUAL CMAKE_BINARY_DIR)
	message(FATAL_ERROR "In-tree builds are not supported. Run CMake from a separate directory: cmake -B build")
endif()

set(CMKR_ROOT_PROJECT OFF)
if(CMAKE_CURRENT_SOURCE_DIR STREQUAL CMAKE_SOURCE_DIR)
	set(CMKR_ROOT_PROJECT ON)

	# Bootstrap cmkr and automatically regenerate CMakeLists.txt
	include(cmkr.cmake OPTIONAL RESULT_VARIABLE CMKR_INCLUDE_RESULT)
	if(CMKR_INCLUDE_RESULT)
		cmkr()
	endif()

	# Enable folder support
	set_property(GLOBAL PROPERTY USE_FOLDERS ON)

	# Create a configure-time dependency on cmake.toml to improve IDE support
	set_property(DIRECTORY APPEND PROPERTY CMAKE_CONFIGURE_DEPENDS cmake.toml)
endif()

project(ketaminex
	LANGUAGES
		CXX
)

# Target: ketaminex
set(ketaminex_SOURCES
	cmake.toml
	"feature/control/control.cpp"
	"feature/control/control.hpp"
	"feature/feature.cpp"
	"feature/feature.hpp"
	"feature/manager.cpp"
	"feature/manager.hpp"
	"feature/overlay/overlay.cpp"
	"feature/overlay/overlay.hpp"
	"feature/overlay/overlay_context.hpp"
	"feature/overlay/overlay_panel.hpp"
	"feature/overlay/overlay_params.hpp"
	"feature/settings.hpp"
	"game_classes/constants/weapon_name.hpp"
	"launcher/launcher.cpp"
	"launcher/launcher.hpp"
	main.cpp
	"menu/imgui_data.hpp"
	"menu/imgui_manager.cpp"
	"menu/imgui_manager.hpp"
	"menu/menu.cpp"
	"menu/menu.hpp"
	"menu/menu_params.hpp"
	"resources/font/Glory.hpp"
	"resources/font/GloryBold.hpp"
	"resources/icon/icons.hpp"
	"sdk/common/weapon_name_selector.hpp"
	"sdk/mouse/mouse.cpp"
	"sdk/mouse/mouse.hpp"
	"sdk/mouse/mouse_common.hpp"
	"sdk/mouse/mouse_constants.hpp"
	"sdk/mouse/mouse_params.hpp"
	"thirdparty/ImGui/imconfig.h"
	"thirdparty/ImGui/imgui.cpp"
	"thirdparty/ImGui/imgui.h"
	"thirdparty/ImGui/imgui_draw.cpp"
	"thirdparty/ImGui/imgui_impl_dx11.cpp"
	"thirdparty/ImGui/imgui_impl_dx11.h"
	"thirdparty/ImGui/imgui_impl_win32.cpp"
	"thirdparty/ImGui/imgui_impl_win32.h"
	"thirdparty/ImGui/imgui_internal.h"
	"thirdparty/ImGui/imgui_tables.cpp"
	"thirdparty/ImGui/imgui_widgets.cpp"
	"thirdparty/ImGui/imstb_rectpack.h"
	"thirdparty/ImGui/imstb_textedit.h"
	"thirdparty/ImGui/imstb_truetype.h"
	"thirdparty/syscall.hpp"
	"window/d3d/directx.cpp"
	"window/d3d/directx.hpp"
	"window/window.cpp"
	"window/window.hpp"
	"window/window_constants.hpp"
)

add_executable(ketaminex)

target_sources(ketaminex PRIVATE ${ketaminex_SOURCES})
source_group(TREE ${CMAKE_CURRENT_SOURCE_DIR} FILES ${ketaminex_SOURCES})

target_include_directories(ketaminex PRIVATE
	"C:/Program Files (x86)/Microsoft DirectX SDK (June 2010)/Include"
	resources
	thirdparty
	sdk
	game_classes
	feature
	window
	menu
)

target_link_directories(ketaminex PRIVATE
	"C:/Program Files (x86)/Microsoft DirectX SDK (June 2010)/Lib/x64"
)

set_target_properties(ketaminex PROPERTIES
	CXX_STANDARD
		20
	CXX_STANDARD_REQUIRED
		ON
)

get_directory_property(CMKR_VS_STARTUP_PROJECT DIRECTORY ${PROJECT_SOURCE_DIR} DEFINITION VS_STARTUP_PROJECT)
if(NOT CMKR_VS_STARTUP_PROJECT)
	set_property(DIRECTORY ${PROJECT_SOURCE_DIR} PROPERTY VS_STARTUP_PROJECT ketaminex)
endif()
