CXX = g++
CXXFLAGS = -Wall -std=c++11
SRC = atomic_object_demo.cpp
TARGET = atomic_object_demo

${TARGET} : ${SRC}
	${CXX} ${CXXFLAGS} ${SRC} -o ${TARGET}

.PHONY: clean
clean:
	rm -f ${TARGET}
