all:
	g++ -g -shared -LsharedLIB -lSymTable -lString -lBuffer -fPIC  src/states/StateERROR.cpp src/states/StateSignCorner2.cpp src/states/StateSignAttention.cpp src/states/StateSignCorner1.cpp src/states/StateSignSlash2.cpp src/states/StateSignStar2.cpp src/states/StateSignStar1.cpp src/states/StateSignSlash1.cpp src/states/StateSignAll.cpp src/states/StateInteger.cpp src/states/StateIdentifier.cpp src/states/StateStart.cpp src/states/State.cpp src/Automat.cpp src/Token.cpp src/ScannerImp.cpp  -o ~/workspace/Scanner/sharedLIB/libScanner.so
	
