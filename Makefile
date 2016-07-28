CCOPTS=-Wall

soundrecorder: recorder.o main.o
	LD_LIBRARY_PATH=~/Library/SFML-2.3.2/lib g++ $(CCOPTS) -o soundrecorder main.o recorder.o -L ~/Library/SFML-2.3.2/lib -lsfml-audio -lsfml-system

recorder.o: recorder.cpp header/recorder.h
	g++ $(CCOPTS) -c recorder.cpp header/recorder.h -I ~/Library/SFML-2.3.2/include

main.o: main.cpp header/recorder.h
	g++ $(CCOPTS) -c main.cpp header/recorder.h -I ~/Library/SFML-2.3.2/include