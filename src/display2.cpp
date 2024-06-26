// #include <Wire.h>
// #include <Adafruit_GFX.h>
// #include <Adafruit_SSD1306.h>
// #include "display.h"

// #define SCREEN_WIDTH 128 // OLED display width, in pixels
// #define SCREEN_HEIGHT 32 // OLED display height, in pixels

// // On an arduino MEGA 2560: 20(SDA), 21(SCL)
// #define OLED_RESET 10       // Reset pin # (or -1 if sharing Arduino reset pin)
// #define SCREEN_ADDRESS 0x3C ///< See datasheet for Address; 0x3D for 128x64, 0x3C for 128x32
// // Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);
// Adafruit_SSD1306 display(OLED_RESET);

// // External Functions in use
// extern String buttonPressed();
// //--------- External important functions---------------------------------------------------------
// extern void memorySaveMotorVariables();
// extern void generateThreshold();
// extern void readSensors();
// extern void generateBinary();
// extern void Run();
// extern double sonarSearch();
// extern void Stop(double del);
// //--------- External important variables----------------------------------------------------------
// extern float motorVariables[4];
// extern float &motorSpeed;
// extern float &P;
// extern float &I;
// extern float &D;
// const int numOfSensors = 8;
// extern int sensorThreshold[numOfSensors];
// extern int sensorRawReading[numOfSensors];
// extern boolean sensorBinaryReading[numOfSensors];

// // Global variables related to Option Selector
// int optX = 2;
// int optY = 2;
// int optH = 7;
// int optionsIterator = 0;
// const char *mainMenuOptions[6] = {
//     "PID_MENU",
//     "SENSOR_MENU",
//     "SERVO_MENU",
//     "SONAR_MENU",
//     "MEMORY_MENU",
//     "RUN"};
// const char *PIDoptions[6] =
//     {
//         "M_SP",
//         "P",
//         "I",
//         "D",
//         "SAVE",
//         "BACK"};
// const char *sensorMenuOptions[6] = {
//     "G_THRESHOLD",
//     "V_THRESHOLD",
//     "S_R_BIN",
//     "S_R_RAW",
//     "",
//     "BACK"};

// void displaySetup()
// {
//     Wire.begin();
//     display.begin(SSD1306_SWITCHCAPVCC, 0x3C);
// }

// void displayBootScreen()
// {

//     display.clearDisplay();
//     display.setTextSize(2);
//     display.setTextColor(SSD1306_WHITE);
//     display.setCursor(20, (SCREEN_HEIGHT / 3));
//     display.println(F("THUNDER"));
//     display.display();
//     delay(1000);
//     display.clearDisplay();
//     display.display();
//     delay(500);
// }

// void displayMenu(String menu_type)
// {
//     delay(300);
//     displayDrawMenu(menu_type);
//     displayOptionSelector(menu_type);
// }

// void optionHandler(String option)
// {
//     if (option == "SAVE")
//     {
//         display.clearDisplay();
//         display.display();
//         memorySaveMotorVariables();
//     }
//     else if (option == "G_THRESHOLD")
//     {
//         display.clearDisplay();
//         display.display();
//         generateThreshold();
//     }
//     else if (option == "V_THRESHOLD")
//     {
//         display.clearDisplay();
//         display.display();
//         delay(300);
//         while (true)
//         {
//             displayDrawMenu("SENSOR_THRESHOLD_MENU");
//             if (buttonPressed() != "NO")
//             {
//                 break;
//             }
//         }
//         delay(200);
//     }
//     else if (option == "S_R_RAW")
//     {
//         display.clearDisplay();
//         display.display();
//         delay(300);
//         while (true)
//         {
//             display.clearDisplay();
//             display.display();
//             readSensors();
//             displayDrawMenu("SENSOR_RAW_MENU");
//             if (buttonPressed() != "NO")
//             {
//                 break;
//             }
//         }
//         delay(200);
//     }
//     else if (option == "SONAR_MENU")
//     {
//         display.clearDisplay();
//         display.display();
//         delay(300);
//         while (true)
//         {
//             display.clearDisplay();
//             display.display();
//             displayDrawMenu("SONAR_MENU");
//             if (buttonPressed() != "NO")
//             {
//                 break;
//             }
//         }
//         delay(200);
//     }
//     else if (option == "RUN")
//     {
//         display.clearDisplay();
//         display.display();
//         while (true)
//         {
//             Run();
//             if (buttonPressed() != "NO")
//             {
//                 Stop(100);
//                 break;
//             }
//         }
//     }
//     else if (option == "S_R_BIN")
//     {
//         display.clearDisplay();
//         display.display();
//         delay(300);
//         while (true)
//         {
//             display.clearDisplay();
//             display.display();
//             readSensors();
//             generateBinary();
//             displayDrawMenu("SENSOR_BINARY_MENU");
//             if (buttonPressed() != "NO")
//             {
//                 break;
//             }
//         }
//         delay(200);
//     }
// }

