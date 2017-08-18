CXX      = clang++
CXXFLAGS = -g3 -std=c++11 -Wall -Wextra
LDFLAGS  = -g3

HDRS = Gerp.h Trie.h Node.h File_Manager.h FSTree.h \
DirNode.h

SRCS = main.cpp Gerp.cpp Trie.cpp Node.cpp File_Manager.cpp

OBJS = main.o Gerp.o Trie.o Node.o File_Manager.o FSTree.o DirNode.o

test: main.o Gerp.o Trie.o Node.o File_Manager.o FSTree.o DirNode.o
	${CXX} ${LDFLAGS} -o gerp main.o Gerp.o Trie.o Node.o File_Manager.o\
    FSTree.o DirNode.o


main.o: main.cpp Gerp.h File_Manager.h
Gerp.o: Gerp.cpp Gerp.h Trie.h
Trie.o: Trie.cpp Trie.h Node.h
File_Manager.o: File_Manager.cpp File_Manager.h FSTree.h Gerp.h
Node.o: Node.cpp Node.h
FSTree.o: FSTree.h DirNode.h
DirNode.o: DirNode.h

clean:
	rm -rf gerp *.dSYM main.o Gerp.o Trie.o File_Manager.o Node.o

provide:
	provide comp15 proj2part3 main.cpp Gerp.h Gerp.cpp Trie.h Trie.cpp \
		File_Manager.h File_Manager.cpp Node.h Node.cpp FSTree.o FSTree.h \
		DirNode.h DirNode.o Makefile README