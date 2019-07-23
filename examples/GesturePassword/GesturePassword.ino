/*!
 * @file GesturePassword.ino
 * @brief 在高速模式下，通过自己写算法，实现手势密码
 * @n 在20秒钟内输入手势密码，如果正确，则进入系统，否则继续等待用户输入密码
 * @n 超时时间可以通过更改TIMEOUT宏来调节，单位是毫秒
 *
 * @copyright   Copyright (c) 2010 DFRobot Co.Ltd (http://www.dfrobot.com)
 * @licence     The MIT License (MIT)
 * @author      Alexander(ouki.wang@dfrobot.com)
 * @version  V1.0
 * @date  2019-07-16
 * @get from https://www.dfrobot.com
 * @url https://github.com/DFRobot/DFRobot_PAJ7620U2
 */
 
#include <DFRobot_PAJ7620U2.h>

DFRobot_PAJ7620U2 paj;


//你需要在TIMEOUT毫秒内输入正确的手势up up down down left left right right
DFRobot_PAJ7620U2::eGesture_t password[]={DFRobot_PAJ7620U2::eGestureUp,DFRobot_PAJ7620U2::eGestureUp,DFRobot_PAJ7620U2::eGestureDown,DFRobot_PAJ7620U2::eGestureDown,\
  DFRobot_PAJ7620U2::eGestureLeft,DFRobot_PAJ7620U2::eGestureLeft,DFRobot_PAJ7620U2::eGestureRight,DFRobot_PAJ7620U2::eGestureRight};

static uint8_t index = 0;     //已经输入正确密码的个数
bool correct = false;  //密码是否已经输入正确
#define TIMEOUT 20000 //输入密码超时时间，单位是毫秒

void setup()
{
  Serial.begin(115200);
  delay(300);
  Serial.println("Gesture recognition system base on PAJ7620U2");
  while(paj.begin() != 0){
    Serial.println("initial PAJ7620U2 failure! 请检查设备是否稳定连接，线序是否正确");
    delay(500);
  }
  Serial.println("PAJ7620U2初始化完成，可以开始测试手势识别功能了");
  
  /*设置快速挥手识别模式
   *参数填写false 模块进入慢速识别状态，每2秒识别一个动作，我们将一些扩展动作集成到库内部，方便基础用户使用
   *可以识别的动作包括向左滑动 向右滑动 向上滑动 向下滑动 向前滑动 向后滑动 逆时针 顺时针 快速挥手 9个基础动作
   *左右慢挥手 上下慢挥手 前后慢挥手 乱序慢挥手  4个扩展动作 
   *
   *
   *
   *参数填写true 模块进入快速识别状态
   *可以识别的动作包括向左滑动 向右滑动 向上滑动 向下滑动 向前滑动 向后滑动 逆时针 顺时针 快速挥手 9个动作
   *高级用户如果想要用这些动作的组合，需要在外部自己算法逻辑，比如左右快速挥手，手斜向下滑动，因为每个人用到的动作有限
   *在高速模式下，我们不计划将更多的扩展动作集在库中，需要用户在ino文件中自己完成算法逻辑
   */
  paj.setGestureHighRate(true);
}

void loop()
{
  /* 读取手势号码（返回eGesture_t枚举类型）
   * eGestureNone  eGestureRight  eGestureLeft  eGestureUp  eGestureDown  eGestureForward
   * eGestureBackward  eGestureClockwise  eGestureAntiClockwise  eGestureWave  eGestureWaveSlowlyDisorder
   * eGestureWaveSlowlyLeftRight  eGestureWaveSlowlyUpDown  eGestureWaveSlowlyForwardBackward
   */
  DFRobot_PAJ7620U2::eGesture_t gesture;
  uint8_t pdLen = sizeof(password)/sizeof(password[0]);
  Serial.print("密码长度=");Serial.println(pdLen);
  unsigned long startTimeStamp = millis();
  Serial.print("请输入第 "); Serial.print(index+1); Serial.println(" 个手势");
  do{
    unsigned long now = millis();
    if(now - startTimeStamp >= TIMEOUT){
        startTimeStamp = now;
        index = 0;
        Serial.println("输入超时，请重新输入");
        Serial.print("请输入第 "); Serial.print(index+1); Serial.println(" 个手势");
    }
    gesture = paj.getGesture();
    if(gesture == paj.eGestureNone){
      continue;
    }
    Serial.println(paj.gestureDescription(gesture));
    if(gesture == password[index]){
      index++;
      Serial.print("请输入第 "); Serial.print(index+1); Serial.println(" 个手势");
    }else{
      startTimeStamp = millis();
      index = 0;
      Serial.println("手势密码输入错误，请重新输入");
      Serial.print("请输入第 "); Serial.print(index+1); Serial.println(" 个手势");
    }
    if(index == pdLen){
      correct = true;
    }
  }while(!correct);
  Serial.println("手势解锁成功，您已经进入系统");
  Serial.print("输入手势密码耗时 ");
  Serial.print((millis()-startTimeStamp)/1000);
  Serial.println(" 秒");
  
  
  //TO DO
  while(1);
}
