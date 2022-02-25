CC= g++ 

INCDIR= -I./include/ 


GAMESRC= \
         src/Manager.cpp \
         src/LogManager.cpp \
         src/Clock.cpp \

GAME= src/game.cpp
EXECUTABLE= game
OBJECTS= $(GAMESRC:.cpp=.o)

all: $(EXECUTABLE) Makefile

$(EXECUTABLE): $(ENGINE) $(OBJECTS) $(GAME) $(GAMESRC) 
	$(CC) $(GAME) $(OBJECTS) -o $@ $(INCDIR) 

.cpp.o: 
	$(CC) -c $(INCDIR) $< -o $@

clean:
	rm -rf $(OBJECTS) $(EXECUTABLE) core dragonfly.log Makefile.bak *~

depend: 
	makedepend *.cpp 2> /dev/null
