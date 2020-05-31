int trigger_pin = 2;
int echo_pin = 3;
int pot_pin = A2;
int register_pin = 7;
float distance;
int echo_time;
int going_up = 0;

char char_set[4][7] = {{'.',' ','a','b','c','d','e'},{'f','g','h','i','j','k','l'},{'m','n','o','p','q','r','s'},{'t','u','v','w','x','y','z'}};

void setup() {
  Serial.begin(9600);
  pinMode(trigger_pin, OUTPUT);
  pinMode(echo_pin, INPUT);
  pinMode(pot_pin, INPUT);
  pinMode(register_pin, INPUT);
}

void loop() {
  digitalWrite(trigger_pin, HIGH);
  delayMicroseconds(1000);
  digitalWrite(trigger_pin, LOW);
  echo_time = pulseIn(echo_pin, HIGH);
  distance = (echo_time * 0.034) / 2;
  //Serial.println(distance); 
  
  if(digitalRead(register_pin) == HIGH) {
    going_up += 1;
  } else {
    going_up = 0;
  }

  
  char output_char = get_char(distance);
  if(going_up > 20) {
    Serial.print("\n1 ");
    Serial.print(output_char);
    going_up = 0;
    delay(2000);
  } else {
    Serial.print("\n0 ");
    Serial.print(output_char);
  }
  
  
}

char get_char(float distance) {
  int pot_val = analogRead(pot_pin);
  int mode = (int)floor(pot_val/256);

  int trb_pos = (int)abs(floor(distance/4));
  if (trb_pos > 7) {
    trb_pos = 7;
  }
  char output = char_set[mode][trb_pos];
  return output;
}
