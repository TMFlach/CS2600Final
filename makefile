CC=gcc
DLLFLAGS=-fPIC --shared
EXT=.exe
#Windows use mingw32-make
ifeq ($(OS),Windows_NT) #Windows
	DELETE=del
else
	DELETE=rm
	ifeq ($(UNAME_S),Darwin) #MAC
		
	else
	endif
endif
all: staticbuild

staticbuild: TicTacToe.c
	$(CC) -o TicTacToe$(EXT) TicTacToe.c
clean:
	$(DELETE) *.o *.a *.so *$(EXT)