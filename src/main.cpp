#include <Arduino.h>

#include "esp_system.h"
#include "esp_event.h"
#include "esp_log.h"
#include "esp_attr.h"

#include "DFRobot_DF1201S.h"

  DFRobot_DF1201S DF1201S;

void setup()
{

  pinMode(LED_BUILTIN, OUTPUT);
  digitalWrite(LED_BUILTIN, HIGH);

  Serial.begin(19200);
  while (!Serial)
    ;

  delay(2000);
  ESP_LOGI(TAG, "Helllllo! I'm up and running on on %s!", ARDUINO_VARIANT);

  Serial2.begin(115200);
  while (!Serial2)
    ;


  while (!DF1201S.begin(Serial2))
  {
    Serial.println("Init failed, please check the wire connection!");
    delay(1000);
  }

  DF1201S.setPrompt(false);

    DF1201S.setVol(/*VOL = */20);
  Serial.print("VOL:");
  /*Get volume*/
  Serial.println(DF1201S.getVol());


    /*Enter music mode*/
  DF1201S.switchFunction(DF1201S.MUSIC);
  /*Wait for the end of the prompt tone */
  delay(2000);
  /*Set playback mode to "repeat all"*/
  DF1201S.setPlayMode(DF1201S.SINGLE);
  Serial.print("PlayMode:");
  /*Get playback mode*/
  Serial.println(DF1201S.getPlayMode());

}

void loop(){
  Serial.println("Start playing");
  /*Start playing*/
  DF1201S.start();
  delay(3000);
  Serial.println("Pause");
  /*Pause*/
  DF1201S.pause();
  delay(3000);
  Serial.println("Next");
  /*Play the next song*/
  DF1201S.next();
  delay(3000);
  Serial.println("Previous");
  /*Play the previous song*/
  DF1201S.last();
  delay(3000);
  Serial.println("Start playing");
  //Fast forward 10S
  DF1201S.fastForward(/*FF = */10);
  //Fast Rewind 10S
  //DF1201S.fastReverse(/*FR = */10);
  //Start the song from the 10th second 
  //DF1201S.setPlayTime(/*Play Time = */10);

  Serial.print("File number:");
  //Get file number
  Serial.println(DF1201S.getCurFileNumber());

  Serial.print("The number of files available to play:");
  //The number of files available to play
  Serial.println(DF1201S.getTotalFile());

  Serial.print("The time length the current song has played:");
  //Get the time length the current song has played 
  Serial.println(DF1201S.getCurTime());

  Serial.print("The total length of the currently-playing song: ");
  //Get the total length of the currently-playing song 
  Serial.println(DF1201S.getTotalTime());
  Serial.print("The name of the currently-playing file: ");
  //Get the name of the playing file 
  Serial.println(DF1201S.getFileName());
  delay(3000);
  //Play the file No.1, the numbers are arranged according to the sequence of the files copied into the U-disk 
  DF1201S.playFileNum(/*File Number = */1);
  //Play the test.mp3 file in test folder 
  //DF1201S.playSpecFile("/test/test.mp3");

  DF1201S.disableAMP();
  DF1201S.setLED(false);

  while(1);
  /*Delete the currently-playing file */
  //DF1201S.delCurFile();
}