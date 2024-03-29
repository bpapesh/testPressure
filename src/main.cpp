/*
 Copyright (c) 2014-present PlatformIO <contact@platformio.org>

 Licensed under the Apache License, Version 2.0 (the "License");
 you may not use this file except in compliance with the License.
 You may obtain a copy of the License at

    http://www.apache.org/licenses/LICENSE-2.0

 Unless required by applicable law or agreed to in writing, software
 distributed under the License is distributed on an "AS IS" BASIS,
 WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 See the License for the specific language governing permissions and
 limitations under the License.
**/

#include <Arduino.h>
#include <WiFi.h>
#include "SecureOTA.h"

#include "esp_timer.h"
#include "soc/soc.h" //disable brownout problems
#include "soc/rtc_cntl_reg.h"  //disable brownout problems
// #include "dl_lib.h"
#include "esp_http_server.h"


#include "driver/rtc_io.h"



const uint16_t OTA_CHECK_INTERVAL = 3000; // ms
uint32_t _lastOTACheck = 0;



void setup()
{
  Serial.begin(115200);
  Serial.setDebugOutput(false);
  delay(10);

  WRITE_PERI_REG(RTC_CNTL_BROWN_OUT_REG, 0); //disable brownout detector
 


  Serial.print("Device version: v.");
  Serial.println(VERSION);
  Serial.print("Connecting to " + String(WIFI_SSID));

  WiFi.begin(WIFI_SSID, WIFI_PASS);
  while (WiFi.status() != WL_CONNECTED)
  {
    Serial.print(".");
    delay(500);
  }

  Serial.println(" connected!");
  _lastOTACheck = millis();

  // your setup code goes here

}


void loop()
{
  if ((millis() - OTA_CHECK_INTERVAL) > _lastOTACheck) {
    _lastOTACheck = millis();
    checkFirmwareUpdates();
  }

  // your loop code goes here
}
