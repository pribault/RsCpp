cmake_minimum_required(VERSION 3.28)

project(RsCpp
	VERSION			0.0.0
	DESCRIPTION		"Reactive Streams for C++"
	HOMEPAGE_URL	"https://github.com/pribault/RsCpp"
	LANGUAGES		CXX
)

add_library(RsCpp)

set_property(TARGET RsCpp PROPERTY CXX_STANDARD 20)

target_sources(RsCpp
	PUBLIC
		FILE_SET CXX_MODULES FILES
			${CMAKE_CURRENT_SOURCE_DIR}/src/RsCpp.cpp
			${CMAKE_CURRENT_SOURCE_DIR}/src/Processor.cpp
			${CMAKE_CURRENT_SOURCE_DIR}/src/Publisher.cpp
			${CMAKE_CURRENT_SOURCE_DIR}/src/Subscriber.cpp
			${CMAKE_CURRENT_SOURCE_DIR}/src/Subscription.cpp
)
