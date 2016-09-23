CXX=g++
CCOPTS=-Wall -DSFML_STATIC
LIBS=-lsfml-audio-s -lsfml-system-s -lpthread -lopenal -lvorbis -lvorbisfile -lvorbisenc -logg -lFLAC
ODIR=obj
SDIR=src

all: soundrecorder.exe

soundrecorder.exe: obj/recorder.o obj/main.o
	$(CXX) -o $@ obj/recorder.o obj/main.o $(LIBS) $(CCOPTS)

obj/recorder.o: src/recorder.cpp #$(SDIR)/header/recorder.h
	$(CXX) -o $@ -c src/recorder.cpp

obj/main.o: src/main.cpp #$(SDIR)/header/recorder.h
	$(CXX) -o $@ -c src/main.cpp

clean:
	rm $(ODIR)/*.o ./*.exe
