# Source files
SET( HEADERS
	Configure.h.in
	TimeMeasurementBase.h
	RunTimeTimer.h
	CPUTimeTimer.h
)

SET( SOURCES
	RunTimeTimer.cpp
        CPUTimeTimer.cpp
)

# Create the library
ADD_LIBRARY( Base STATIC ${HEADERS} ${SOURCES} )

SET_TARGET_PROPERTIES(Base PROPERTIES LINKER_LANGUAGE CXX)

IF (WIN32)
        TARGET_LINK_LIBRARIES(Base Winmm.lib)
ENDIF (WIN32)


