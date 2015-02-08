cmake_minimum_required (VERSION 2.8)
project (Scrapier)

set (Scrapier_VERSION_MAJOR 1)
set (Scrapier_VERSION_MINOR 0)

configure_file (
		"${PROJECT_SOURCE_DIR}/ScrapierConfig.h.in"
		"${PROJECT_BINARY_DIR}/ScrapierConfig.h"
		)

add_executable (Scrapier parser.c)
target_link_libraries (Scrapier "${PROJECT_SOURCE_DIR}"/lib/mpc m)

message (STATUS "Generate ScrapierConfig.h ... ")
