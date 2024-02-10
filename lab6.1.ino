#define Speaker 27
#define Button 22
hw_timer_t *My_timer = NULL;

int DOO = 1047;
int REA = 1175;
int MEE = 1319;
int FAA = 1397;
int SON = 1568;
int NOTE = 1000000 / MEE; // Calculate the initial alarm value for frequency MEE
int Open = 1;
int t = 5;
int sp = 50;

void IRAM_ATTR onTimer(){
  if (Open == 1) {
    digitalWrite(Speaker, !digitalRead(Speaker));
  } else {
    digitalWrite(Speaker, LOW);
  }
  timerAlarmWrite(My_timer, NOTE, true); // Update the alarm value
}

void IRAM_ATTR IO_INT_ISR()
{
  t--;
  if(t == 0){
    t = 5;
  }
  Serial.println(t);
}

void setup() {
  pinMode(Speaker, OUTPUT);
  pinMode(Button, INPUT);
  digitalWrite(Speaker, LOW);
  My_timer = timerBegin(0, 80, true);
  timerAttachInterrupt(My_timer, &onTimer, true);
  timerAlarmWrite(My_timer, NOTE, true);
  timerAlarmEnable(My_timer);
  attachInterrupt(Button, IO_INT_ISR, RISING);
  Serial.begin(9600);
}

void loop() {
  Blacknote(t);
  Blacknote(t);
  whlienote(t);

  Blacknote(t);
  Blacknote(t);
  whlienote(t);

  Blacknote(t);
  NOTE = 1000000 / SON;
  Blacknote(t);
  NOTE = 1000000 / DOO;
  Blacknote(t);
    NOTE = 1000000 / REA;
  Blacknote(t);
    NOTE = 1000000 / MEE;
  Onote(t);

  NOTE = 1000000 / FAA;
  Blacknote(t);
  Blacknote(t);
  Blacknote(t);
  Blacknote(t);

  Blacknote(t);
  NOTE = 1000000 / MEE;
  Blacknote(t);
  Blacknote(t);
  kabetnote(t);
  kabetnote(t);

  NOTE = 1000000 / SON;
  Blacknote(t);
  Blacknote(t);
  NOTE = 1000000 / FAA;
  Blacknote(t);
  NOTE = 1000000 / REA;
  Blacknote(t);
  NOTE = 1000000 / DOO;
  Onote(t);
  // Repeat the melody loop as needed
  
}

void Blacknote(int t){
  Open = 1;
  delay(t*sp);
  Open = 0;
  delay(t*sp);
}

void whlienote(int t){
  Open = 1;
  delay(t*2*sp);
  Open = 0;
  delay(t*2*sp);
}

void Onote(int t){
  Open = 1;
  delay(t*4*sp);
  Open = 0;
  delay(t*4*sp);
}

void kabetnote(int t){
  Open = 1;
  delay((t*sp)/2);
  Open = 0;
  delay((t*sp)/2);
}
