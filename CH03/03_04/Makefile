CXX = g++
CXXFLAGS = -Wall -std=c++11
SRC = mutual_exclusion_demo.cpp
TARGET = mutual_exclusion_demo

${TARGET} : ${SRC}
	${CXX} ${CXXFLAGS} ${SRC} -o ${TARGET}

.PHONY: clean
clean:
	rm -f ${TARGET}
