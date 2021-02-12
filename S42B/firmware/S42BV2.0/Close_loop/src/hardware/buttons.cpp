#include "buttons.h"
#include "pinMapping.h"
#include "Arduino.h"

// Initialize the button pins as inputs
void initButtons() {

  // Back pin
  pinMode(BACK_BUTTON_PIN, INPUT);

  // Confirm pin
  pinMode(SELECT_BUTTON_PIN, INPUT);

  // Select pin
  pinMode(CONFIRM_BUTTON_PIN, INPUT);

}

// Scan each of the keys
void checkButtons(void) {

  // Check the select key
  if(checkButtonState(SELECT_BUTTON_PIN)){

    /*

    // Check if we're in the menu
    if(Menu_Num == 0){
      
      // Make sure that the key click wasn't processed yet
      if(!KEY_Select_flag){

        // Set the update flags
        KEY_Select_flag = true;
        menuUpdateFlag = true;
        
        if(!isCalibrated()){
            Menu_Num_item++;
            if(Menu_Num_item>1)
                Menu_Num_item=0;
        }
        else if(Second_Menu==1){
                Menu_Num_item++;
                if(Menu_Num_item > MENU_NUM){
                    Menu_Num_item =2;
            }
        }
        else if(Second_Menu==2){
                Menu_Num2_item++;
                if(Menu_Num2_item>33)
                    Menu_Num2_item=0;
        }
        else if(Second_Menu==3){
                Menu_Num3_item++;
                if(Menu_Num3_item>4)
                    Menu_Num3_item=0;
        }
        else if(Second_Menu==4){
                Menu_Num4_item++;
                if(Menu_Num4_item>1)
                    Menu_Num4_item=0;
        }
        else if(Second_Menu==5){
                Menu_Num5_item++;
                if(Menu_Num5_item>1)
                    Menu_Num5_item=0;
        }
      }
    }
    */
  }
  // Check the back key
  else if(checkButtonState(BACK_BUTTON_PIN)){

    /*
    // Make sure that the back key hasn't been dealt with yet
    if(!KEY_Back_flag){

      // Update the state flags
      KEY_Back_flag = true;
      menuUpdateFlag = true;

      // Clear the OLED for writing
      OLED_Clear();

      // ! Check
      if(Enter_exit_flag == 1){
          Enter_exit_flag=0;
          Menu_Num=0;
          Menu_Num_item=2;
          Second_Menu=1;
      }else {
          Menu_Num++;
          if(Menu_Num >1 ){
              Menu_Num=0;
          }
          dataUpdateFlag = true;
      }
    }
    */
  }

  // Check the confirm key
  else if(checkButtonState(CONFIRM_BUTTON_PIN)){

    /*

    // Make sure that we're not already dealing with a key
    if(!KEY_Confirm_flag){
      PHASE_MULTIPLIER++;
      dataUpdateFlag = true;
      delayMs(100);

      // Set the flags to the correct state
      KEY_Confirm_flag = true;

      // Check the current menu
      switch(Menu_Num){
        case 0:     
          switch(Menu_Num_item){
              case 0:
                SetModeCheck();
                break;
              case 1: 
                Enter_exit_flag = 1;
                Menu_Num = 1;
                menuUpdateFlag = true;
                OLED_Clear();
              break ;
              case 2: 
                      TIM_Cmd(TIM2,DISABLE);
                      enmode=0;
                      NVIC_DisableIRQ(EXTI1_IRQn);
                      Second_Calibrate_flag=1;
                      SetModeCheck();
                      NVIC_EnableIRQ(EXTI1_IRQn);
                      TIM_Cmd(TIM2,ENABLE);
                      Second_Menu=1;
                  break ;
              case 3:
                      OLED_Clear();   //
                      menuUpdateFlag = true;   //
                      enter_num++;
                      if(enter_num==1)
                          Second_Menu=2;        //
                      if(enter_num==2){
                          enter_num=0;
                          Second_Menu=1;
                          //
                          //
                          Currents= Currents_Set;//
                          flashStoreFlag = true;
                          table1[1]=Currents;
                          table1[2]=Menu_Num2_item;
                      }
                  break ;
              case 4: OLED_Clear();   //
                      menuUpdateFlag = true;   //
                      enter_num++;
                      if(enter_num==1)
                          Second_Menu=3;        //
                      if(enter_num==2){
                          enter_num=0;
                          Second_Menu=1;
                          enmode =0;
                          PID_Cal_value_init();

                          stepangle = Microstep_Set;
                          
                          flashStoreFlag = true;
                          table1[3]=stepangle;
                          table1[4]=Menu_Num3_item;
                      }
                  break ;
              case 5: OLED_Clear();   //
                      menuUpdateFlag = true;   //
                      enter_num++;
                      if(enter_num==1)
                          Second_Menu=4;        //
                      if(enter_num==2){
                          enter_num=0;
                          Second_Menu=1;
                          enmode =0;
                          PID_Cal_value_init();
                          
                          if(Dir_Enable == 0xaa ){
                              //enmode =1;
                            motorEnabled = false;
                          }else if(Dir_Enable == 0x55  ){
                              motorEnabled = true;
                              //enmode =0;
                          }
                          if(Dir_Enable == 0x55 || Dir_Enable == 0xAA){
                              Dir_Enable =0;
                              flashStoreFlag = true;//
                              table1[5] = motorEnabled;
                              table1[6]=Menu_Num4_item;
                              
                          }
                      }
                  break ;
              case 6: OLED_Clear();   //
                      menuUpdateFlag = true;   //
                      enter_num++;
                      if(enter_num==1)
                          Second_Menu=5;        //
                      if(enter_num==2){
                          enter_num=0;
                          Second_Menu=1;
                          
                          //
                          //Dir_Enable  ;
                          if(Dir_Enable ==0x11){
                              positiveDirection = true;
                          }else if(Dir_Enable == 0x22){
                              positiveDirection = false;
                          }
                          Dir_Enable=0;
                          flashStoreFlag = true;
                          table1[7] = positiveDirection;
                          table1[8] = Menu_Num5_item;
                      }
                  break ;
              case 7:Enter_exit_flag=1;    //
                      Menu_Num=1;           //  
                      menuUpdateFlag = true;   //
                      OLED_Clear();         //
                  break;
              default:break;
            }
        break;
        }  
      }*/
    }
    else {
        
    }
}

// Check to see if a button is clicked
bool checkButtonState(uint32_t buttonPin) {

  // Check to see if the select button is clicked (pins are pulled high by default)
  if(digitalRead(buttonPin) == LOW){

    // Wait to make sure it wasn't a misread
    delay(10);

    // Check again
    if(digitalRead(buttonPin) == LOW){

      // The button is still clicked, it's valid
      return true;

    }
    else {

      // The button is no longer clicked, probably just a misread
      return false;
    }

  }
  else {

    // Button was never clicked
    return false;
  }
}