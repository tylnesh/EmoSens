/* 
This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/


  #include <nRF24L01.h>
  #include <printf.h>
  #include <RF24.h>
  #include <RF24_config.h>
  #include <SPI.h>

   #define RF_CE    9
  #define RF_CSN   10 //piny na ktorych je antena


#define WIRE 1


  //*********************Komunikacia *******************************************************************
  
  RF24 radio(RF_CE, RF_CSN);
  
  const uint64_t pipes[2] = { 0xABCDABCD71LL, 0x544d52687CLL };  // na druhom arduine/rpi treba prehodit tie pipes, aby boli opacne
  
  struct message {
    int wire = 1; //na rozlisovanie medzi jednotlivymi zariadeniami
    int i = 0; //ak chces poslat int
    String str = ""; // string, atd..
  
  };
  
  message outgoing;
  message incoming;

  int in;
  
  void sndMsg()
  
  { radio.stopListening();
    Serial.println(F("Sending message..."));
    outgoing.wire = WIRE;
    for (int i =0; i<3; i++) { radio.write(&outgoing,sizeof(message)); delay(100);} //poslanie troch rovnakych sprav, pre jednu staci len to radio.write(&outgoing,sizeof(message));
    
    
    //NEZABUDNI DELAY!!!!
    radio.startListening();
  }
  
  void rcvMsg()
  
  { 
    radio.startListening();
    while (radio.available()) {
      Serial.println(F("Receiving message..."));
      radio.read(&incoming, sizeof(message));
      if(incoming.wire == WIRE)
      {
      Serial.println(incoming.i);
      Serial.print(incoming.str);
      }
    }
  }
  
  void setup()
  {
    Serial.begin(9600);
 
    outgoing.wire = WIRE;
    
    printf_begin();
  
    radio.begin();                           // Setup and configure rf radio
    radio.setChannel(1);
    radio.setPALevel(RF24_PA_MIN);
    radio.setDataRate(RF24_250KBPS);
    radio.setAutoAck(true);                     // Ensure autoACK is enabled
    radio.setRetries(5, 30);                 // Optionally, increase the delay between retries & # of retries
  
    radio.setCRCLength(RF24_CRC_8);          // Use 8-bit CRC for performance
  
    radio.openWritingPipe(pipes[0]);
    radio.openReadingPipe(1, pipes[1]);
  
    radio.stopListening();                 // Start listening
    radio.printDetails();                   // Dump the configuration of the rf unit for debugging
  
  
  
  radio.startListening();
  in=22;
  }
 
  void loop() {
//rcvMsg();
//Serial.println(incoming.str);
//delay(500);
  if(radio.available())
  {
    radio.read(&in, 1);
    Serial.println(in);
    }
  }
  
  
  
  
 
