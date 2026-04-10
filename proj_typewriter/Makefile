CXX = clang++
CXXFLAGS = -g3 -Wall -Wextra -Wpedantic -Wshadow
LDFLAGS = -g3 -lncurses

typewriter: main.o Editor.o ActionStack.o TextUI.o
	$(CXX) $(CXXFLAGS) $(LDFLAGS) $^ -o typewriter

main.o: main.cpp Editor.h
	$(CXX) $(CXXFLAGS) -c main.cpp

Editor.o: Editor.cpp Editor.h
	$(CXX) $(CXXFLAGS) -c Editor.cpp

ActionStack.o: ActionStack.cpp ActionStack.h
	$(CXX) $(CXXFLAGS) -c ActionStack.cpp

unit_test: unit_test_driver.o ActionStack.o
	$(CXX) $(CXXFLAGS) $(LDFLAGS) $^ -o unit_test

clean:
	@find . -type f -name '*.o' ! -name 'TextUI.o' -exec rm -f {} \;
	@rm -f *~ a.out