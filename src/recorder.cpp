#include "header/recorder.h"

Recorder::Recorder()
{
    bRec = false;
    bRecEnd = false;
    corrector = 0;
}

Recorder::~Recorder()
{
    //dtor
}

bool Recorder::onProcessSamples(const sf::Int16 *samples, std::size_t sampleCount)
{
    if (*samples == 0){
        if (bRec){
            if (corrector > 2){
                bRecEnd = true;
                std::cout << "Saving..." << std::endl;
                return false;
            }
            else
                corrector++;
        }
    }
    else{
        if (!bRec){
        	std::cout << "Recording..." << std::endl;
            bRec = true;
        }
        if (corrector > 0)
            corrector = 0;
        return sf::SoundBufferRecorder::onProcessSamples(samples, sampleCount);
    }
    return true;
}