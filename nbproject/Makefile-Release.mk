#
# Generated Makefile - do not edit!
#
# Edit the Makefile in the project folder instead (../Makefile). Each target
# has a -pre and a -post target defined where you can add customized code.
#
# This makefile implements configuration specific macros and targets.


# Environment
MKDIR=mkdir
CP=cp
GREP=grep
NM=nm
CCADMIN=CCadmin
RANLIB=ranlib
CC=gcc
CCC=g++
CXX=g++
FC=gfortran
AS=as

# Macros
CND_PLATFORM=MinGW-Windows
CND_DLIB_EXT=dll
CND_CONF=Release
CND_DISTDIR=dist
CND_BUILDDIR=build

# Include project Makefile
include Makefile

# Object Directory
OBJECTDIR=${CND_BUILDDIR}/${CND_CONF}/${CND_PLATFORM}

# Object Files
OBJECTFILES= \
	${OBJECTDIR}/main.o


# C Compiler Flags
CFLAGS=

# CC Compiler Flags
CCFLAGS=
CXXFLAGS=

# Fortran Compiler Flags
FFLAGS=

# Assembler Flags
ASFLAGS=

# Link Libraries and Options
LDLIBSOPTIONS=-L../../../Downloads/glew-2.0.0/lib/Release/x64 -L../../../Downloads/glfw-3.2.1.bin.WIN64/lib-mingw-w64 -L../../../../../Program\ Files\ \(x86\)/mingw-w64/i686-6.3.0-posix-dwarf-rt_v5-rev1/mingw32/i686-w64-mingw32/lib/ldscripts -L../../../../../Program\ Files\ \(x86\)/mingw-w64/i686-6.3.0-posix-dwarf-rt_v5-rev1/mingw32/lib -lglew32 -lglew32s -lopengl32 -lglfw3 -lgdi32 -lglu32

# Build Targets
.build-conf: ${BUILD_SUBPROJECTS}
	"${MAKE}"  -f nbproject/Makefile-${CND_CONF}.mk ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/sphere.exe

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/sphere.exe: ${OBJECTFILES}
	${MKDIR} -p ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}
	${LINK.cc} -o ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/sphere ${OBJECTFILES} ${LDLIBSOPTIONS}

${OBJECTDIR}/main.o: main.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -I../../../Downloads/glew-2.0.0/include/GL -I../../../Downloads/glfw-3.2.1.bin.WIN64/include/GLFW -I../../../../../Program\ Files\ \(x86\)/mingw-w64/i686-6.3.0-posix-dwarf-rt_v5-rev1/mingw32/i686-w64-mingw32/include -I../../../../../Program\ Files\ \(x86\)/mingw-w64/i686-6.3.0-posix-dwarf-rt_v5-rev1/mingw32/i686-w64-mingw32/include/GL -include ../../../Downloads/glew-2.0.0/include/GL/glew.h -include ../../../Downloads/glfw-3.2.1.bin.WIN64/include/GLFW/glfw3.h -include ../../../Downloads/glfw-3.2.1.bin.WIN64/include/GLFW/glfw3native.h -include ../../../../../Program\ Files\ \(x86\)/mingw-w64/i686-6.3.0-posix-dwarf-rt_v5-rev1/mingw32/i686-w64-mingw32/include/string.h -include ../../../../../Program\ Files\ \(x86\)/mingw-w64/i686-6.3.0-posix-dwarf-rt_v5-rev1/mingw32/i686-w64-mingw32/include/GL/glu.h -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/main.o main.cpp

# Subprojects
.build-subprojects:

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r ${CND_BUILDDIR}/${CND_CONF}

# Subprojects
.clean-subprojects:

# Enable dependency checking
.dep.inc: .depcheck-impl

include .dep.inc
