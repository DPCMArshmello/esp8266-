#include <TJpg_Decoder.h>
#include <ESP8266HTTPClient.h>
#include <Arduino.h>
#include<ESP8266WiFi.h>
#include <ArduinoJson.h>
#include <NTPClient.h>
#include <WiFiUdp.h>
#include "SPI.h"
#include <TFT_eSPI.h>
#include <Wire.h>
#include "jpg.h"
#include<string.h>
#include <DNSServer.h>
#include <ESP8266WebServer.h>
#include"dog.h"
/*
@AUTHOR DiaoPengChaug
DATA:2023/1/10
*/

/*************************************************/
#include "font/ZdyLwFont_20.h"
#include "font/songti12.h"
/*************************************************/

void getwheather();
void ui();
const char* ssid = "DPC";
const char* password = "dpc54321";
//const String W_url="http://api.seniverse.com/v3/weather/now.json?key=STkS69ZY9Jlbffqhz&location=TZY33C4YJBP3&language=en&unit=c";
//const String W_url="http://api.seniverse.com/v3/weather/daily.json?key=STkS69ZY9Jlbffqhz&location=TZY33C4YJBP3&language=en&unit=c&start=-1&days=5";

/********************************************************天气的变量***********************************************************************************************/

const String W_url="http://api.seniverse.com/v3/weather/daily.json?key=STkS69ZY9Jlbffqhz&location=TZY33C4YJBP3&language=zh-Hans&unit=c&start=-1&days=5";
String  g_strUpdateTime;
int  g_high_iTemperature;
int  g_low_iTemperature;
int g_iCode;
String g_strWeather="wait";
String g_name;
String wind_direction;
String humidity;
String g_data;
String  Tomorrow_g_strUpdateTime;
int  Tomorrow_g_high_iTemperature;
int  Tomorrow_g_low_iTemperature;
int Tomorrow_g_iCode;
String Tomorrow_g_strWeather="wait";
String Tomorrow_g_name;
String T_data;

String  acquired_g_strUpdateTime;
int  acquired_g_high_iTemperature;
int  acquired_g_low_iTemperature;
int acquired_g_iCode;
String acquired_g_strWeather="wait";
String acquired_g_name;
String a_data;

WiFiUDP ntpUDP;
NTPClient timeClient(ntpUDP,"ntp1.aliyun.com",60*60*8, 30*60*1000);
int huors=-1,minutes=-1,second=-1;
/*********************************************************************************************************************************************************/
/*************************tft********************************************/
TFT_eSPI tft = TFT_eSPI();
bool tft_output(int16_t x, int16_t y, uint16_t w, uint16_t h, uint16_t *bitmap)
{
  if (y >= tft.height())
    return 0;
  tft.pushImage(x, y, w, h, bitmap);
  // Return 1 to decode next block
  return 1;
}
void show_w(int code,int x,int y){
    tft.setSwapBytes(true);
    TJpgDec.setCallback(tft_output);
    show_weather(code,x,y);
}
/**********************************************************************/
void NPT_init(){
  timeClient.update();
  huors=timeClient.getHours() ;
  minutes=timeClient.getMinutes();
  second=timeClient.getSeconds();
}
void NPT_time(){
  timeClient.update();
  huors=timeClient.getHours() ;
  minutes=timeClient.getMinutes();
  second=timeClient.getSeconds();
  tft.setCursor(120,5);//设置坐标
  tft.setTextSize(1);
  /*****************显示时间***********************/
  tft.setTextColor(ILI9341_ORANGE,ILI9341_WHITE);
  tft.setTextFont(7);
  tft.print(huors);tft.print(":");
  if (minutes<10)
  {
    tft.print(0);
    tft.print(minutes);
  }else{
    tft.print(minutes);
  }
  tft.setTextFont(1);
  tft.setTextSize(3);
  tft.setTextColor(ILI9341_ORANGE,ILI9341_WHITE);
  if (second<10)
  { 
    tft.print(0);
    tft.print(second);
  }else{
    tft.print(second);
  }
  if(second==59){
    ui();
  }
  tft.setTextFont(2);
  tft.setTextSize(2);
  tft.setCursor(140,60);//设置坐标
  /*************显示日期********************/
  tft.print(g_strUpdateTime);

 
}
/***********************************************************************/

