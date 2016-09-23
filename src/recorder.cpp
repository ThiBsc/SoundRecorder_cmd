#include "header/recorder.h"

Recorder::Recorder()
{
    status = WAIT;
    corrector = 0;
}

Recorder::~Recorder()
{
    //dtor
}
int Recorder::getStatus()
{
    return status;
}

bool Recorder::onProcessSamples(const sf::Int16 *samples, std::size_t sampleCount)
{
    if (*samples == 0){
        if (status == RECORD){
            if (corrector > 2){
                status = END;
                std::cout << "Saving..." << std::endl;
                return false;
            }
            else
                corrector++;
        }
    }
    else{
        if (status == WAIT){
        	std::cout << "Recording..." << std::endl;
            status = RECORD;
        }
        if (corrector > 0)
            corrector = 0;
        return sf::SoundBufferRecorder::onProcessSamples(samples, sampleCount);
    }
    return true;
}