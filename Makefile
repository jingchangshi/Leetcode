CPP=g++
CPPFLAGS=-O0 -g -Wall -fsanitize=address -fno-omit-frame-pointer
CASEID=542
PROG=leetcode
${PROG}: ${CASEID}.cpp
	${CPP} ${CASEID}.cpp -o ${PROG} ${CPPFLAGS}
run:
	./${PROG}
clean:
	rm ${PROG}


