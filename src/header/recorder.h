#ifndef RECORDER_H
#define RECORDER_H

#include <SFML/Audio.hpp>
#include <iostream>

class Recorder : public sf::SoundBufferRecorder
{
    public:
        Recorder();
        virtual ~Recorder();
    	bool bRecEnd;
    protected:
    	virtual bool onProcessSamples(const sf::Int16 *samples, std::size_t sampleCount);
    private:
    	bool bRec;
    	int corrector;
};

#endif // RECORDER_H
