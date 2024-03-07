#include <Arduino.h>

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
  Serial.begin(115200);
  pinMode(SAMPLING, OUTPUT);
  pinMode(PWMOUT, OUTPUT);
  digitalWrite(SAMPLING, LOW);

  Serial.print("Starting...\n");

  while(1) {
    if (analogRead(A0) > 512) break;
  }
  
  Serial.println("PV connected, MPPT starts");
  analogWrite(PWMOUT, byte_Ton);
}

void loop() {
  pv_sen();
  check_over_v_out();
  check_over_time_limit();
  mppt_tracking();
  print_para();
  
  long_time_limit++;
  digitalWrite(SAMPLING, LOW);
  delay(LOOP_TIME);
}

void pv_sen() {
  float_v_pv = analogRead(A0) * 0.0048828125;
  float_i_pv = analogRead(A1) * 0.0048828125;
  float_v_out = analogRead(A2) * 0.0048828125;
}

void check_over_v_out() {
  if (float_v_out > VOUT_LIMIT) {
    analogWrite(PWMOUT, 0);
    digitalWrite(SAMPLING, LOW);
    while (1); // Stop the program
  }
}

void check_over_time_limit() {
  if (long_time_limit > TIME_LIMIT) {
    analogWrite(PWMOUT, 0);
    digitalWrite(SAMPLING, LOW);
    while (1); // Stop the program
  }
}

void mppt_tracking() {
  float_p_pv_k0 = float_v_pv * float_i_pv;
  float_dPdV = (float_p_pv_k0 - float_p_pv_k1) / (float_v_pv - float_v_pv_k1);

  if (float_dPdV < 0) {
    int_slope *= -1;
  }

  byte_Ton += int_slope * TON_STEP;

  if (byte_Ton > 255) {
    byte_Ton = 255;
  } else if (byte_Ton < 1) {
    byte_Ton = 1;
  }

  float_v_pv_k1 = float_v_pv;
  float_i_pv_k1 = float_i_pv;
  float_p_pv_k1 = float_p_pv_k0;
  
  analogWrite(PWMOUT, byte_Ton);
}

void print_para() {
  Serial.print("V_pv: ");
  Serial.print(float_v_pv);
  Serial.print(" I_pv: ");
  Serial.print(float_i_pv);
  Serial.print(" V_out: ");
  Serial.print(float_v_out);
  Serial.print(" P_pv: ");
  Serial.println(float_p_pv);
}

