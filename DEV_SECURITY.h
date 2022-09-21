struct DEV_SECURITY : Service::SecuritySystem {
  
  SpanCharacteristic *currentState;
  SpanCharacteristic *targetState;

  DEV_SECURITY() : Service::SecuritySystem() {
    currentState=new Characteristic::SecuritySystemCurrentState(3);
    targetState=(new Characteristic::SecuritySystemTargetState(3))->setValidValues(3,2,1,3);
    digitalWrite(26, LOW);
    digitalWrite(25, LOW);
  }

  boolean update() {
    switch (targetState->getNewVal()) {
      case 1:
        currentState->setVal(1);
        digitalWrite(26, LOW);
        digitalWrite(25, HIGH);
        LOG1("Security System switched to Away mode\n");
        break;
      case 2:
        currentState->setVal(2);
        digitalWrite(26, LOW);
        digitalWrite(25, HIGH);
        LOG1("Security System switched to Night mode\n");
        break;
      case 3:
        currentState->setVal(3);
        digitalWrite(26, LOW);
        digitalWrite(25, LOW);
        LOG1("Security System disabled\n");
        break;
    }

    return(true);
  }

  void triggerAlarm() {
    currentState->setVal(4);
    digitalWrite(26, HIGH);
    LOG1("Alarm Triggered!!!\n");
    
  }

  boolean isArmed() {
    if(currentState->getVal()==3) {
      return(false);
    } else {
      return(true);
    }
  }
  
};
