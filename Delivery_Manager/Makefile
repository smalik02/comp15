CXX      = clang++
CXXFLAGS = -g3 -std=c++11 -Wall -Wextra
LDFLAGS  = -g3

HDRS = Parser.h RoundRobin.h string2int.h TimeCalc.h FewestItems.h \
ShortestTime.h Orderqueue.h Order.h Retriever.h

SRCS = main.cpp RoundRobin.cpp string2int.cpp TimeCalc.cpp FewestItems.cpp \
ShortestTime.cpp Orderqueue.cpp Retriever.cpp Parser.cpp

OBJS = main.o Parser.o Retriever.o RoundRobin.o string2int.o TimeCalc.o \
ShortestTime.o FewestItems.o Orderqueue.o

test: main.o Parser.o Retriever.o RoundRobin.o string2int.o TimeCalc.o \
ShortestTime.o FewestItems.o Orderqueue.o 
	${CXX} ${LDFLAGS} -o test main.o Parser.o Retriever.o RoundRobin.o \
	string2int.o TimeCalc.o ShortestTime.o FewestItems.o Orderqueue.o


main.o: main.cpp Parser.h RoundRobin.h string2int.h TimeCalc.h FewestItems.h \
	ShortestTime.h Orderqueue.h Order.h Retriever.h
Retriever.o: Retriever.cpp Order.h Orderqueue.h Retriever.h
RoundRobin.o: RoundRobin.cpp RoundRobin.h Order.h Retriever.h Orderqueue.h
Parser.o: Parser.cpp Parser.h Order.h
ShortestTime.o: ShortestTime.cpp ShortestTime.h Order.h Orderqueue.h \
	TimeCalc.h Retriever.h
string2int.o: string2int.cpp string2int.h
FewestItems.o: FewestItems.cpp FewestItems.h Orderqueue.h Order.h TimeCalc.h \
	Retriever.h
TimeCalc.o: TimeCalc.cpp TimeCalc.h Order.h Orderqueue.h Retriever.h
Orderqueue.o: Orderqueue.cpp Orderqueue.h Order.h

clean:
	rm -rf test *.dSYM *.o
