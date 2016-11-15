all: TueEtwas.o testMain.o
	g++ -shared ja/TueEtwas.o -o libTest.so
	
TueEtwas.o:
	g++ -fPIC -c TueEtwas.cpp -o ja/TueEtwas.o