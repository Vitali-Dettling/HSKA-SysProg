all:
	g++ -g -shared -pthread	-fPIC src/ReadBuffer.cpp src/WriteBuffer.cpp -o ~/workspace/Scanner/sharedLIB/libBuffer.so

#Um die Thread zu testen und generell
#all:debug/ReadBuffer.o debug/testMain.o
#g++ -g -pthread debug/ReadBuffer.o debug/testMain.o -o debug/testReader


#debug/ReadBuffer.o: 
#	g++ -c -g src/ReadBuffer.cpp -o		debug/ReadBuffer.o
#debug/testMain.o:
#	g++ -c -g src/testMain.cpp -o	 	debug/testMain.o
 

#Muster nach dem ich es implementiert habe!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
#all: debug/ParserImp.o debug/Node.o debug/TypeCheck.o debug/MakeCodeOutput.o debug/testMain.o																						
#	g++ -g -L/home/stud/lkt/fbi/devi1013/workspace/Scanner/sharedLIB -lString -lScanner -lSymTable -lBuffer debug/ParserImp.o debug/Node.o debug/TypeCheck.o debug/MakeCodeOutput.o debug/testMain.o -o debug/TestParseTree
#all: debug/ParserImp.o debug/Node.o debug/MakeCodeOutput.o debug/main.o 
#	g++ -g -L/home/stud/lkt/fbi/devi1013/workspace/Scanner/sharedLIB -lString -lScanner -lSymTable -lBuffer debug/ParserImp.o debug/Node.o debug/MakeCodeOutput.o debug/main.o -o debug/Parser
	
#debug/Node.o:
#	g++ -c -g src/ParseTree/Node.cpp -o				debug/Node.o

#debug/MakeCodeOutput.o:
#	g++ -c -g src/ParseTree/MakeCodeOutput.cpp -o 	debug/MakeCodeOutput.o
	
#debug/main.o:
#	g++ -c -g src/main.cpp -o						debug/main.o

#debug/testMain.o:
#	g++ -c -g src/ParseTree/testMain.cpp -o 		debug/testMain.o
	
#debug/ParserImp.o:
#	g++ -c -g src/Parser/ParserImp.cpp -o 			debug/ParserImp.o 
	
