// -----------------------------------
// Starting and Stopping Car Remotely Over the Internet with Alexa Integration
// -----------------------------------
// Code written by Austin Hable and Chris Hanson
// EchoPhotonBridge.cpp and EchoPhotonBridge.h written by JeremyProffitt https://github.com/JeremyProffitt/EchoPhotonBridge

// Add the EchoPhontonBridge Library to your code
#include "EchoPhotonBridge.h"

// Create a new EchoPhotonBridge instance
EchoPhotonBridge epb;

// Define the Start and Stop pins
int start = D0;
int stop = D1;

// Create a function to call when you tell Alexa to turn something on or off
int functionOnOff(int device, bool onOff, String rawParameters) { 
        
// Do something when the on or off command is sent. On will start the car and Off with turn off the car.
if(onOff){
    digitalWrite(start,LOW);
    delay(3000);
    digitalWrite(start,HIGH);
    return 1;
}

else {
    digitalWrite(stop,LOW);
    delay(3000);
    digitalWrite(stop,HIGH);
    return 1;
}
    
}

void setup() {
    pinMode(start, OUTPUT);
    pinMode(stop, OUTPUT);
    
// Register the Particle Function to work on the web and IFTTT
    Particle.function("carstarter", remotestarter);
       
// Make sure everything is off before running commmands
   digitalWrite(start, HIGH);
   digitalWrite(stop, HIGH);
   
// This line adds "Turn My Car" to your Alexa, 
// when you say "Alexa Turn My Car On" the functionOnOff is called.
    epb.addEchoDeviceV2OnOff("Turn My Car", &functionOnOff);
}

void loop() {
}

// This cammand function is used when turning the car on and off from IFTTT or from a custom webpage.
int remotestarter(String command) {

    /* Particle.functions always take a string as an argument and return an integer.
    Since we can pass a string, it means that we can give the program commands on how the function should be used.
    In this case, telling the function "on" will turn the car on and telling it "off" will turn the car off.
    Then, the function returns a value to us to let us know what happened.
    In this case, it will return 1 when starting and stopping the car,
    and 0 if we received a totally bogus command that didn't do anything to the car. */
    
    
    if (command=="Start Car") {
        digitalWrite(start,LOW);
        delay(3000);
        digitalWrite(start,HIGH);
        return 1;
    }
    
    else if (command=="Stop Car") {
        digitalWrite(stop,LOW);
        delay(3000);
        digitalWrite(stop,HIGH);
        return 1;
    }
    else {
        return 0;
    }
}
