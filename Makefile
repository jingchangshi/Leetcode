CPP=g++
CPPFLAGS=
CASEID=704
PROG=leetcode
${PROG}: ${CASEID}.cpp
	${CPP} ${CASEID}.cpp -o ${PROG} ${CPPFLAGS}
run:
	./${PROG}
clean:
	rm ${PROG}


