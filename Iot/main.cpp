#include <WiFi.h>
#include <WiFiUdp.h>
#include <ArduinoOTA.h>

//    Can be client or even host   //
#ifndef STASSID
#define STASSID "Shekar"  // Replace with your network credentials
#define STAPSK  "shekar12"
#endif

const char* ssid = STASSID;
const char* password = STAPSK;

#define PIN_LED 2
int A = 31,B;
hw_timer_t *timer = NULL; 
volatile uint8_t led_state = 0;




void IRAM_ATTR timer_isr(){
 led_state = !led_state;
 digitalWrite(PIN_LED,led_state);
 }

void OTAsetup() {
  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);
  while (WiFi.waitForConnectResult() != WL_CONNECTED) {
    delay(5000);
    ESP.restart();
  }
  ArduinoOTA.begin();
}

void OTAloop() {
  ArduinoOTA.handle();
}

//-------------------------------------------------------//

void setup(){
  OTAsetup();

  Serial.begin(115200);
  
  pinMode(PIN_LED,OUTPUT);
  pinMode(2,OUTPUT);
  timer = timerBegin(0,40, true);
  timerAttachInterrupt(timer, &timer_isr,true);
  timerAlarmWrite(timer,1000000 ,true);
  timerAlarmEnable(timer);
  digitalWrite(2,digitalRead(2)^1);
  
}

void loop() {
  OTAloop();
 
}

