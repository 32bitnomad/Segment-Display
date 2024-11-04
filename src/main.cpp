#include <Arduino.h>
#include "seg_c.h"

void setup() {
  Serial.begin(153600);
}

  uint32_t now = millis();

  int s_nums[4] = {10,10,0,10};
  int ss_nums[4] = {8,8,8,8};
  int t_nums[4] = {0,0};
  uint8_t shape[6] = {0,0,0,0,0,0};
  int bat_level = 0; 
  int cpu_level = 0; 
  int ram_level = 0; 
  int is_plugged = 0; 
  String message; 

void loop() {
  if (Serial.available()) 
  {
      message = Serial.readStringUntil('\n'); 

      switch (message.charAt(0))
      {
      case 'C':
        cpu_level = message.substring(2).toInt();
        break;
      case 'R':
        ram_level = message.substring(2).toInt();
        break;
      case 'P':
        is_plugged = message.substring(2).toInt();
        break;  
      case 'B':
        bat_level = message.substring(2).toInt();
        break;  
      default:
        break;
      }
  }

  if(is_plugged == 1)
  {
    shape[3] = 1; 
    shape[2] = 0; 
  }
  else
  {
    shape[3] = 0; 
    shape[2] = 1; 
  }

  if(millis() < now + 5000)
  {
    clear_screen();
    shape[0] = 0; 
    shape[1] = 0; 
    shape[2] = 0; 
    shape[3] = 0; 
    shape[4] = 1; 
    shape[5] = 1; 
    update_right_numbers(ram_level);
    update_left_numbers(cpu_level);
    update_shapes(shape);
  }
  else if(millis() > now + 5000 && millis() < now + 10000)
  {
    clear_screen();
    shape[4] = 0;
    update_right_numbers(bat_level);
    if(bat_level >= 70)
    {
      shape[1] = 1;
      shape[0] = 0; 
    }else if (bat_level<70 && bat_level>30){
      shape[1] = 1;
      shape[0] = 1; 
    }else{
      shape[1] = 0;
      shape[0] = 1; 
    }

    if(is_plugged == 1)
    {
      shape[3] = 1; 
      shape[2] = 0; 
    }
    else
    {
      shape[3] = 0; 
      shape[2] = 1; 
    }
    update_shapes(shape);
  }
  else if(millis() > now + 10000)
  {
    now = millis();
  }
  keep_alive();
}