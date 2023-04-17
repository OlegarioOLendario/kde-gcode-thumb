
cmake_minimum_required(VERSION 3.10)

project(gcode-thumb-kde
	#VERSION 0.0.1
	DESCRIPTION "Fast lightweight GCODE file thumbnail generator for KDE"
	)

set(QT_MIN_VERSION "5.3.0")
set(KF5_MIN_VERSION "5.2.0")

find_package(ECM 1.0.0 REQUIRED NO_MODULE)
set(CMAKE_MODULE_PATH ${ECM_MODULE_PATH} ${ECM_KDE_MODULE_DIR} ${CMAKE_CURRENT_SOURCE_DIR}/cmake)

include(KDEInstallDirs)
include(KDECMakeSettings)
include(KDECompilerSettings NO_POLICY_SCOPE)
include(FeatureSummary)

# Find Qt modules
find_package(Qt5 ${QT_MIN_VERSION} CONFIG REQUIRED COMPONENTS 
    Core    # QCommandLineParser, QStringLiteral
    Widgets # QApplication 
)

# Find KDE modules
find_package(KF5 ${KF5_MIN_VERSION} REQUIRED COMPONENTS
    KIO
)

feature_summary(WHAT ALL INCLUDE_QUIET_PACKAGES FATAL_ON_MISSING_REQUIRED_PACKAGES)
    
set(gcodethumbnail_SRCS gcodecreator.cpp)

add_library(gcodethumbnail MODULE ${gcodethumbnail_SRCS})


target_link_libraries(gcodethumbnail
    Qt5::Widgets
    KF5::KIOWidgets)

install(TARGETS gcodethumbnail DESTINATION ${LIB_INSTALL_DIR}/qt5/plugins/)
install(FILES gcodethumbnail.desktop DESTINATION ${SERVICES_INSTALL_DIR})
