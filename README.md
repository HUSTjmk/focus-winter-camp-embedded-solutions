# 机电/嵌入式赛道的参考解决方案

### 这个仓库存放了机电赛道的解决方案，主要包括文档、历程、学习路径等 
- datasheets目录下存放一些可能用到的资料，供各位查阅  
- docs目录下放置一些需要的图片、视频等

### 机械篇
- 以下有4个TASK，其中TASK1为环境相关，TASK2为基础任务，TASK3为附加任务，TASK4为心得体会。必做任务是TASK1、TASK2与TASK4，建议机械组同学尽快完成前两个任务，方便电控组同学后续进行调试  
- 机械组的同学们，学长学姐已经默认你们这一学期已经学到了SolidWorks等3D建模软件的绘图功能以及BambuStudio的基础参数设置，这两个软件功能还不太熟练的同学请先从b站上自学相应的内容，方便后续任务的完成  
- FOCUS团队为你们提供各种装配工具以及两台拓竹打印机  
- 有任何问题及时在群里询问学长学姐帮你解决  
- TASK1：**环境搭建**\
  良好的开端是成功的一半，请确保你的电脑上已经有SolidWorks（2024版，一定要是这个版本，不然学长学姐们打不开你的文件）和BambuStudio两款软件，还没有下载的同学可以参考以下资料:  
  Solidworks（2024版）一键下载：https://www.bilibili.com/video/BV14rDwYnEpe/?spm_id_from=333.337.search-card.all.click&vd_source=fcc63609845574c1206cec5c666affba  
  BambuStudio请自行到拓竹官网上进行下载
- TASK2：**基础任务**  
  - TASK2.0：**机械小狗的建模与装配**
    - TASK 2.0.0: **小狗本体与履带的建模**\
      你需要通过SolidWorks进行小狗本体的建模、履带建模、链轮建模、直流电机建模等  
      (1)：小狗本体的建模应有预留的孔位可以固定电机、舵机、OLED屏幕等。整个小狗体积（包括履带）限制在256mm×256mm×200mm，不要超过这个限制  
      (2)：舵机、OLED屏的建模应尽可能准确，方便后续装配。你也可以向商家索要最为准确模型  
      (3)：对于小狗本体上明显的棱边需要进行倒角或圆角处理  
      (4)：履带和链轮建模可以参考以下视频：  
      1、https://www.bilibili.com/video/BV1h9VgzPEYk/?spm_id_from=333.1387.favlist.content.click&vd_source=fcc63609845574c1206cec5c666affba  
      2、https://www.bilibili.com/video/BV1Tz42117Ah/?spm_id_from=333.1387.favlist.content.click&vd_source=fcc63609845574c1206cec5c666affba  
      3、https://www.bilibili.com/video/BV1hj8ze8EAq/?spm_id_from=333.1387.favlist.content.click&vd_source=fcc63609845574c1206cec5c666affba  
    - TASK 2.0.1：**机械小狗的装配**\
      单个零件并没有什么作用，他们装配起来才是一个完整的机构  
      你需要把所有的零件装配成一个装配体，并进行干涉检查  
      最后，将装配体打包，并连同干涉检查截图与软件组一起上传在git地址里  
      ⚠ 装配完成后请务必进行干涉检查，不允许出现大于1mm³的干涉（过盈配合等除外）    
      <img src="datasheets/Machine/3.png" alt="装配体打包" width="640">
      <img src="datasheets/Machine/1.png" alt="干涉检查截图" width="640">
  - TASK2.1 **小狗本体的3D打印**\
    先前没有使用过BambuStudio的小伙伴请从b站上学习完相应3D打印知识后再进行小狗本体等3D打印  
     ⚠ 团队内不允许出现过夜打印件  
- TASK3：**附加任务**\
  我们的任务最终是为了做出一个完整的产品，而完整的产品要求好的封装、内部电子元器件都应是固定好的  
  你需要设计出一个外壳，尽可能地包裹住内部的电路与走线，并且固定好内部的电路板、电池等所有电子元器件   
  (1)：这只是附加任务，你设计的小狗外壳不应干扰小狗的正常功能  
  (2)：你所设计的外壳要稳定，不能存在走几步就松动的情况  
  (3)：小狗外壳要方便拆解，请不要直接用胶水粘上，这样不方便后续调试
- TASK4：**心得体会**  
  闻一多先生有言：“莫问收获，但问耕耘”。无论结果如何，我们总会在前进的过程中收获很多  
  请写一篇关于你在冬令营收获了什么的文章，文体不限，字数不少于300字，文件名为“小队名称+机械组+姓名”，并连同先前的文件一起传到git地址里  
 
