cmake_minimum_required (VERSION 3.3)
project (project3)

set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++98")

set (SOURCE_FILES
	src/main.cpp
	src/Node.h
	src/Tree.h src/Tree.cpp src/TreeIterator.cpp
	src/Library.h src/Library.cpp
	src/AlbumCompare.h src/AlbumCompare.cpp
	src/ArtistCompare.h src/ArtistCompare.cpp
	src/GenreCompare.h src/GenreCompare.cpp
	src/Song.h src/Song.cpp
	src/TitleCompare.h src/TitleCompare.cpp
	src/YearCompare.h src/YearCompare.cpp
	)


add_executable (project3 ${SOURCE_FILES} src/library.txt)