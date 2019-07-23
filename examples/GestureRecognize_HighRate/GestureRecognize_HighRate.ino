/*!
 * @file GestureRecognize_HighRate.ino
 * @brief 展示传感器内置支持的9种手势数据
 * @n 在传感器上方0-20cm的距离内挥手，传感器能识别到向左滑动 向右滑动 向上滑动 向下滑动 向前滑动 向后滑动 逆时针 顺时针 快速挥手9种基础动作
 * @n 更多使用方式，详见setup函数中对setGestureHighRate函数的说明
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
  DFRobot_PAJ7620U2::eGesture_t gesture = paj.getGesture();
  if(gesture != paj.eGestureNone ){
   /* 获取手势号码对应的字符串描述
    * 字符串描述可能是 
    * "None","Right","Left", "Up", "Down", "Forward", "Backward", "Clockwise", "Anti-Clockwise", "Wave",
    * "WaveSlowlyDisorder", "WaveSlowlyLeftRight", "WaveSlowlyUpDown", "WaveSlowlyForwardBackward"
    */
    String description  = paj.gestureDescription(gesture);//将手势号码转换为描述字符串
    Serial.println("--------------Gesture Recognition System---------------------------");
    Serial.print("gesture code        = ");Serial.println(gesture);
    Serial.print("gesture description  = ");Serial.println(description);
    Serial.println();
  }
}