### 嵌入式篇
- 嵌软的同学，学长学姐已经默认你们这一学期已经学习了C/C++的编程，对于github的使用，学长不多介绍了。
- **学习路径 && 资料说明：**  
  **所有手册资料/学习路径仅供参考，不一定与实际解决的问题对口，请发挥主观能动性**  
  1. **环境搭建**    
    千里之行，始于足下！开发一块板子你首先需要一个开发环境。对于stm32开发来说，主流有寄存器/标准库/HAL库等开发方式。我们推荐HAL库开发，学长的代码也是HAL库的，当然你也可以参考江科大等优秀的历程使用其他方式开发。下面是我们推荐的教程：
      - 标准库：[闻名四海的江科大](https://www.bilibili.com/video/BV1th411z7sn)
      - HAL库（Keil+Cubemx+VScode）：[尚硅谷，没时间可以跳过寄存器](https://www.bilibili.com/video/BV1KM4m1U7f1/)
      - HAL库（Clion）：[keysking，cmake开发的历程比较少，上手稍微有点难度](https://www.bilibili.com/video/BV1pnjizYEAk)    
  2. **运动控制**       
    运动是桌宠的必备技能。我们为你们提供了两个个直流减速电机和一个舵机，你需要用他们驱动轮子/尾巴，使你的桌宠动起来！而最简单的驱动电机/舵机方式需要用到很基础但很实用的一种技术——PWM，并且驱动电机时我们采用drv8870电机驱动芯片实现，下面是我们提供的教程与手册：  
    路径：[datasheets/Software/运动相关资料](datasheets/Software/运动相关资料)   
    网址：对应教程的pwm章节 && [CSDN上的一篇DRV8837教程](https://blog.csdn.net/weixin_45229061/article/details/142480529)  
  3. **语音交互**
    语音是人机交互的重要方式。我们将用SU-03T芯片实现简单的离线对话，下面是我们提供的教程与手册：  
    路径：[datasheets/Software/SU-03T1语音模块无底板已焊接](datasheets/Software/SU-03T1语音模块无底板已焊接)   
    网址：对应教程的串口章节 && [机芯智能B站官方教程](https://www.bilibili.com/video/BV1DG4y1u7mb/)
  4. **UI设计**  
    相必很多人看过江科大的stm32教程，上面用了OLED作为一个有力的调试工具。当然OLED也可以显示许多表情和文字，实现产品丰富的UI功能，下面是我们提供的教程与手册：    
    路径：[datasheets/Software/0.96寸OLED](datasheets/Software/0.96寸OLED)  
    网址：[江科大OLED教程](https://www.bilibili.com/video/BV1EN41177Pc/) && [HAL库版本的OLED使用](https://www.bilibili.com/video/BV1M6ioYzE58)  
  5. **跟随功能**  
    我们已经实现了桌宠的基本功能——行走、对话。但是学长学姐想要一个”粘人的桌宠“。为实现这个功能，或许HC-SR04超声波模块会有所帮助，下面是我们提供的教程与手册：  
    路径：[datasheets/Software/HC-SR04超声模块](datasheets/Software/HC-SR04超声模块)  
    网址：[CSDN上的一篇教程，讲超声模块原理及如何使用](https://blog.csdn.net/qq_16519885/article/details/113778828) && [CSDN另外一篇教程，告诉你一种智能小车这么做，看看里面的跟随功能即可，其他功能也可以借鉴一下](https://blog.csdn.net/m0_74712453/article/details/134113174) && [PID可以让运动更平滑一些](https://www.bilibili.com/video/BV1oE421T7Ey)  
    By the way: 这是一个演示视频，本地路径为：[docs/Software/ultrasonic-pid.mp4](docs/Software/ultrasonic-pid.mp4)    
    [![超声波PID控制演示](https://github.com/HUSTjmk/focus-winter-camp-embedded-solutions/raw/main/docs/Software/ultrasonic-pid.jpg)](https://github.com/HUSTjmk/focus-winter-camp-embedded-solutions/raw/main/docs/Software/ultrasonic-pid.mp4)
  7. **手势传感**    
    我们要使用的是PAJ7620U2手势传感器模块，它可以识别基础的手势，丰富我们与桌宠的交互方式，下面是我们提供的教程与手册：
    路径：[datasheets/Software/PAJ7620手势传感器](datasheets/Software/PAJ7620手势传感器)  
    网址:[CSDN上的一篇教程](https://blog.csdn.net/2501_92816716/article/details/154502471)
