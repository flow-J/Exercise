# coding: utf-8
#####
import random, pygame, sys, threading # 随机， pygame， ，线程
from pygame.locals import *

''' pygame模块
     pygame.cdrom    访问光驱
     pygame.color        颜色
     pygame.cursors    加载光标
     pygame.display    访问显示设备
     pygame.draw            绘制形状、线和点
     pygame.event    管理事件
     pygame.examples     不同的例子
     pygame.font            使用字体
     pygame.image    加载和存储图片
     pygame.gfxdraw      Anti-aliasing draw functions
     pygame.locals       常量
     pygame.joystick    使用游戏手柄或者 类似的东西
     pygame.key            读取键盘按键
     pygame.mixer    声音
     pygame.mouse    鼠标
     pygame.movie    播放视频
     pygame.music    播放音频
     pygame.overlay    访问高级视频叠加
     pygame            就是我们在学的这个东西了……
     pygame.rect            管理矩形区域
     pygame.scrap        本地剪贴板访问
     pygame.sndarray    操作声音数据
     pygame.sprite    操作移动图像
     pygame.surface    管理图像和屏幕
     pygame.surfarray    管理点阵图像数据
     pygame.tests        测试例子
     pygame.time            管理时间和帧信息
     pygame.transform    缩放和移动图像
 '''

# 创建常量
NUM_WORMS = 24  # 蠕虫在网格中的数量
FPS = 30	    # 帧数
CELL_SIZE = 20  # 20个像素宽高的格子
CELLS_WIDE = 32 # 32个格子(宽
CELLS_HIGH = 24 # 24个格子（高


GRID = [] # 网格
for x in range(CELLS_WIDE):
	GRID.append([None] * CELLS_HIGH)
