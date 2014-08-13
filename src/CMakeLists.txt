# Set the sources
set(QtStomp_SRCS
    qstompconnectframe.cpp
    qstompconnection.cpp
    qstompframebody.cpp
    qstompframebodytext.cpp
    qstompframe.cpp
)

# Build the library
add_library(QtStomp ${QtStomp_SRCS})
qt5_use_modules(QtStomp Network)


