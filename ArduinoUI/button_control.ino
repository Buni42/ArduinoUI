// buttons

int button_left = 2;
int button_down = 3;
int button_right = 4;
int button_forward = 5;
int button_ok = 6;

String IntBytes;

void setup() {
  Serial.begin(9600);
  pinMode(button_left, INPUT);
  pinMode(button_down, INPUT);
  pinMode(button_right, INPUT);
  pinMode(button_forward, INPUT);
  pinMode(button_ok, INPUT);
}

void loop() {
  // to read from py
  if (Serial.available()>0){
    IntBytes = Serial.readStringUntil("\n");
  }
  int button_left_value = digitalRead(button_left);
  int button_down_value = digitalRead(button_down);
  int button_right_value = digitalRead(button_right);
  int button_forward_value = digitalRead(button_forward);
  int button_ok_value = digitalRead(button_ok);
  
  if (button_left_value != 0){
    Serial.write("button_left_value");
    }
  if (button_down_value != 0){
    Serial.write("button_down_value");
    }
  if (button_right_value != 0){
    Serial.write("button_right_value");
    }
  if (button_forward_value != 0){
    Serial.write("button_forward_value");
    delay(100);
    }
  if (button_ok_value != 0){
    Serial.write("button_ok_value");
    }
}
