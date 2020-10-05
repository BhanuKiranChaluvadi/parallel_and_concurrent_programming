CXX = g++
CXXFLAGS = -Wall -std=c++11
SRC = detached_thread_demo.cpp
TARGET = detached_thread_demo

${TARGET} : ${SRC}
	${CXX} ${CXXFLAGS} ${SRC} -o ${TARGET}

.PHONY: clean
clean:
	rm -f ${TARGET}
