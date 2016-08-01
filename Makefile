CXX=g++
CCOPTS=-Wall -DSFML_STATIC
LIBS=-lsfml-audio-s -lsfml-system-s -lpthread -lopenal -lvorbis -lvorbisfile -lvorbisenc -logg -lFLAC
ODIR=obj
SDIR=src

soundrecorder: recorder.o main.o
	$(CXX) $(CCOPTS) -o soundrecorder $(ODIR)/main.o $(ODIR)/recorder.o $(LIBS)

recorder.o: $(SDIR)/recorder.cpp $(SDIR)/header/recorder.h
	$(CXX) $(CCOPTS) -c $(SDIR)/recorder.cpp -o $(ODIR)/recorder.o

main.o: $(SDIR)/main.cpp $(SDIR)/header/recorder.h
	$(CXX) $(CCOPTS) -c $(SDIR)/main.cpp -o $(ODIR)/main.o

clean:
	rm $(ODIR)/*.o