// void displayDrawMenu(String menuType)
// {
//     int x = 14;
//     int y = 2;
//     int left_padding = 25;
//     display.clearDisplay();
//     display.display();
//     // Draw Horizontal line
//     // for (int16_t i = 0; i < display.height(); i += 10)
//     // {
//     //     display.drawLine(0, i, display.width() - 1, i, SSD1306_WHITE);
//     // }

//     if (menuType == "MAIN_MENU")
//     {
//         // Drawing the gridlines
//         display.setTextSize(1); // Set the text size
//         display.setTextColor(SSD1306_WHITE);
//         display.setCursor(left_padding, SCREEN_HEIGHT / 3);
//         display.println(mainMenuOptions[optionsIterator]);
//     }
//     else if (menuType == "PID_MENU")
//     {
//         display.setTextSize(1); // Set the text size
//         display.setTextColor(SSD1306_WHITE);
//         display.setCursor(left_padding, SCREEN_HEIGHT / 3);
//         display.println(PIDoptions[optionsIterator]);
//         display.setCursor(SCREEN_WIDTH / 2, SCREEN_HEIGHT / 3);
//         if (optionsIterator < 4)
//             display.println(motorVariables[optionsIterator]);
//     }
//     else if (menuType == "SENSOR_MENU")
//     {
//         display.setTextSize(1); // Set the text size
//         display.setTextColor(SSD1306_WHITE);
//         display.setCursor(left_padding, SCREEN_HEIGHT / 3);
//         display.println(sensorMenuOptions[optionsIterator]);
//     }
//     else if (menuType == "SENSOR_THRESHOLD_MENU")
//     {
//         display.drawLine(0, 0, 0, display.height() - 5, SSD1306_WHITE);
//         display.drawLine(10, 0, 10, display.height() - 5, SSD1306_WHITE);
//         display.drawLine(display.width() / 2, 0, display.width() / 2, display.height() - 5, SSD1306_WHITE);
//         display.drawLine(display.width() - 1, 0, display.width() - 1, display.height() - 5, SSD1306_WHITE);
//         display.drawLine(display.width() - 11, 0, display.width() - 11, display.height() - 5, SSD1306_WHITE);
//         display.setTextSize(1);
//         display.setTextColor(SSD1306_WHITE);
//         for (int optionsIterator = 0; optionsIterator < numOfSensors / 2; optionsIterator++, y += 10)
//         {
//             display.setCursor(x, y);                           // Set the cursor position . The top left position is 0,0
//             display.println(sensorThreshold[optionsIterator]); // Print from the cursor position
//             display.setCursor(display.width() / 2 + 4, y);
//             display.println(sensorThreshold[(numOfSensors - 1) - optionsIterator]);
//         }
//     }
//     else if (menuType == "SENSOR_RAW_MENU")
//     {
//         display.drawLine(0, 0, 0, display.height() - 5, SSD1306_WHITE);
//         display.drawLine(10, 0, 10, display.height() - 5, SSD1306_WHITE);
//         display.drawLine(display.width() / 2, 0, display.width() / 2, display.height() - 5, SSD1306_WHITE);
//         display.drawLine(display.width() - 1, 0, display.width() - 1, display.height() - 5, SSD1306_WHITE);
//         display.drawLine(display.width() - 11, 0, display.width() - 11, display.height() - 5, SSD1306_WHITE);
//         display.setTextSize(1);
//         display.setTextColor(SSD1306_WHITE);
//         for (int optionsIterator = 0; optionsIterator < numOfSensors / 2; optionsIterator++, y += 10)
//         {
//             display.setCursor(x, y);                            // Set the cursor position . The top left position is 0,0
//             display.println(sensorRawReading[optionsIterator]); // Print from the cursor position
//             display.setCursor(display.width() / 2 + 4, y);
//             display.println(sensorRawReading[(numOfSensors - 1) - optionsIterator]);
//         }
//     }
//     else if (menuType == "SENSOR_BINARY_MENU")
//     {
//         display.drawLine(0, 0, 0, display.height() - 5, SSD1306_WHITE);
//         display.drawLine(10, 0, 10, display.height() - 5, SSD1306_WHITE);
//         display.drawLine(display.width() / 2, 0, display.width() / 2, display.height() - 5, SSD1306_WHITE);
//         display.drawLine(display.width() - 1, 0, display.width() - 1, display.height() - 5, SSD1306_WHITE);
//         display.drawLine(display.width() - 11, 0, display.width() - 11, display.height() - 5, SSD1306_WHITE);
//         display.setTextSize(1);
//         display.setTextColor(SSD1306_WHITE);
//         for (int optionsIterator = 0; optionsIterator < numOfSensors / 2; optionsIterator++, y += 10)
//         {
//             display.setCursor(x, y);                               // Set the cursor position . The top left position is 0,0
//             display.println(sensorBinaryReading[optionsIterator]); // Print from the cursor position
//             display.setCursor(display.width() / 2 + 4, y);
//             display.println(sensorBinaryReading[(numOfSensors - 1) - optionsIterator]);
//         }
//     }
//     else if (menuType == "SONAR_MENU")
//     {
//         display.setTextSize(1); // Set the text size
//         display.setTextColor(SSD1306_WHITE);
//         display.setCursor(left_padding, SCREEN_HEIGHT / 3);
//         display.println(sonarSearch());
//     }
//     display.display();
// }

