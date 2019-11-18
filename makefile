###
### @file - project3_makefile
### @author - Michael Nutt <nuttm@oregonstate.edu>
### @description - makefile for Project 3 - Fantasy Combat Game

#
# Fantasy Combat Game
#

CXX = g++

CFLAGS = -std=c++11

.PHONY: clean

fantasyTournament: fantasyTournament.o menu.o inputValidation.o randomNum.o game.o character.o characterQueue.o barbarian.o vampire.o blueMen.o medusa.o harryPotter.o
	$(CXX) $(CFLAGS) -g fantasyTournament.o menu.o inputValidation.o randomNum.o game.o character.o characterQueue.o barbarian.o vampire.o blueMen.o medusa.o harryPotter.o -o fantasyTournament

fantasyTournament.o: fantasyTournament.cpp
	$(CXX) $(CFLAGS) -c fantasyTournament.cpp

menu.o: menu.cpp menu.hpp
	$(CXX) $(CFLAGS) -c menu.cpp

inputValidation.o: inputValidation.cpp inputValidation.hpp
	$(CXX) $(CFLAGS) -c inputValidation.cpp

randomNum.o: randomNum.cpp randomNum.hpp
	$(CXX) $(CFLAGS) -c randomNum.cpp

game.o: game.cpp game.hpp
	$(CXX) $(CFLAGS) -c game.cpp

character.o: character.cpp character.hpp
	$(CXX) $(CFLAGS) -c character.cpp

characterQueue.o: characterQueue.cpp characterQueue.hpp
	$(CXX) $(CFLAGS) -c characterQueue.cpp

barbarian.o: barbarian.cpp barbarian.hpp
	$(CXX) $(CFLAGS) -c barbarian.cpp

vampire.o: vampire.cpp vampire.hpp
	$(CXX) $(CFLAGS) -c vampire.cpp

blueMen.o: blueMen.cpp blueMen.hpp
	$(CXX) $(CFLAGS) -c blueMen.cpp

medusa.o: medusa.cpp medusa.hpp
	$(CXX) $(CFLAGS) -c medusa.cpp

harryPotter.o: harryPotter.cpp harryPotter.hpp
	$(CXX) $(CFLAGS) -c harryPotter.cpp

clean:
	rm *.o fantasyTournament