> Logo 程序设计语言成就了一个著名的概念“海龟图”(Turtle Graphic)。设想个机器海龟在一个 C 程序的控制下在一个房间里爬行。海龟拿着一支要么向上要么向下的笔。当笔向下时，海龟就画出它所走过的路线。当笔向上时，海龟就自由地爬行而不留下任何痕迹。本问题中，请模拟海龟的操作，创造出一个计算机画板程序。程序使用一个初始值是零的50乘50数组r表示一个房间的地板程序读人事先存在个数组中的命令,并且随时记录海龟所处的位置以及笔的状态.假设海龟总是拿着向上的笔从数组 foor 的 (0,0) 位置出发，程序用到的海龟命令如图所示。设目前海龟正位于地板中心附近的某个位置上，下面的“命令序列”将画出一个12乘12的正方形:
> 2
> 5,12
> 3
> 5,12
> 5,12
> 3
> 5,12
> 6
> 9

| 命令 | 含义               |
| ---- | ------------------ |
| 1    | 笔向上             |
| 2    | 笔向下             |
| 3    | 右转               |
| 4    | 左转               |
| 5 x  | 向前走x格          |
| 9    | 标志当前指令组结束 |



按照上述要求用 QT 对海龟画图进行简单实现，包含以下部分：

- inputcontroller 独立线程，处理终端的用户输入
- turtle 对海龟类进行简单封装
- mainwindow UI界面，在 paintEvent 中根据指令绘制图形



运行程序之后在终端中输入命令即可开始画图，需注意：

- 截止指令为9，输入9并回车即可刷新显示
- 一条指令占据一行空间，多个参数的情况使用空格进行分割
- 程序会保存绘画指令，直到输入下一组以9结尾的指令后画面才会更新

**程序对于画图指令的功能实现并不完整**，目前仅支持指令5，运行程序后在终端中输入

```no
5 20
9
```

即可预览绘制效果。其他功能搜索 ``TODO`` 关键字，在该处对代码进行补全。