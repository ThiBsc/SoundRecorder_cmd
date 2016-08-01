#include <iostream>
#include "header/recorder.h"

using namespace std;

int main()
{
    Recorder *rec = new Recorder();

    int device;
    std::vector<std::string> devices = rec->getAvailableDevices();
    cout << "Choose a device for record\n" << endl;
    for (int i=0; i<(int)devices.size(); i++)
        cout << i << " . " << devices.at(i) << endl;
    cout << endl;
    cin >> device;
    cout << "Setting -> " << devices.at(device) << endl;
    rec->setDevice(devices.at(device));
    cout << "Start recording..." << endl;
    cout << "Press a key and enter for stop" << endl;

    rec->start();

    char key;
    cin >> key;

    rec->stop();
    // Get the buffer containing the captured audio data
    const sf::SoundBuffer& buffer = rec->getBuffer();
    // Display captured sound informations
    cout << "Sound information:" << endl;
    cout << " " << buffer.getDuration().asSeconds() << " seconds"           << endl;
    cout << " " << buffer.getSampleRate()           << " samples / seconds" << endl;
    cout << " " << buffer.getChannelCount()         << " channels"          << endl;
    // Save it to a file (for example...)
    buffer.saveToFile("/home/thibaut/my_record.wav");

    cout << "Good bye!\n" << endl;
    delete rec;

    return 0;
}
