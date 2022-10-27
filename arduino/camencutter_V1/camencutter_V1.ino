//Define pin connections

#define platter_dirPin 2
#define platter_stepPin 3
#define column_dirPin 4
#define column_stepPin 5
#define column_in 6
#define platter_in 7
#define button_in 13

//Define timings betwen steps
#define platter_time 10000
#define column_time 1000

//Define travel steps
#define column_travel 10050
#define platter_travel 66

//Define ints
int platterState =0;
int columnState =0;
int buttonState =1;

void setup() {

  //Declare stepper outputs
  pinMode(platter_dirPin, OUTPUT);
  pinMode(platter_stepPin, OUTPUT);
  pinMode(column_dirPin, OUTPUT);
  pinMode(column_stepPin, OUTPUT);

  //Define switch inputs
  pinMode(platter_in, INPUT);
  pinMode(column_in, INPUT);
  pinMode(button_in, INPUT);
}
void loop() 
{
  // On start up home the stepper motors
  home();
  buttonState = digitalRead(button_in);

  // While the column stane is high
  if (buttonState == LOW){
    //

  
    home();
    delay(1000);
  
    // Drop blade
    step_column(LOW, column_travel);
    //Raise blade
    step_column(HIGH, column_travel);
    delay(500);
  
    //Rotate 120 degrees
    step_platter(HIGH, platter_travel);
    delay(500);
  
    //Drop blade
    step_column(LOW, column_travel);
    //Raise blade
    step_column(HIGH, column_travel);
    
    //Rotate platter 120 degrees
    step_platter(HIGH, platter_travel);
    delay(500);
  
    //Drop blade
    step_column(LOW, column_travel);
    //Raise blade
    step_column(HIGH, column_travel);
    
    // Return to home
    home();
   
  }
}

int home(){

  //home the column
  columnState = digitalRead(column_in);

  // While the column state is high
  while (columnState == HIGH){
    //
    digitalWrite(column_dirPin, HIGH);
    digitalWrite(column_stepPin, HIGH);
    delayMicroseconds(column_time);
    digitalWrite(column_stepPin, LOW);
    delayMicroseconds(column_time);
    columnState = digitalRead(column_in);
  }
  
  //home the platter
  platterState = digitalRead(platter_in);
  
  while (platterState == HIGH){
    digitalWrite(platter_dirPin, LOW);
    digitalWrite(platter_stepPin, HIGH);
    delayMicroseconds(platter_time);
    digitalWrite(platter_stepPin, LOW);
    delayMicroseconds(platter_time);
    platterState = digitalRead(platter_in);
  }
}

int step_platter(int directions, int steps){
  for (int i = 0; i <= steps ; i++) {
    digitalWrite(platter_dirPin, directions);
    digitalWrite(platter_stepPin, HIGH);
    delayMicroseconds(platter_time);
    digitalWrite(platter_stepPin, LOW);
    delayMicroseconds(platter_time);
  }
}

int step_column(int directions, int steps){
  for (int i = 0; i <= steps ; i++) {
    digitalWrite(column_dirPin, directions);
    digitalWrite(column_stepPin, HIGH);
    delayMicroseconds(column_time);
    digitalWrite(column_stepPin, LOW);
    delayMicroseconds(column_time);
  }
}
