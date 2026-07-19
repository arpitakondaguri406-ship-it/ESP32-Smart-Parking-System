#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <ESP32Servo.h>

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);

Servo gateServo;

// ------------ Pins ------------
#define SLOT1 34
#define SLOT2 35
#define SLOT3 32
#define SLOT4 33

#define GREEN_LED 18
#define RED_LED   19
#define BUZZER    23
#define SERVO_PIN 5

const int threshold = 2000;

// ------------ Variables ------------

bool slotStatus[4];

int occupied = 0;
int available = 4;
int percentage = 0;

bool gateOpen = false;

int vehicleEntered = 0;
int vehicleExited = 0;

int previousOccupied = 0;

unsigned long previousScreen = 0;
const int screenDelay = 3000;

int screen = 0;

// Function Prototypes

void startupAnimation();
void loadingAnimation();
void readSlots();
void controlGate();
void controlLED();
void controlBuzzer();
void serialOutput();

void showDashboard();
void showSlotScreen();
void showStatistics();
void showSystemStatus();
void showParkingFull();

void drawProgressBar(int value);

// ---------------- SETUP ----------------

void setup() {

Serial.begin(115200);

pinMode(GREEN_LED,OUTPUT);
pinMode(RED_LED,OUTPUT);
pinMode(BUZZER,OUTPUT);

pinMode(SLOT1,INPUT);
pinMode(SLOT2,INPUT);
pinMode(SLOT3,INPUT);
pinMode(SLOT4,INPUT);

gateServo.attach(SERVO_PIN);
gateServo.write(0);

Wire.begin(21,22);

display.begin(SSD1306_SWITCHCAPVCC,0x3C);

startupAnimation();

loadingAnimation();

display.clearDisplay();

display.display();

}
// ---------------- READ PARKING SLOTS ----------------

void readSlots() {

  slotStatus[0] = analogRead(SLOT1) > threshold;
  slotStatus[1] = analogRead(SLOT2) > threshold;
  slotStatus[2] = analogRead(SLOT3) > threshold;
  slotStatus[3] = analogRead(SLOT4) > threshold;

  occupied = 0;

  for(int i=0;i<4;i++){
    if(slotStatus[i])
      occupied++;
  }

  available = 4 - occupied;

  percentage = occupied * 25;

  // Vehicle Counter

  if(occupied > previousOccupied)
      vehicleEntered++;

  if(occupied < previousOccupied)
      vehicleExited++;

  previousOccupied = occupied;
}

// ---------------- GATE CONTROL ----------------

void controlGate(){

  if(available > 0){

    gateOpen = true;

    for(int i=0;i<=90;i+=3){
      gateServo.write(i);
      delay(10);
    }

    delay(1500);

    for(int i=90;i>=0;i-=3){
      gateServo.write(i);
      delay(10);
    }

  }
  else{

    gateOpen = false;

    gateServo.write(0);

  }

}

// ---------------- LED CONTROL ----------------

void controlLED(){

  if(gateOpen){

    digitalWrite(GREEN_LED,HIGH);
    digitalWrite(RED_LED,LOW);

  }
  else{

    digitalWrite(GREEN_LED,LOW);
    digitalWrite(RED_LED,HIGH);

  }

}

// ---------------- BUZZER ----------------

void controlBuzzer(){

  if(available==0){

    tone(BUZZER,1000);

    delay(300);

    noTone(BUZZER);

  }

}

// ---------------- SERIAL MONITOR ----------------

void serialOutput(){

Serial.println("==================================");

Serial.println(" SMART PARKING SYSTEM ");

Serial.println("==================================");

Serial.print("Available : ");
Serial.println(available);

Serial.print("Occupied : ");
Serial.println(occupied);

Serial.print("Usage : ");
Serial.print(percentage);
Serial.println("%");

Serial.print("Vehicle Entered : ");
Serial.println(vehicleEntered);

Serial.print("Vehicle Exited : ");
Serial.println(vehicleExited);

Serial.print("Gate : ");

if(gateOpen)
Serial.println("OPEN");

else
Serial.println("CLOSED");

Serial.println("==================================");
}
// ---------------- STARTUP ANIMATION ----------------

