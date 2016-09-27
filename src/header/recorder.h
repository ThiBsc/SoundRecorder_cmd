#ifndef RECORDER_H
#define RECORDER_H

#include <SFML/Audio.hpp>
#include <iostream>

class Recorder : public sf::SoundBufferRecorder
{
    public:
        Recorder();
        virtual ~Recorder();
        enum RECSTATUS { WAIT=0, RECORD, END };
        RECSTATUS getStatus();
    protected:
    	virtual bool onProcessSamples(const sf::Int16 *samples, std::size_t sampleCount);
    private:
    	RECSTATUS status;
    	int corrector;
};

#endif // RECORDER_H
