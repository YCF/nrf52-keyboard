# Lot60-BLE 键盘

## 描述

- 5x14的60%键盘
- 一个Caps灯和一个状态指示灯
- Type-C接口

## 硬件

参见 [BLE60-keyboard](https://github.com/Lotlab/BLE60-keyboard)的 type-c 分支。

## 默认行为

在没有USB接入时，按键空闲15秒进入慢速扫描状态，600秒自动进入休眠。
自动休眠后按任意按键即可唤醒；手动休眠后需要按开机按钮开机。

插入USB也可以唤醒设备。

- Space+U 开机
- Space+E 清空绑定设备
- Fn+Caps 休眠
- Fn+Tabs 切换USB/蓝牙

## 默认指示灯颜色表

- <span style="color: #FFFFFF">白色</span>：无连接
- <span style="color: #66CCFF">天依蓝</span>：蓝牙已连接
- <span style="color: #0099FF">天蓝色</span>：USB已连接
- <span style="color: #FF8000">橙色</span>：充电中
- <span style="color: #00FF00">绿色</span>：充电完毕
- <span style="color: #FFFF00">黄色</span>：输入配对密码
- <span style="color: #FF0080">紫红色</span>：配对密码输入完毕
- <span style="color: #FF00FF">紫色</span>：休眠