// void displayOptionSelector(String menuType)
// {
//     optionsIterator = 0;
//     String buttonInstruction;
//     if (menuType == "MAIN_MENU")
//     {
//         while (true)
//         {
//             buttonInstruction = buttonPressed();
//             if (buttonInstruction != "NO")
//             {

//                 if (buttonInstruction == "BTN_DOWN" && optionsIterator < 5)
//                 {
//                     optionsIterator++;
//                 }
//                 else if (buttonInstruction == "BTN_UP" && optionsIterator > 0)
//                 {
//                     optionsIterator--;
//                 }
//                 else if (buttonInstruction == "BTN_SELECT" && optionsIterator < 5)
//                 {

//                     displayMenu(mainMenuOptions[optionsIterator]);
//                 }
//                 else if (buttonInstruction == "BTN_SELECT" && optionsIterator == 5)
//                 {

//                     optionHandler("RUN");
//                 }
//                 else if (buttonInstruction == "BTN_SELECT" && optionsIterator == 3)
//                 {
//                     optionHandler(mainMenuOptions[optionsIterator]);
//                 }
//                 displayDrawMenu("MAIN_MENU");
//                 display.display();
//                 delay(100);
//             }
//         }
//     }
//     else if (menuType == "PID_MENU")
//     {
//         while (true)
//         {
//             buttonInstruction = buttonPressed();
//             if (buttonInstruction != "NO")
//             {

//                 if (buttonInstruction == "BTN_UP" && optionsIterator > 0)
//                 {
//                     optionsIterator--;
//                 }
//                 else if (buttonInstruction == "BTN_DOWN" && optionsIterator < 5)
//                 {
//                     optionsIterator++;
//                 }
//                 else if (buttonInstruction == "BTN_LEFT" && optionsIterator < 4)
//                 {
//                     if (strcmp(PIDoptions[optionsIterator], "M_SP") == 0)
//                         motorVariables[optionsIterator] -= 5;
//                     else
//                         motorVariables[optionsIterator] -= 0.2;
//                 }
//                 else if (buttonInstruction == "BTN_RIGHT" && optionsIterator < 4)
//                 {
//                     if (strcmp(PIDoptions[optionsIterator], "M_SP") == 0)
//                         motorVariables[optionsIterator] += 5;
//                     else
//                         motorVariables[optionsIterator] += 0.2;
//                 }
//                 else if (buttonInstruction == "BTN_SELECT" && optionsIterator > 3)
//                 {
//                     if (strcmp(PIDoptions[optionsIterator], "BACK") == 0)
//                     {
//                         delay(200);
//                         return;
//                     }
//                     else
//                     {
//                         optionHandler(PIDoptions[optionsIterator]);
//                         delay(200);
//                     }
//                 }
//                 displayDrawMenu("PID_MENU");
//                 display.display();
//                 delay(200);
//             }
//         }
//     }
//     else if (menuType == "SENSOR_MENU")
//     {
//         while (true)
//         {
//             buttonInstruction = buttonPressed();
//             if (buttonInstruction != "NO")
//             {

//                 if (buttonInstruction == "BTN_UP" && optionsIterator > 0)
//                 {
//                     optionsIterator--;
//                 }
//                 else if (buttonInstruction == "BTN_DOWN" && optionsIterator < 5)
//                 {
//                     optionsIterator++;
//                 }
//                 else if (buttonInstruction == "BTN_SELECT" && optionsIterator > 0 && optionsIterator < 6)
//                 {
//                     if (strcmp(sensorMenuOptions[optionsIterator], "BACK") == 0)
//                     {
//                         delay(300);
//                         return;
//                     }
//                     else
//                     {
//                         optionHandler(sensorMenuOptions[optionsIterator]);
//                         delay(300);
//                     }
//                 }
//                 displayDrawMenu("SENSOR_MENU");
//                 display.drawRect(optX, optY, optH, optH, SSD1306_WHITE);
//                 display.fillRect(optX, optY, optH, optH, SSD1306_WHITE);
//                 display.display();
//                 delay(300);
//             }
//         }
//     }
// }
