struct DEV_TRIGGER_SW : Service::Switch {

  SpanCharacteristic *state;
  DEV_SECURITY *security;

  DEV_TRIGGER_SW(DEV_SECURITY *sec) : Service::Switch() {
    new Characteristic::Name("Trigger");
    security=sec;
    state=new Characteristic::On(0);
  }

  boolean update() {
    if(state->getNewVal()==1 && security->isArmed()) {
      security->triggerAlarm();
      state->setVal(0);
    } else {
      state->setVal(0);
      LOG1("Alarm is not armed\n");
    }
    
    return(true);
  }
};
