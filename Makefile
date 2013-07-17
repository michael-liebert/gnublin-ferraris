all: gnublin.o gnublin-ferraris

gnublin.o: gnublin.cpp
	$(CXX) $(CXXFLAGS) $(BOARDDEF) -c gnublin.cpp

gnublin-ferraris: gnublin-ferraris.cpp
	$(CXX) $(CXXFLAGS) $(BOARDDEF) -o gnublin-ferraris gnublin.o gnublin-ferraris.cpp
