include ../Make.defines

PROGS = checkopts prdefaults rcvbuf rcvbufset sockopt

all: 	${PROGS}

sockopt:		sockopt.o
				${CC} ${CFLAGS} -o $@ sockopt.o ${LIBS}

checkopts:		checkopts.o
				${CC} ${CFLAGS} -o $@ checkopts.o ${LIBS}

predufaults:	prdefaults.o
				${CC} ${CFLAGS} -o $@ prdefaults.o ${LIBS}

clean:
				rm -f ${PROGS} ${CLEANFILES}