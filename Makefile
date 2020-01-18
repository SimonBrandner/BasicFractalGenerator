# OBJS specifies which files to compile as part of the project
OBJS =  Main.cpp Engine.cpp Game.cpp

# OBJ_NAME specifies the name of our exectuable
OBJ_NAME = Fractal.run

# Include path
INC=-I/usr/local/include/SDL2/

#This is the target that compiles our executable
all : $(OBJS)
	g++ $(OBJS) -g -w -lSDL2 -o $(OBJ_NAME) -L./ ${INC}
