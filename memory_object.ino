#include <SD.h> //SD reader library
#include <TMRpcm.h> //WAV playback library
#include <SPI.h> //SPI library

#define SD_ChipSelectPin 10

// delay function for serial log, used during recording
void wait_min(float mins) {
  int count = 0;
  float secs = mins * 60;
  while (1) {
    Serial.print('.');
    delay(1000);
    count++;
    if (count == secs) {
      count = 0;
      break;
    }
  }
  Serial.println();
  return ;
}

TMRpcm tmrpcm;

int playButton = 4; //play
int playState;
int nextWavBn = 2;
int nextWav;
int prevWavBn = 3;
int prevWav;
int micButton = 6; //recording
int micState;
int piezoPin = A3;
int piezoState;
int threshold = 100;
int tilt = 7;
int tiltState;
//int buttonState1;
//int buttonState2; // the current reading from the input pin
int lastButtonState = LOW;   // the previous reading from the input pin
long buttonMillis = 0; // variable for reading the pushbutton start time
const long intervalButton = 2000;   // length of button hold

int memory[11] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10}; //switch case array

//recorded file settings
int file_number = 0;
char filePrefixname[50] = "Testing";
char exten[10] = ".wav";
const int recordLed = 2;
const int micPin = A1;
const int sample_rate = 8000;

void setup() {
  pinMode(playButton, INPUT);
  pinMode(micButton, INPUT);
  pinMode(nextWav, INPUT);
  pinMode(prevWav, INPUT);
  pinMode(micPin, INPUT);
  pinMode(recordLed, OUTPUT);
  pinMode(piezoPin, INPUT);
  pinMode(tilt, INPUT);

  playState = LOW; //button default is off
  micState = LOW; //button default is off
  tiltState = LOW;
  nextWav = LOW;
  prevWav = LOW;

  tmrpcm.speakerPin = 9;

  Serial.begin(9600);
  if (!SD.begin(SD_ChipSelectPin)) {
    Serial.println("SD fail");
    return;   // don't do anything more if not
  }
  tmrpcm.setVolume(5);
  //tmrpcm.play("geese.wav");


}

