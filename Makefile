NAME = dice
DESC = a simple dice roller
AUTH = mangomeep
DATE = 10/03
YEAR = 2023

SRC = ${NAME}.c
OUTPUT = ${NAME}
CC = cc
CFLAGS =
LINKS =



all: build

build:
	${CC} ${SRC} ${CFLAGS} ${LINKS} -o ${OUTPUT}

clean:
	rm -f ${OUTPUT}

install: build
	cp ${OUTPUT} /usr/local/bin/

uninstall:
	rm -f /usr/local/bin/${OUTPUT}
