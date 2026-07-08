#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <Keypad.h>

LiquidCrystal_I2C lcd(0x27,16,2);

// Keypad setup
const byte ROWS = 4;
const byte COLS = 4;

char keys[ROWS][COLS] =
{
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'*','0','#','D'}
};

byte rowPins[ROWS] = {9,8,7,6};
byte colPins[COLS] = {5,4,3,2};

Keypad keypad = Keypad(makeKeymap(keys), rowPins, colPins, ROWS, COLS);

float num1 = 0;
float num2 = 0;
char op;
bool secondNumber = false;

void setup()
{
  lcd.init();
  lcd.backlight();

  lcd.setCursor(0,0);
  lcd.print("Calculator");
  delay(2000);
  lcd.clear();
}

void loop()
{
  char key = keypad.getKey();

  if(key)
  {
    // Number keys
    if(key >= '0' && key <= '9')
    {
      lcd.print(key);

      if(!secondNumber)
      {
        num1 = num1*10 + (key-'0');
      }
      else
      {
        num2 = num2*10 + (key-'0');
      }
    }

    // Operators
    else if(key=='A' || key=='B' || key=='C' || key=='D')
    {
      secondNumber = true;

      switch(key)
      {
        case 'A':
          op='+';
          lcd.print("+");
          break;

        case 'B':
          op='-';
          lcd.print("-");
          break;

        case 'C':
          op='*';
          lcd.print("*");
          break;

        case 'D':
          op='/';
          lcd.print("/");
          break;
      }
    }

    // Calculate
    else if(key=='#')
    {
      float answer;

      lcd.clear();

      switch(op)
      {
        case '+':
          answer = num1 + num2;
          break;

        case '-':
          answer = num1 - num2;
          break;

        case '*':
          answer = num1 * num2;
          break;

        case '/':
          if(num2==0)
          {
            lcd.print("Divide by Zero");
            delay(2000);
            clearCalculator();
            return;
          }
          answer = num1 / num2;
          break;
      }

      lcd.print("Ans=");
      lcd.print(answer);
    }

    // Clear
    else if(key=='*')
    {
      clearCalculator();
    }
  }
}

void clearCalculator()
{
  num1 = 0;
  num2 = 0;
  secondNumber = false;
  op = ' ';

  lcd.clear();
}