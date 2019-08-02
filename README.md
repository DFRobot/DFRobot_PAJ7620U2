# DFRobot_PAJ7620
The PAJ7620 integrates gesture recognition function with general I2C interface into a single chip forming an image analytic sensor system. It can recognize 9 human hand gesticulations such as moving up, down, left, right, forward, backward, circle-clockwise, circle-counter Key Parameters clockwise, and waving. It also offers built-in proximity detection in sensing approaching or departing object from the sensor. The PAJ7620 is packaged into module form in-built with IR LED and optics lens as a complete sensor solution<br>
* PAJ7620U2-based gesture recognition sensor, high accuracy, long detecting distance(the distance on the datasheet is 0-15cm, but actually it's up to 20cm during our test).
* We expanded a slow detection mode with 2s recognition cycle. Except the original 9 gestures, we developed four gesutres for this mode: wave slowly from left to right, from up to down, from forward to backward, wave slowly and randomly, which is very suitable for the beginners.  

这里需要显示拍照图片，可以一张图片，可以多张图片（不要用SVG图）

![正反面svg效果图](https://github.com/ouki-wang/DFRobot_Sensor/raw/master/resources/images/SEN0245svg1.png)


## Product Link（链接到英文商城）
    SKU：PAJ7620挥手传感器
   
## Table of Contents

* [Summary](#summary)
* [Installation](#installation)
* [Methods](#methods)
* [Compatibility](#compatibility)
* [History](#history)
* [Credits](#credits)

## Summary

In this Arduino library, we have realized the basic usage of the PAJ7620 gesture sensor. You can experience the functions below using the built-in examples: 
  1. Read the 9 gestures' function in fast mode. 
  2. Read the function of the 9 basic gestures and 4 expanded gestures in slow mode.
  3. An example of gesture sequence recognition in fast mode, we call it gesture code.

## Installation

To use this library, first download the library file, paste it into the \Arduino\libraries directory, then open the examples folder and run the demo in the folder.

## Methods

```C++
  /**
   * @brief Constructor 构造函数
   * @param mode When building a device, designate its default working mode. 构造设备时,可指定默认的工作模式
   */
  DFRobot_PAJ7620U2(TwoWire *pWire=&Wire);

  /**
   * @brief Init function
   * @return Return 0 if the initialization succeeds, otherwise return non-zero. 
   */
  int begin(void);

  /**
   * @brief Set the gesture recognition mode 
   * @param b true Fast detection mode, recognize gestures quickly and return 
   * @n  false Slow detection mode, the system will do more judgements. 
   * @n  In fast detection mode, the sensor can recognize 9 gestures: move left, right, up, down, 
   * @n  forward, backward, clockwise, counter-clockwise, wave.  
   * @n  To detect the combination of these gestures, like wave left, right and left quickly, users needs to design their own algorithms logic. 
   * @n  Since users only use limited gestures, we didn't integrate too much expanded gestures in the library. If necessary, you can complete the algorithm logic in the ino file by yourself.   
   * @n
   * @n
   * @n  In low detection mode, the sensor recognize one gesture every 2 seconds, and we integrated the expanded gestures inside the library, which is convenient for the beginners to use.  
   * @n  It can recognize 9  basic gestures and 4 expanded gestures: move left, right, up, down, forward, backward, clockwise, counter-clockwise, wave. 
   * @n  wave slowly from left to right, from up to down, from forward to backward, wave slowly and randomly
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
Arduino Uno        |      √       |              |             | 
Mega2560        |      √       |              |             | 
Leonardo        |      √       |              |             | 
mPython/ESP32   |      √       |              |             | 
micro:bit        |      √       |              |             | 

## History

- data 2019-7-16
- version V1.0


## Credits

Written by Alexander(ouki.wang@dfrobot.com), 2019. (Welcome to our [website](https://www.dfrobot.com/))

