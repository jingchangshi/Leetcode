CPP=g++
CPPFLAGS=-O0 -g -Wall
CASEID=116
PROG=leetcode
${PROG}: ${CASEID}.cpp
	${CPP} ${CASEID}.cpp -o ${PROG} ${CPPFLAGS}
run:
	./${PROG}
clean:
	rm ${PROG}


