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
Recorder::RECSTATUS Recorder::getStatus()
{
    return status;
}

bool Recorder::onProcessSamples(const sf::Int16 *samples, std::size_t sampleCount)
{
    bool ret = true;
    if (*samples == 0){
        if (status == RECORD){
            if (corrector > max_blank){
                status = END;
                std::cout << "Saving..." << std::endl;
                return false;
            }
            else{
                corrector++;
            }
        }
    }
    else{
        if (status == WAIT){
        	std::cout << "Recording..." << std::endl;
            status = RECORD;
        }
        if (corrector > 0){
            corrector = 0;
        }
        ret = sf::SoundBufferRecorder::onProcessSamples(samples, sampleCount);
    }
    return ret;
}