void loop() {
  playState = digitalRead(playButton);
  micState = digitalRead(micButton);
  nextWav = digitalRead(nextWavBn);
  prevWav = digitalRead(prevWavBn);
  tiltState = digitalRead(tilt);
  piezoState = analogRead(piezoPin);

  tmrpcm.disable();

  //debounce stuff
  unsigned long currentMillis = millis();

  Serial.print("micState: ");
  Serial.println(micState);
  Serial.print("piezoState: ");
  Serial.println(piezoState);
  Serial.print("playState: ");
  Serial.println(playState);
  Serial.print("nextState: ");
  Serial.println(nextWav);
  Serial.print("prevState: ");
  Serial.println(prevWav);


  //recording audio
  if (micState == HIGH) {
    Serial.println("####################################################################################");
    Serial.println("Mic button pressed");
    char fileSlNum[20] = "";
    itoa(file_number, fileSlNum, 10);
    char file_name[50] = "";
    strcat(file_name, filePrefixname);
    strcat(file_name, fileSlNum);
    strcat(file_name, exten);

    Serial.print("New File Name: ");
    Serial.println(file_name);
    digitalWrite(recordLed, HIGH);

    tmrpcm.startRecording(file_name, sample_rate, micPin);
    Serial.println("startRecording ");
    // record audio for 2mins. means, in this loop process record 2mins of audio.
    // if you need more time duration recording audio then
    // pass higher value into the wait_min(int mins) function.
    wait_min(0.5); // This is the length of the audio file which is set to 2 minutes

    digitalWrite(recordLed, LOW);
    tmrpcm.stopRecording(file_name);
    Serial.println("stopRecording");
    file_number++;

    Serial.println("####################################################################################");
  }

  delay(20);

  //playing recordings back
  if (SD.exists("TESTING0.WAV") && micState == HIGH) {
    Serial.println("File exists");
    tmrpcm.play("TESTING0.WAV");
    delay(30000);
    tmrpcm.stopPlayback();
  } else {
    Serial.println("No File");
    tmrpcm.disable();
  }

  //delay(30000);

  /*if (SD.exists("REC1.WAV")) {
    Serial.println("Rec1 exists");
    tmrpcm.play("REC1.WAV");
    delay(60000);
    tmrpcm.stopPlayback();
    } else {
    Serial.println("Rec1 not here");
    }*/


  //  if (buttonPin == LOW && currentMillis - buttonMillis > intervalButton) {
  //    tmrpcm.play("geese.wav");
  //    delay(4000);
  //    Serial.println("button pressed");
  //    if (!tmrpcm.isPlaying()){
  //      tmrpcm.pause();
  //    }
  //  }
  //
  //  else {
  //    tmrpcm.pause();
  //    Serial.println("no button");
  //  }

  if (nextWav == HIGH) {
    Serial.println("next pressed");
    tmrpcm.play("roxannememory.wav");
    delay(260000);

  }

  if (piezoState > threshold) {
    Serial.println("Play pressed");
    for (int i = 0; i < 8; i++) { // Birthday w/ Grandma memory
      switch (memory[i]) {
        case 0:
          tmrpcm.play("cardoor.wav");
          delay(9500);
          break;

        case 1:
          tmrpcm.play("kidstalk.wav");
          delay(8000);
          break;

        case 2:
          tmrpcm.play("arrive.wav");
          delay(4000);
          break;

        case 3:
          tmrpcm.play("crickets.wav");
          delay(4500);
          break;

        case 4:
          tmrpcm.play("match.wav");
          delay(6000);
          break;

        case 5:
          tmrpcm.play("bday.wav");
          delay(13000);
          break;

        case 6:
          tmrpcm.play("applause.wav");
          delay(7000);
          break;

        case 7:
          tmrpcm.play("grandma.wav");
          delay(8000);
          tmrpcm.stopPlayback();
          break;

          return;

      }
      tmrpcm.pause();
      tmrpcm.stopPlayback();
      tmrpcm.disable();
    }
    tmrpcm.disable();
  }

  // Cat memory
  else if (nextWav == HIGH) {
    Serial.println("Next button pressed");
    for (int i = 0; i < 7; i++) {
      switch (memory[i]) {
        case 0:
          tmrpcm.play("purr1.wav");
          delay(5000);
          break;

        case 1:
          tmrpcm.play("rain1.wav");
          delay(5000);
          break;

        case 2:
          tmrpcm.play("meow2.wav");
          delay(4000);
          break;

        case 3:
          tmrpcm.play("pages.wav");
          delay(3500);
          break;

        case 4:
          tmrpcm.play("enter.wav");
          delay(4000);
          break;

        case 5:
          tmrpcm.play("petwalk.wav");
          delay(5000);
          break;

        case 6:
          tmrpcm.play("meow3.wav");
          delay(3500);
          break;

          tmrpcm.stopPlayback();
      }
    }
  }

  // memory love
  //else if (buttonPin == LOW && currentMillis - buttonMillis > intervalButton * 2) {
  //  tmrpcm.disable();
  //    for (int i = 0; i < 11; i++) {
  //    switch (memory[i]) {
  //
  //      case 0:
  //        tmrpcm.play("victrola.wav");
  //        delay(14000);
  //        break;
  //
  //      case 1:
  //        tmrpcm.play("beso.wav");
  //        delay(6000);
  //        break;
  //
  //       case 2:
  //          tmrpcm.play("laugh.wav");
  //          delay(2000);
  //          break;
  //
  //      case 3:
  //        tmrpcm.play("manlaugh.wav");
  //        delay(7000);
  //        break;
  //
  //      case 4:
  //        tmrpcm.play("wed.wav");
  //        delay(6800);
  //        break;
  //
  //      case 5:
  //        tmrpcm.play("claps.wav");
  //        delay(6300);
  //        break;
  //
  //      case 6:
  //        tmrpcm.play("clink.wav");
  //        delay(2000);
  //        break;
  //
  //      case 7:
  //        tmrpcm.play("newborn.wav");
  //        delay(11000);
  //        break;
  //
  //      case 8:
  //        tmrpcm.play("lullaby.wav");
  //        delay(10000);
  //        break;
  //
  //      case 9:
  //        tmrpcm.play("lunch.wav");
  //        delay(8100);
  //        break;
  //
  //      case 10:
  //        tmrpcm.play("goodbye.wav");
  //        delay(2100);
  //        break;
  //
  //        return;
  //
  //    }
  //    tmrpcm.stopPlayback();
  //    }

}
