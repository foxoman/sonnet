include_directories(${VOIKKO_INCLUDE_DIR})


########### next target ###############

set(sonnet_voikko_PART_SRCS voikkoclient.cpp voikkodict.cpp voikkodebug.cpp)

add_library(sonnet_voikko MODULE ${sonnet_voikko_PART_SRCS})

target_link_libraries(sonnet_voikko PRIVATE KF5::SonnetCore ${VOIKKO_LIBRARIES})

set_target_properties(sonnet_voikko PROPERTIES OUTPUT_NAME "voikko")
install(TARGETS sonnet_voikko  DESTINATION ${KDE_INSTALL_PLUGINDIR}/kf5/sonnet/)
