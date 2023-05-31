#include "Module.h"

//try this !!!: curl -X POST "http://192.168.121.196/json" -d '{"Pin2":false}' -H "Content-Type: application/json"

class AppModPinManager:public Module {

public:

  AppModPinManager() :Module("Pin Manager") {}; //constructor

  void setup() {
    Module::setup();
    print->print("%s Setup:", name);

    pinMode(2, OUTPUT);
    pinMode(4, OUTPUT);
    pinMode(33, OUTPUT);

    ui->defGroup(name);
    ui->defCheckBox("Pin2", true, updateGPIO);
    ui->defCheckBox("Pin4", false);
    ui->defCheckBox("Pin33", true);

    ui->finishUI();
  
    print->print(" %s\n", success?"success":"failed");
  }

  void loop(){
    // Module::loop();
  }

  static void updateGPIO(const char *prompt, JsonVariant value) {
    if (value.is<bool>()) {
      bool pin = value.as<bool>();

      print->print("updateGPIO %s:=%d\n", prompt, pin);

      if (strcmp(prompt, "Pin2") == 0) digitalWrite(2, pin?HIGH:LOW);
      if (strcmp(prompt, "Pin4") == 0) digitalWrite(4, pin?HIGH:LOW);
      if (strcmp(prompt, "Pin33") == 0) digitalWrite(33, pin?HIGH:LOW);
    }
  }

};

static AppModPinManager *pin;