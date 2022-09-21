#include "HomeSpan.h"
#include "DEV_SECURITY.h"
#include "DEV_TRIGGER_SW.h"

void setup() {
  Serial.begin(115200);

  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(26, OUTPUT);
  pinMode(25, OUTPUT);
  
  homeSpan.setStatusPin(LED_BUILTIN);

  homeSpan.begin(Category::SecuritySystems,"Security System");
  
  new SpanAccessory(); 
  
    new Service::AccessoryInformation(); 
      new Characteristic::Identify();
      new Characteristic::Manufacturer("Axel-1");
      new Characteristic::SerialNumber("0123456789");
      new Characteristic::Model("Security-System-001");
      new Characteristic::FirmwareRevision("1.0");

    new DEV_TRIGGER_SW(new DEV_SECURITY());
}

void loop() {
  homeSpan.poll();
}
