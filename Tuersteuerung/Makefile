# Autor: M.Herhold
# Datum: Mai 2017
# Organisation: Institut für Automatisierungstechnik

# Projekt Dateien, Skelett

CC_FILES = \
	DoorInterface.cpp \
	DoorControl.cpp

HH_FILES = \
	DoorInterface.h \
	DoorControl.h

C_FILES = \
	Library/niusb6501.c

H_FILES = \
	Library/niusb6501.h

BINARY = Tuersteuerung

# rules

OBJ_FILES = $(C_FILES:.c=.o) ${CC_FILES:.cpp=.o}

LDLIBS		= -lrt -lncurses -lusb -lm -lpthread
LDFLAGS		= -g

CXXFLAGSI	=  -Wall -g -O0
CFLAGSI		=  -Wall -g -O0

CSTD		= -std=gnu99
CXXSTD		= -std=c++11
.c.o:
	$(CC) ${CSTD} ${CFLAGSI} ${CFLAGS} -c $< -o $@

.cpp.o:
	${CXX} ${CXXSTD} ${CXXFLAGSI} ${CXXFLAGS} -c $< -o $@

${BINARY}: ${OBJ_FILES}
	${CXX} ${LDFLAGS} ${OBJ_FILES} ${LDLIBS} -o $@


all:	${BINARY}

clean:
	-rm ${OBJ_FILES}
	-rm .depend
	-rm ${BINARY}

run:
	@xterm -e "./${BINARY}; echo 'press enter to continue'; read"

.SUFFIXES: .c .o .cpp
.PHONY: clean run


# dependencies

depend: .depend

.depend: ${C_FILES} ${CC_FILES}
	rm -f ./.depend
	$(CXX) ${CXXSTD} -MM $^ -MF  ./.depend;

include .depend
