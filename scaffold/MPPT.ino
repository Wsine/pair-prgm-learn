// Define input constant name
#define SAMPLING 11
#define PWMOUT 5
#define VOUT_LIMIT 25
#define TON_STEP 5
#define LOOP_TIME 300
#define TIME_LIMIT 3000

// Solar panel variables
float float_i_pv;
float float_i_pv_k0 = 0;
float float_i_pv_k1 = 0;

float float_v_pv;
float float_v_pv_k0 = 0;
float float_v_pv_k1 = 0;

float float_p_pv;
float float_p_pv_k0 = 0;
float float_p_pv_k1 = 0;

// Converter variables
float float_duty;
float float_v_out;
byte byte_Ton;
byte byte_Ton_k0 = 1;
byte byte_Ton_k1 = 0;

int int_slope = 1;

int A1read;

float float_dPdV = 0;
float float_dPdV_k0;

long long_time_limit = 0;

void setup() {
  // Initialize serial communication at 115200 bits per second
  // Hint: Use Serial.begin() with 115200 as its argument
  
  // Configure pin modes for SAMPLING and PWMOUT as OUTPUT.
  // Hint: Use pinMode() function with SAMPLING and OUTPUT as its arguments
  // Hint: Use pinMode() function with PWMOUT and OUTPUT as its arguments

  // Set SAMPLING pin to LOW
  // Hint: Use digitalWrite() function with SAMPLING and LOW as its arguments

  // Display initial messages on the serial monitor
  // Hint: Use Serial.println() and Serial.print() functions
  
  // Wait for PV voltage to be higher than 2.5V before starting the program
  // Hint: Use while loop with analogRead() and if condition with break
  
  // Display messages to indicate PV is connected and the program starts
  // Hint: Use Serial.println() functions for this

  // Set initial PWM duty cycle
  // Hint: Use analogWrite() function with PWMOUT and byte_Ton as its arguments

}

void loop() {
  // Read PV voltage, current, and storage voltage from ADCs
  // Hint: Call pv_sen() function
  
  // Check if storage voltage has exceeded its limit
  // Hint: Call check_over_v_out() function

  // Check if the time limit has been exceeded
  // Hint: Call check_over_time_limit() function

  // Perform MPPT tracking
  // Hint: Call mppt_tracking() function

  // Print parameters on the serial monitor
  // Hint: Call print_para() function
  
  // Increment long_time_limit variable
  
  // Set SAMPLING pin to LOW
  // Hint: Use digitalWrite() function with SAMPLING and LOW as its arguments

  // Delay for LOOP_TIME
  // Hint: Use delay() function with LOOP_TIME as its argument

}

void pv_sen() {
  // Read PV voltage, current and storage voltage from ADCs and average their values to remove noise
  // Hint: Use analogRead() function and formula to calculate the values
}

void check_over_v_out() {
  // Check if storage voltage has exceeded its limit, and if so, stop the program
  // Hint: Use if condition with float_v_out and VOUT_LIMIT variables
  // Hint: analogWrite() to set PWM to 0, digitalWrite() with SAMPLING and LOW, and infinite while loop.
}

void check_over_time_limit() {
  // Check if the time limit is exceeded, and if so, stop the program
  // Hint: Use if condition with long_time_limit and TIME_LIMIT variables
  // Hint: analogWrite() to set PWM to 0, digitalWrite() with SAMPLING and LOW, and infinite while loop.
}

void mppt_tracking() {
  // Perform MPPT tracking logic to optimize the power output
  // Hint: Update variables with new values, calculate the dP/dV and adjust byte_Ton accordingly
  // Hint: Implement limits for byte_Ton and update PWM using analogWrite()
}

void print_para() {
  // Display information on the serial monitor by printing solar panel, MPPT, charger, and storage parameters
  // Hint: Use Serial.print() and Serial.println() functions to print the values 
}
