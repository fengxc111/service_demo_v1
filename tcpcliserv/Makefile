include ../Make.defines

PROGS =	tcpcli01 tcpcli04 tcpcli05 tcpcli06 \
		tcpcli07 tcpcli08 tcpcli09 tcpcli10 \
		tcpserv01 tcpserv02 tcpserv03 tcpserv04 \
		tcpserv08 tcpserv09 tcpservselect01 tcpservpoll01 tsigpipe

all:	${PROGS}

tcpcli01:	tcpcli01.o
			${CC} ${CFLAGS} -o $@ tcpcli01.o ${LIBS}
tcpcli04:	tcpcli04.o
			${CC} ${CFLAGS} -o $@ tcpcli04.o ${LIBS}
tcpcli09: 	tcpcli09.o
			${CC} ${CFLAGS} -o $@ tcpcli09.o ${LIBS}
tcpcli11:	tcpcli11.o
			${CC} ${CFLAGS} -o $@ tcpcli11.o ${LIBS}

tcpserv01:	tcpserv01.o
			${CC} ${CFLAGS} -o $@ tcpserv01.o ${LIBS}
tcpserv04:	tcpserv04.o
			${CC} ${CFLAGS} -o $@ tcpserv04.o ${LIBS}
tcpserv08: tcpserv08.o
			${CC} ${CFLAGS} -o $@ tcpserv08.o ${LIBS}
tcpserv09: tcpserv09.o
			${CC} ${CFLAGS} -o $@ tcpserv09.o ${LIBS}
clean:
			rm -f ${PROGS} ${CLEANFILES}