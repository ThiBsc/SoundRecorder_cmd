#include <iostream>
#include <getopt.h>
#include <unistd.h>
#include "header/recorder.h"

using namespace std;

int help=0, verbose=0, max_blank=2;
unsigned int sampleRate = 44100;
const string progname = "soundrec";

void print_help();

int main(int argc, char *argv[])
{
    int idxopt, opt;
    string outFile="";
    struct option t_opt[] =
    {
        {"help",        no_argument,        &help,      1},
        {"verbose",     no_argument,        &verbose,   2},
        {"corrector",   required_argument,  NULL,       'c'},
        {"srate",       required_argument,  NULL,       'r'},
        {0,         0,              NULL,       0}
    };

    while ((opt = getopt_long(argc, argv, "hvc:r:o:", t_opt, &idxopt)) != -1){
        switch (opt){
            case 'o':
                outFile = optarg;
                break;
            case 'c':
                max_blank = atoi(optarg);
                break;
            case 'r':
                sampleRate = (unsigned int) atoi(optarg);
                break;
            case 'v':
                verbose = 1;
                break;
            case 'h':
                help = 1;
                break;
            default:
                break;
        }
    }
    bool ret = EXIT_SUCCESS;
    if (help || outFile == ""){
        print_help();
    }
    else{
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
        cout << "Waiting sound..." << endl;

        if (sf::SoundBufferRecorder::isAvailable()){
            rec->start(sampleRate);
            while (rec->getStatus() != Recorder::END);
            rec->stop();

            // Get the buffer containing the captured audio data
            const sf::SoundBuffer& buffer = rec->getBuffer();
            if (verbose){
                // Display captured sound informations
                cout << "Sound information:" << endl;
                cout << " " << buffer.getDuration().asSeconds() << " seconds"           << endl;
                cout << " " << buffer.getSampleRate()           << " samples / seconds" << endl;
                cout << " " << buffer.getChannelCount()         << " channels"          << endl;
            }
            // Save it to a file (for example...)
            if (buffer.saveToFile(outFile))
                ret = EXIT_SUCCESS;
            else
                ret = EXIT_FAILURE;
        }
        else{
            cout << "Buffer recorder not available." << endl;
        }
        delete rec;
        cout << "Good bye!\n" << endl;
    }
    return ret;
}

void print_help(){
    cout << "usage: " << progname << " -o music.ogg [-OPTION...]\n"
        "\t--help, -h\t Show help\n"
        "\t--verbose, -v\t Verbose mode\n"
        "\t-o music.ogg\t Specify the out file (.wav, .ogg, .flac)\n"
        "\t--corrector N\t Max blank time (default 2)\n"
        "\t--srate\t\t Sample rate (default 44100)\n"
        "The record stop automatically when the music stop.\n";
}