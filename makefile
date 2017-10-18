#Each class has three targets
#target1 ClassName.o -> compile the class
#target2 test/UnitTestName.exe -> compile the unit test program and any test stubs
#target3 ABREVIATEIONtest -> run the unit test
#there are three special targets: 
#	test which runs all tests  
#	clean which deletes any compiled code
#	docs which generates documentation using doxygen	
#
#Don't forget to add your tests to the end of the tests target

#make format
#targetName (e.g what you are creating): preqrequisites/requried files
#(tab)	command1
#(tab)	command2

#TODO
#setup usage of simlib
#setup usage of qt

#LIBS =
CPP=g++
CPPFLAGS = -g -Wall
#Lane
#LinkedList
#EngineInterface

#Simulation Engine
SimulationEngine.o: src/james/SimulationEngine.cpp inc/jpconstants.h inc/TrafficModel.h TrafficModel.o
	$(CPP) $(CPPFLAGS) -c src/james/SimulationEngine.cpp TrafficModel.o $(LIBS) 

test/SimulationEngine_test.exe: TrafficModel.o test/SimulationEngine_test.cpp
	$(CPP) $(CPPFLAGS) TrafficModel.o SimulationEngine.o test/SimulationEngine_test.cpp  $(LIBS) -o test/SimulationEngine_test
	
SEtest: test/SimulationEngine_test.exe
	test/SimulationEngine_test.exe


#Traffic Model
TrafficModel.o: src/james/TrafficModel.cpp inc/jpconstants.h inc/TrafficModel.h 
	$(CPP) $(CPPFLAGS) -c src/james/TrafficModel.cpp  $(LIBS) 

test/TrafficModel_test.exe: TrafficModel.o test/TrafficModel_test.cpp
	$(CPP) $(CPPFLAGS) TrafficModel.o test/TrafficModel_test.cpp  $(LIBS) -o test/TrafficModel_test
	
TMtest: test/TrafficModel_test.exe
	test/TrafficModel_test.exe

test: TMtest SEtest
 	
clean:
	rm -f *.o
	rm -f *.exe
	rm -f test/*.exe

docs:
	#create a temporary working directory
	mkdir -p doctemp
	#generate the docs
	doxygen docs/dxy.cfg 
	#copy the appropriate files
	cp doctemp/html/* docs/. 
	#alteranatively use one cp for generaic files and one for each person
	#cp doctemp/html/{a.html,b.html} docs/.