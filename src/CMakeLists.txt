ADD_SUBDIRECTORY(Display)

# add c file
aux_source_directory(. DIR_GAME_EXE_SRCS)
aux_source_directory(Utils/ DIR_UTILS_SRCS)
aux_source_directory(GameContent/ DIR_CHARACTERS_SRCS)
aux_source_directory(Utils/data_stucture DIR_UTILS_DS_SRCS)

#ser project wide include
include_directories("${CMAKE_SOURCE_DIR}/include/")

# add RapidJson Dependency
include_directories("${CMAKE_SOURCE_DIR}/thirdparty/rapidjson/include/")

add_executable(Dungeon ${DIR_UTILS_SRCS} ${DIR_CHARACTERS_SRCS} ${DIR_UTILS_DS_SRCS} ${DIR_GAME_EXE_SRCS})


target_link_libraries(Dungeon libdisplay-ncurses ${Boost_LIBRARIES} )
