#pragma once
#include "Module.h"

#include "LittleFS.h"
// #include <FS.h>

//https://randomnerdtutorials.com/esp32-vs-code-platformio-spiffs/
  // upload under the data folder:
    // Click the PIO icon at the left side bar. The project tasks should open.
    // Select esp32dev (it may be slightly different depending on the board you’re using).
    // Expand the Platform menu.
    // Select Build Filesystem Image.
    // Finally, click Upload Filesystem Image.
//https://www.tutorialspoint.com/esp32_for_iot/esp32_for_iot_spiffs_storage.htm

class SysModFiles:public Module {

public:

  SysModFiles() :Module("Files") {
    print->print("%s %s\n", __PRETTY_FUNCTION__, name);

    if (!LittleFS.begin(true)) { //true: formatOnFail
      print->print(" An Error has occurred while mounting File system");
      print->print(" fail\n");
      success = false;
    }

    print->print("%s %s %s\n", __PRETTY_FUNCTION__, name, success?"success":"failed");
  };

  //setup filesystem
  void setup() {
    Module::setup();
  }

  void loop(){
    // Module::loop();
  }

  bool remove(const char * path) {
    return LittleFS.remove(path);
  }

  size_t usedBytes() {
    return LittleFS.usedBytes();
  }

  size_t totalBytes() {
    return LittleFS.totalBytes();
  }

  File open(const char * path, const char * mode, const bool create = false) {
    return LittleFS.open(path, mode, create);
  }

  // https://techtutorialsx.com/2019/02/24/esp32-arduino-listing-files-in-a-spiffs-file-system-specific-path/
  void dirToJson(JsonArray array) {
    File root = LittleFS.open("/");

    File file = root.openNextFile();
  
    while(file){

      JsonArray row = array.createNestedArray();
      row.add((char *)file.name());  //create a copy!
      row.add(file.size());
  
      Serial.printf("FILE: %s %d\n", file.name(), file.size());

      file = root.openNextFile();
    }
  }

};

static SysModFiles *files;