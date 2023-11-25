cmake_minimum_required(VERSION 3.8)

project(RsCpp
	VERSION			0.0.0
	DESCRIPTION		"Reactive Streams for C++"
	HOMEPAGE_URL	"https://github.com/pribault/RsCpp"
	LANGUAGES		CXX
)

set(SOURCES
	${CMAKE_CURRENT_SOURCE_DIR}/include/rscpp/inl/Processor.inl
	${CMAKE_CURRENT_SOURCE_DIR}/include/rscpp/inl/Publisher.inl
	${CMAKE_CURRENT_SOURCE_DIR}/include/rscpp/inl/Subscriber.inl
	${CMAKE_CURRENT_SOURCE_DIR}/include/rscpp/Processor.h
	${CMAKE_CURRENT_SOURCE_DIR}/include/rscpp/Publisher.h
	${CMAKE_CURRENT_SOURCE_DIR}/include/rscpp/Subscriber.h
	${CMAKE_CURRENT_SOURCE_DIR}/include/rscpp/Subscription.h
	${CMAKE_CURRENT_SOURCE_DIR}/src/Subscription.cpp
)

add_library(RsCpp ${SOURCES})

target_include_directories(RsCpp PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)
