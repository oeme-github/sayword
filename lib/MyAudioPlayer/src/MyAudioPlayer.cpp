#include "MyAudioPlayer.h"


/**
 * @brief Construct a new Audio Player object
 * 
 */
MyAudioPlayer::MyAudioPlayer(){}
/**
 * @brief Destroy the Audio Player object
 * 
 */
MyAudioPlayer::~MyAudioPlayer(){}

/**
 * @brief setup the audio
 * 
 */
void MyAudioPlayer::begin(int sample_rate_, int channels_, float_t fVolume_, String filename_)
{
    this->sample_rate=sample_rate_;
    this->channels=channels_;
    this->fVolume=fVolume_;
    this->filename=filename_;
    // setup audio
    auto cfg        = i2s.defaultConfig();
    cfg.sample_rate = this->sample_rate;
    cfg.channels    = this->channels;
    i2s.begin(cfg);
    volume.setTarget(i2s);
    volume.setVolumeControl(lvc);
    volume.setVolume(fVolume_);
    out_obj.begin(&volume, &helix);
    copier = StreamCopy(out_obj, audioFile);
}
/**
 * @brief play the sound
 * 
 */
void MyAudioPlayer::play() 
{
    // if you put this file in a loop it plays same file over and over again
    // init
    SPIFFS.begin("/"); // could leed to a warning if SPIFF is already in place
    this->audioFile = SPIFFS.open(this->filename, FILE_READ);
    helix.begin();
    volume.setVolume(this->fVolume);
    copier.copyAll();
    helix.end();
    audioFile.close();
}
