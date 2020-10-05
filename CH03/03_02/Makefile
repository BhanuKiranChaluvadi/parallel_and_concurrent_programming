CXX = g++
CXXFLAGS = -Wall -std=c++11
SRC = data_race_demo.cpp
TARGET = data_race_demo

${TARGET} : ${SRC}
	${CXX} ${CXXFLAGS} ${SRC} -o ${TARGET}

.PHONY: clean
clean:
	rm -f ${TARGET}
