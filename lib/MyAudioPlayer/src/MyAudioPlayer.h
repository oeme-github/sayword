#pragma once

#include "SPIFFS.h"
#include "AudioTools.h"
#include "AudioCodecs/CodecMP3Helix.h"

/**
 * @brief audio 
 * 
 */
class MyAudioPlayer
{
private:
    I2SStream i2s; 
    MP3DecoderHelix helix;
    EncodedAudioStream out_obj;
    StreamCopy copier;
    VolumeStream volume;
    LogarithmicVolumeControl lvc;

    int sample_rate = 24000;
    int channels    = 1;
    float_t fVolume = 1.0;
    String filename = "/beep.mp3";
    File audioFile;

/**
 * @brief Constructor, Destructur
 * 
 */
public:
    /**
     * @brief Construct a new Audio Player object
     * 
     */
    MyAudioPlayer();
    /**
     * @brief Destroy the Audio Player object
     * 
     */
    ~MyAudioPlayer();

/**
 * @brief public methodes
 * 
 */
public:
    /**
     * @brief startup sequence
     * 
     */
    void begin(int sample_rate_=24000, int channels_=1, float_t fVolume_=1.0, String filename_="/beep.mp3");
    /**
     * @brief play the sound file
     * 
     */
    void play();
    /**
     * @brief Set the Volume object
     * 
     * @param fVolume_ 
     */
    void setVolume( float_t fVolume_ ){ this->fVolume = fVolume_;}
    /**
     * @brief Get the Volume object
     * 
     * @return uint32_t 
     */
};
