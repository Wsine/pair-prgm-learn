/*
Arduino code that plays a tone on a speaker.
*/

// Define the setup() function, which is executed only once during powerup.
void setup() {

}

// Define the loop() function, which is called repeatedly during the program execution.
void loop() {
    // Play a tone at 2000 Hz frequency and 100 ms duration on pin 9.
    // Hint: Use the tone() function with 9 as the pin number, 2000 as the frequency, and 100 as the duration.
    tone(9, 2000, 100);

    // Wait for 1000 milliseconds (1 second) before executing the next command.
    // Hint: Use the delay() function with 1000 as its argument.
    delay(1000);
}
