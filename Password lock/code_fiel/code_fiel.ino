/* @file HelloKeypad.pde
|| @version 1.0
|| @author Alexander Brevig
|| @contact alexanderbrevig@gmail.com
||
|| @description
|| | Demonstrates the simplest use of the matrix Keypad library.
|| #
*/
#include <Keypad.h>
#include <LiquidCrystal.h>
const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

const byte ROWS = 4; //four rows
const byte COLS = 3; //three columns
char keys[ROWS][COLS] = {
  {'1','2','3'},
  {'4','5','6'},
  {'7','8','9'},
  {'*','0','#'}
};
byte rowPins[ROWS] = {A3, A4, A5, 6}; //connect to the row pinouts of the keypad
byte colPins[COLS] = {A0, A1, A2}; //connect to the column pinouts of the keypad
int i=0;

char pass[]="1234569";
int count=0;
int num=(sizeof(pass)-1);
char p[sizeof(pass)-1];

Keypad keypad = Keypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS );

void setup(){
  Serial.begin(9600);
  lcd.begin(16, 2);
  // Print a message to the LCD.
  lcd.print("enter the pass");
}
  
void loop(){
  
  
  
  char key = keypad.getKey();
  
  if (key>'0' && key != '#'){
    lcd.setCursor(i, 1);
    lcd.print("*");
    p[i]=key;
    i++;
    }
    else if(key=='#'){ 
      if (i==num){
              for(int j=0;j<num;j++){
                if (p[j]==pass[j]){
                  count++;
                  }
              }
              if (count==num){
              lcd.clear();
              lcd.setCursor(0,0);
              lcd.print("correct  ");
              delay(2000);
              }
          
              else {
                lcd.clear();
                lcd.setCursor(0,0);
                lcd.print("not correct");
                delay(500);
                lcd.clear();
                lcd.print("enter the pass");
                lcd.setCursor(0,1);
                i=0;}
                
                 
          
        
        }
        else{
          lcd.clear();
          lcd.setCursor(0,0);
          lcd.print("not correct   ");
          delay(500);
          lcd.setCursor(0,0);
          lcd.print("enter the pass");
          lcd.setCursor(0,1);
          i=0;
          }
      
      }
    
    
    
   
      
      
    
  
  
 
  
  
}
