/**
 * @file streams-memory_mp3_short-i2s-2.ino
 * @author Phil Schatzmann
 * @brief decode MP3 stream and output as i2s signal
 * @version 0.1
 * @date 2021-01-24
 * 
 * @copyright Copyright (c) 2021
 
 */

#include "SPIFFS.h"
#include "AudioTools.h"
#include "AudioCodecs/CodecMP3Helix.h"
#include "MyAudioPlayer.h"

MyAudioPlayer myAudioPlayer;

void setup(){
  Serial.begin(115200);
  AudioLogger::instance().begin(Serial, AudioLogger::Info);  
  // begin processing
  myAudioPlayer.begin();  
}


void loop(){

  myAudioPlayer.play();

  vTaskDelay(500/portTICK_PERIOD_MS);

}