void startupAnimation() {

  display.clearDisplay();

  display.setTextSize(2);
  display.setCursor(8,5);
  display.println("SMART");

  display.setCursor(15,28);
  display.println("PARKING");

  display.display();

  delay(2000);
}

// ---------------- LOADING SCREEN ----------------

void loadingAnimation() {

  display.clearDisplay();

  display.setTextSize(1);
  display.setCursor(20,5);
  display.println("Initializing");

  for(int i=0;i<=100;i+=10){

    display.drawRect(10,30,108,12,WHITE);

    display.fillRect(12,32,i,8,WHITE);

    display.display();

    delay(150);

  }

}

// ---------------- PROGRESS BAR ----------------

void drawProgressBar(int value){

  int width = map(value,0,100,0,100);

  display.drawRect(14,48,100,10,WHITE);

  display.fillRect(16,50,width-2,6,WHITE);

}

// ---------------- DASHBOARD ----------------

void showDashboard(){

  display.clearDisplay();

  display.setTextSize(1);

  display.setCursor(18,0);
  display.println("SMART PARKING");

  display.drawLine(0,10,128,10,WHITE);

  display.setCursor(0,18);
  display.print("Free : ");
  display.print(available);

  display.setCursor(70,18);
  display.print("Used : ");
  display.print(occupied);

  display.setCursor(0,34);
  display.print("Usage : ");
  display.print(percentage);
  display.println("%");

  drawProgressBar(percentage);

  display.display();

}

// ---------------- SLOT SCREEN ----------------

void showSlotScreen(){

display.clearDisplay();

display.setTextSize(1);

display.setCursor(20,0);
display.println("SLOT STATUS");

display.drawLine(0,10,128,10,WHITE);

display.setCursor(0,18);
display.print("S1 : ");
display.println(slotStatus[0]?"FULL":"FREE");

display.setCursor(0,30);
display.print("S2 : ");
display.println(slotStatus[1]?"FULL":"FREE");

display.setCursor(0,42);
display.print("S3 : ");
display.println(slotStatus[2]?"FULL":"FREE");

display.setCursor(0,54);
display.print("S4 : ");
display.println(slotStatus[3]?"FULL":"FREE");

display.display();

}

// ---------------- STATISTICS ----------------

void showStatistics(){

display.clearDisplay();

display.setTextSize(1);

display.setCursor(20,0);
display.println("STATISTICS");

display.drawLine(0,10,128,10,WHITE);

display.setCursor(0,20);
display.print("Entered : ");
display.println(vehicleEntered);

display.setCursor(0,34);
display.print("Exited : ");
display.println(vehicleExited);

display.setCursor(0,48);
display.print("Usage : ");
display.print(percentage);
display.println("%");

display.display();

}
//---------------- SYSTEM STATUS ----------------

void showSystemStatus() {

  display.clearDisplay();

  display.setTextSize(1);

  display.setCursor(15,0);
  display.println("SYSTEM STATUS");

  display.drawLine(0,10,128,10,WHITE);

  display.setCursor(0,20);
  display.println("OLED  : OK");

  display.setCursor(0,32);
  display.println("Servo : OK");

  display.setCursor(0,44);
  display.println("ESP32 : RUNNING");

  display.setCursor(0,56);
  display.println("READY");

  display.display();

}

//---------------- PARKING FULL SCREEN ----------------

void showParkingFull() {

  display.clearDisplay();

  display.setTextSize(2);

  display.setCursor(12,8);
  display.println("PARK");

  display.setCursor(15,28);
  display.println("FULL");

  display.setTextSize(1);

  display.setCursor(10,54);
  display.println("Gate Closed");

  display.display();

}

//---------------- MAIN LOOP ----------------

void loop() {

  readSlots();

  controlGate();

  controlLED();

  controlBuzzer();

  serialOutput();

  // Change OLED screen every 3 seconds
  if (millis() - previousScreen >= screenDelay) {

    previousScreen = millis();

    screen++;

    if (screen > 3)
      screen = 0;

  }

  if (available == 0) {

    showParkingFull();

  } else {

    switch (screen) {

      case 0:
        showDashboard();
        break;

      case 1:
        showSlotScreen();
        break;

      case 2:
        showStatistics();
        break;

      case 3:
        showSystemStatus();
        break;

    }

  }

  delay(100);

}
