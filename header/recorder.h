#ifndef RECORDER_H
#define RECORDER_H

#include <SFML/Audio.hpp>


class Recorder : public sf::SoundBufferRecorder
{
    public:
        Recorder();
        virtual ~Recorder();
    protected:
    private:
};

#endif // RECORDER_H
