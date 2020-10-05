CXX = g++
CXXFLAGS = -Wall -std=c++11
SRC = thread_lifecycle_demo.cpp
TARGET = thread_lifecycle_demo

${TARGET} : ${SRC}
	${CXX} ${CXXFLAGS} ${SRC} -o ${TARGET}

.PHONY : clean
clean:
	rm -f ${TARGET}