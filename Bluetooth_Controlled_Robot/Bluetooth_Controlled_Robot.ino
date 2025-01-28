#define in1 5
#define in2 6
#define in3 9
#define in4 10
#define e1 3
#define e2 11
char t;

void setup() {
  pinMode(in1, OUTPUT);  //left motors  forward
  pinMode(in2, OUTPUT);  //left motors reverse
  pinMode(in3, OUTPUT);  //right  motors forward
  pinMode(in4, OUTPUT);  //right motors reverse
  pinMode(e1, OUTPUT);
  pinMode(e2, OUTPUT);
  Serial.begin(9600);

}

void loop() {
  if (Serial.available()) {
    t = Serial.read();
    Serial.println(t);
  }
    if (t == 'F') {
     analogWrite(e1,200);
     analogWrite(e2,200);
      digitalWrite(in1, HIGH);
      digitalWrite(in3, HIGH);

    }

    else if (t == 'B') {
     analogWrite(e1,200);
     analogWrite(e2,200);//move reverse (all  motors rotate in reverse direction)
      digitalWrite(in2, HIGH);
      digitalWrite(in4, HIGH);
 
    }

    else if (t == 'L') {
      analogWrite(e1,150);
     analogWrite(e2,150);//turn right (left side motors rotate in forward direction,  right side motors doesn't rotate)
      digitalWrite(in3, HIGH);
      digitalWrite(in2, HIGH);
 
    }

    else  if (t == 'R') {  
           analogWrite(e1,150);
     analogWrite(e2,150);//turn left (right side motors rotate in forward direction, left  side motors doesn't rotate)
      digitalWrite(in1, HIGH);
      digitalWrite(in4, HIGH);
     
    }

    else if (t ==  'G') {
     analogWrite(e1,70);
     analogWrite(e2,200);//turn led on or off)
           digitalWrite(in1, HIGH);
      digitalWrite(in3, HIGH);
     
    }
    else if (t ==  'I') {
           analogWrite(e1,200);
     analogWrite(e2,70);//turn led on or off)
      digitalWrite(in1, HIGH);
            digitalWrite(in3, HIGH);
         
    }
    else if (t ==  'H') {  
                 analogWrite(e1,50);
     analogWrite(e2,100);
            digitalWrite(in2, HIGH);//turn led on or off)
      digitalWrite(in4, HIGH);
   
    }
    else if (t ==  'J') {
                       analogWrite(e1,100);
     analogWrite(e2,50);//turn led on or off)
      digitalWrite(in2, HIGH);
           digitalWrite(in4, HIGH);
       
    }
    else if (t == 'S') {    //STOP (all motors stop)
      digitalWrite(in1, LOW);
      digitalWrite(in2, LOW);
      digitalWrite(in3, LOW);
      digitalWrite(in4, LOW);
     
    }
    delay(1);


  }
