// -----------------------------------
// Starting and Stopping Car Remotely Over the Internet
// -----------------------------------

// Define the Start and Stop pins

int start = D0;
int stop = D1;

void setup()
{
    
   // Pin Configuration
   pinMode(start, OUTPUT);
   pinMode(stop, OUTPUT);

   // Register the Particle Function to work on the web and IFTTT
   Particle.function("carstarter", remotestarter);

   // Make sure everything is off before running commmands
   digitalWrite(start, HIGH);
   digitalWrite(stop, HIGH);
   
}

void loop()
{
   // Nothing to do here
}

int remotestarter(String command) {
    /* Particle.functions always take a string as an argument and return an integer.
    Since we can pass a string, it means that we can give the program commands on how the function should be used.
    In this case, telling the function "on" will turn the car on and telling it "off" will turn the car off.
    Then, the function returns a value to us to let us know what happened.
    In this case, it will return 1 when starting and stopping the car,
    and 0 if we received a totally bogus command that didn't do anything to the car.
    */
    
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
