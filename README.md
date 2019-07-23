# DFRobot_PAJ7620
The PAJ7620 integrates gesture recognition function with general I2C interface into a single chip forming an image analytic sensor system. It can recognize 9 human hand gesticulations such as moving up, down, left, right, forward, backward, circle-clockwise, circle-counter Key Parameters clockwise, and waving. It also offers built-in proximity detection in sensing approaching or departing object from the sensor. The PAJ7620 is packaged into module form in-built with IR LED and optics lens as a complete sensor solution<br>

这里需要显示拍照图片，可以一张图片，可以多张图片（不要用SVG图）

![正反面svg效果图](https://github.com/ouki-wang/DFRobot_Sensor/raw/master/resources/images/SEN0245svg1.png)


## 产品链接（链接到英文商城）
    SKU：PAJ7620挥手传感器
   
## Table of Contents

* [Summary](#summary)
* [Installation](#installation)
* [Methods](#methods)
* [Compatibility](#compatibility)
* [History](#history)
* [Credits](#credits)

## Summary

这个Arduino库，我们实现了PAJ7620手势传感器的基础功能，你可以在内置的examples中体验这些功能
  1. 快速模式下，读取9种手势的功能
  2. 慢速模式下，读取9中基础手势和4中扩展手势的功能
  3. 基于快速模式，我们做了一个手势序列识别的例子，我们称之为手势密码

## Installation

To use this library, first download the library file, paste it into the \Arduino\libraries directory, then open the examples folder and run the demo in the folder.

## Methods

```C++
  /**
   * @brief 构造函数
   * @param mode 构造设备时，可以指定它的默认工作模式
   */
  DFRobot_PAJ7620U2(TwoWire *pWire=&Wire);

  /**
   * @brief 初始化函数
   * @return 返回0表示初始化成功，返回其他值表示初始化失败
   */
  int begin(void);

  /**
   * @brief 设置告诉手势识别模式
   * @param b true表示配置为高速识别模式，以最快速度识别手势并返回。
   * @n  false表示低速模式，在低速模式下，系统会做更多的判断
   * @n  在高速识别模式下，可以快速识别的动作包括向左滑动 向右滑动 向上滑动 向下滑动 
   * @n  向前滑动 向后滑动 逆时针 顺时针 快速挥手 9个动作
   * @n  高级用户如果想要用这些动作的组合，需要在外部自己算法逻辑，比如左右左快速挥手
   * @n  因为每个人用到的动作有限 ，我们没有将更多的扩展动作集在库中，需要用户在ino文件中自己完成算法逻辑
   * @n
   * @n
   * @n  在低速识别模式下，每2秒识别一个动作，我们将一些扩展动作集成到库内部，方便基础用户使用
   * @n  可以识别的动作包括向左滑动 向右滑动 向上滑动 向下滑动 向前滑动 向后滑动 
   * @n  逆时针 顺时针 快速挥手 9个基础动作 左右慢挥手 上下慢挥手 前后慢挥手 乱序慢挥手  4个扩展动作 
   */
  void setGestureHighRate(bool b);

  /**
   * @brief 获取手势号码对应的字符串描述
   * @param gesture 包含在eGesture_t中的手势号码
   * @return 手势号码对应的文字描述信息，如果输入了手势表中不存在的手势，返回空字符串
   * @n 正常的返回值可能是   "None","Right","Left", "Up", "Down", "Forward", "Backward", "Clockwise",
   * @n "Anti-Clockwise", "Wave", "WaveSlowlyDisorder", "WaveSlowlyLeftRight", "WaveSlowlyUpDown",
   * @n "WaveSlowlyForwardBackward"
   */
  String gestureDescription(eGesture_t gesture);
  /**
   * @brief 获取手势
   * @return 返回手势，可能是的值为eGestureNone  eGestureRight  eGestureLeft  eGestureUp  
   * @n     eGestureDown  eGestureForward  eGestureBackward  eGestureClockwise
   * @n     eGestureWave  eGestureWaveSlowlyDisorder  eGestureWaveSlowlyLeftRight  
   * @n     eGestureWaveSlowlyUpDown  eGestureWaveSlowlyForwardBackward
   */
  eGesture_t getGesture(void);
```

## Compatibility

MCU                | Work Well    | Work Wrong   | Untested    | Remarks
------------------ | :----------: | :----------: | :---------: | -----
Arduino uno        |      √       |              |             | 
Mega2560        |      √       |              |             | 
Leonardo        |      √       |              |             | 
mPython/ESP32   |      √       |              |             | 
Microbit        |      √       |              |             | 

## History

- data 2019-7-16
- version V1.0


## Credits

Written by Alexander(ouki.wang@dfrobot.com), 2019. (Welcome to our [website](https://www.dfrobot.com/))