void getwheather(){
  tft.setTextColor(ILI9341_BLACK);
  WiFiClient client;
  HTTPClient http;
  http.useHTTP10(true);
  http.begin(client,W_url);
  
  http.GET();
  String result = http.getString();
  
  DynamicJsonDocument doc(2048);
  deserializeJson(doc, result);
  
  // Test if parsing succeeds.
  JsonObject results_0 = doc["results"][0];
  JsonObject results_0_location = results_0["location"];
  JsonObject results_0_daily_item = results_0["daily"][0];
  JsonObject results_1_daily_item = results_0["daily"][1];
  JsonObject results_2_daily_item = results_0["daily"][2];
  
  g_strWeather = results_0_daily_item["text_day"].as<String>();
  g_iCode = results_0_daily_item["code_day"].as<int>();// "0"             //获得天气代码
  g_high_iTemperature = results_0_daily_item["high"].as<int>(); //获得温度
  g_low_iTemperature = results_0_daily_item["low"].as<int>(); 
  g_strUpdateTime = results_0_daily_item["date"].as<String>();
  g_name=results_0_location["name"].as<String>();
  wind_direction=results_0_daily_item["wind_direction"].as<String>();
  humidity=results_0_daily_item["humidity"].as<String>();

  g_data=g_strUpdateTime.substring(5);
  Tomorrow_g_strWeather = results_1_daily_item["text_day"].as<String>();
  Tomorrow_g_high_iTemperature = results_1_daily_item["high "].as<int>(); //获得温度
  Tomorrow_g_low_iTemperature = results_1_daily_item["low"].as<int>(); 
  Tomorrow_g_strUpdateTime = results_1_daily_item["date"].as<String>();
  T_data=Tomorrow_g_strUpdateTime.substring(5);

  
  acquired_g_strWeather = results_2_daily_item["text_day"].as<String>();
  acquired_g_high_iTemperature = results_2_daily_item["high "].as<int>(); //获得温度
  acquired_g_low_iTemperature = results_2_daily_item["low"].as<int>(); 
  acquired_g_strUpdateTime = results_2_daily_item["date"].as<String>();
  a_data=acquired_g_strUpdateTime.substring(5);
  http.end();
}
void ui(){
  getwheather();
   

  tft.loadFont(ZdyLwFont_20);
 
  tft.setCursor(100,0);
  tft.println("星");
  tft.setCursor(100,30);
  tft.println("期");
  tft.setCursor(100,60);
  tft.setTextColor(ILI9341_BLACK,ILI9341_WHITE);
  tft.print(timeClient.getDay());

  tft.setCursor(0,100);

  tft.print(g_name);tft.print(" 天气:");tft.print(g_strWeather);tft.print(" 风向:");tft.print(wind_direction);
  
  tft.setCursor(0,125); tft.print("空气湿度: "+humidity+"%"); 
  tft.setCursor(0,145);

  tft.print(g_data);tft.print("   ");tft.print(T_data);tft.print("   ");tft.println(a_data);


  tft.setCursor(0,165);
  tft.print(g_high_iTemperature);tft.print("°");
  tft.setCursor(80,165);
  tft.print(Tomorrow_g_high_iTemperature);tft.print("°");
  tft.setCursor(160,165);
  tft.print(acquired_g_high_iTemperature);tft.println("°");

  tft.setCursor(0,185);
  tft.print(g_low_iTemperature); tft.print("°");
  tft.setCursor(80,185);
  tft.print(Tomorrow_g_low_iTemperature); tft.print("°");
  tft.setCursor(160,185);
  tft.print(acquired_g_low_iTemperature);tft.println("°");
  show_w(102,0,210);
  tft.unloadFont();


}
void setup() { 
    Serial.begin(115200);
    tft.begin();    
    tft.setTextColor(ILI9341_BLACK);
    tft.fillScreen(ILI9341_WHITE);
    tft.setRotation(1);
    tft.setTextSize(2);
    WiFi.begin(ssid, password, 6);
//  WiFiManager wifiManager;
//  wifiManager.autoConnect("AutoConnectAP");  
  while (WiFi.status() != WL_CONNECTED) {
      delay(100);
      tft.print(".");
  }

  tft.println("\nOK! Is connected");
  tft.println(WiFi.localIP());
  delay(1000);
  tft.fillScreen(ILI9341_WHITE);
  NPT_init();
  ui();
  show_w(g_iCode,0,0);   
}
void loop(void) {
    for (int i = 0; i < 14; i++)
    {
      tft.setSwapBytes(true);
      TJpgDec.setCallback(tft_output);
      gif_d(i,220,140); // 显示太空人的动画
      NPT_time();
      delay(10);
    }
}
