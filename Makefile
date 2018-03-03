EXE=ball

all: compile run

compile:
	gcc -D_GNU_SOURCE -L/usr/local/lib -I/usr/local/include -o ${EXE} nate.c -lncurses -ltinfo

run:
#	@read -p "Press ENTER to begin and Ctrl+C to quit..."
	./${EXE}

clean:
	rm -rf ${EXE}
