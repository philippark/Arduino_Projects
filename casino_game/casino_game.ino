int switchState = 0;
int delay_time = 250;
int start_pin = 3;
int curr_pin = 3;
int end_pin = 9;  
int target_pin = 6;

void on_all(){
  if (delay_time < 50){
    delay_time = 250;
  }
  for (int i = start_pin; i <= end_pin; i++){
    digitalWrite(i, HIGH);
  }
}


void off_all(){
  for (int i = start_pin; i <= end_pin; i++){
    digitalWrite(i, LOW);
  }
}

void setup() {
  // put your setup code here, to run once:
  pinMode(2, INPUT);

  for (int i = start_pin; i < end_pin; i++){
    pinMode(i, OUTPUT);
  }

}

void loop() {
  // put your main code here, to run repeatedly:
  switchState = digitalRead(2);

  off_all();

  if (curr_pin > end_pin){
      curr_pin = start_pin;
  }

  if (switchState == LOW){
    digitalWrite(target_pin, HIGH);
    digitalWrite(curr_pin, HIGH);
    delay(delay_time);
    curr_pin++;
  }
  
  else{
    if (curr_pin == target_pin){
      on_all();
      delay(200);
      off_all();
      delay(200);
      on_all();
      delay(200);
      off_all();
      delay(200);
      on_all();
      delay(500);

      delay_time *= 0.50;
    }

    else{
      digitalWrite(curr_pin, HIGH);
      delay(500);
    }
  }
  
  
}
