//Function to control each pin of stepper motor
void Step_A(){
  digitalWrite(pin1, HIGH);//turn on coil 1 
  digitalWrite(pin2, HIGH); 
  digitalWrite(pin3, LOW); 
  digitalWrite(pin4, LOW); 
}
void Step_B(){
  digitalWrite(pin1, LOW); 
  digitalWrite(pin2, HIGH);//turn on coil 2
  digitalWrite(pin3, HIGH); 
  digitalWrite(pin4, LOW); 
}
void Step_C(){
  digitalWrite(pin1, LOW); 
  digitalWrite(pin2, LOW); 
  digitalWrite(pin3, HIGH); //turn on coil 3
  digitalWrite(pin4, HIGH); 
}
void Step_D(){
  digitalWrite(pin1, HIGH); 
  digitalWrite(pin2, LOW); 
  digitalWrite(pin3, LOW); 
  digitalWrite(pin4, HIGH); //turn on coil 4
}
void step_OFF(){
  digitalWrite(pin1, LOW); //power all coils down
  digitalWrite(pin2, LOW); 
  digitalWrite(pin3, LOW); 
  digitalWrite(pin4, LOW); 
}

//these functions run the above configurations in forward and reverse order
//the direction of a stepper motor depends on the order in which the coils are turned on.
void forward(){//one tooth forward
  Step_A();
  delay(delaytime);
  Step_B();
  delay(delaytime);
  Step_C();
  delay(delaytime);
  Step_D();
  delay(delaytime);
}
void backward(){//one tooth backward
  Step_C();
  delay(delaytime);
  Step_B();
  delay(delaytime);
  Step_A();
  delay(delaytime);
  Step_D();
  delay(delaytime);
}
