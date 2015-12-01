# 第三章 基础算法

## 1 枚举算法

* 所谓枚举算法，是指从可能的集合中一一枚举各元素，用题目给定的检验条件判定哪些是有用的，哪些是无用的。能使命题成立者，即为问题的解。

* 采用枚举算法解题的基本思路如下：
（1）建立问题的数学模型，确定问题的可能解的集合（可能解的空间）。
（2）逐一枚举可能解集合中的元素，验证是否是问题的解。

使用伪代码可以描述为：
```cpp
for each s in S	//S是问题所有可能解的集合
   if s is a solution then
     begin
        Write(s);
        exit the program;
     end;
```

**例3.1：**

寻找水仙花数

一个三位数其各位数字的立方和等于它本身，这样的数称为水仙花数。要求找出所有的水仙花数

分析：所求一定是三位数，所以范围一定在100-999之间，只要将这些数逐一列举，符合条件者为解

```cpp
For a:=100  to 999 do {
    b:=a mod 10;  //取出个位
    c:=(a div 10) mod 10 //取出十位
    d:＝ a div 100 //取出百位
    if (a=b*b*b+c*c*c+d*d*d) then writeln(a)
}
```

* 分析 :按照枚举算法的思路，首先应该构造可能解的集合：S={(x,y,z)|0≤x,y,z≤100}，其中三元组(x,y,z)表示买公鸡x只，母鸡y只和小鸡z只。因为一共需要买100只鸡，因此，买公鸡、母鸡和小鸡的数量都不会超过100。然后确定验证解的条件：x+y+z=100 and 3x+2y+z/3=100。

* 下面是解这百鸡问题的程序：

```cpp
    Program ex3_1_1;

    Var  x,y,z:integer;

    begin //枚举可能解空间的元素
    for x:=0 to 100 do
        for y:=0 to 100 do
            for z:=0 to 100 do
            if (x+y+z=100) and (x*3+y*2+z　div 3=100) and (z mod 3=0)  then
            	WriteLn(Format('(x,y,z)=(%3d,%3d,%3d)',[x,y,z]));
    end.
```

**程序输出结果为：**
```cpp
(x,y,z)=(  0, 40, 60)
(x,y,z)=(  5, 32, 63)
(x,y,z)=( 10, 24, 66)
(x,y,z)=( 15, 16, 69)
(x,y,z)=( 20,  8, 72)
(x,y,z)=( 25,  0, 75)
```
> 有6种可选的方案。

* 程序需要循环100^3，即|S|=100^3。我们通过条件x+y+z=100来约束求解空间，缩小可能解的集合的规模：
```cpp
Program ex3_1_2;
	　．．．．．．
begin
      //枚举可能解空间的元素
        for (x=0;x<=100;x++)
         for (y=0;y<=100-x;y++) 
	    begin
          z:=100-x-y;
		　if (x+y+z=100) and (x*3+y*2+z div 3=100) and (z mod 3=0) 
             ．．．．．．
	   end;
end.
```

* 程序ex3_1_2的运行结果和程序ex3_1_1相同，但是循环次数为（100*101/2），是程序ex3_1_1循环次数的1/200左右。

* 枚举算法适用范围：
```cpp
简单数值判断题；
简单逻辑判断题；
数据规模不大的问题；
没有想到更好解法的题，可用枚举求出一定范围内的解。
对于枚举算法，程序优化的主要考虑方向是：通过加强约束条件，缩小可能解的集合的规模。
```

## 2 回溯算法

* 所谓的回溯技术就是像人走迷宫一样，先选择一个前进方向尝试，一步步往前试探，在遇到死胡同不能再往前的时候就回退到上一个分叉点，选另一个方向尝试，而在前进和回撤的路上都设置一些标记，以便能正确返回，直到达到目标或者所有的可行方案都已经尝试完为止。
* 在通常的情况下，我们使用递归方式来实现回溯技术，也就是在每一个分叉点进行递归尝试。在回溯时通常采用栈来记录回溯过程，使用栈可使穷举过程能回溯到所要位置，并继续在指定层次上往下穷举所有可能的解。

* 回溯算法可以用伪码描述如下：
```cpp
  Proc Search(当前状态);
  begin
      If  当前状态等于目标状态 then exit;
      for 对所有可能的
          Search(新状态)；
  end;
```

* 回溯算法是一种十分常用的算法，象一些经典问题如八皇后问题、骑士周游问题、地图着色问题都可以采用回溯算法来解。

**例题：**

求马的不同走法总数问题描述：在一个4*5的棋盘上，马的起始位置坐标（纵，横）位置由键盘输入，求马能返回初始位置的所有不同走法的总数(马走过的位置不能重复，马走“日”字)。

**算法分析：**

由于棋盘的大小只有4*5，所以只需使用回溯算法，搜索马能返回初始位置的所有不同走法，效率基本上能达到要求。

* 递归的回溯算法可描述为：

```cpp
 procedure search(now:position); {now是当前位置}
    begin
        for 马从当前位置now出发走一步到位置next的每一种走法 do begin
            if next在棋盘内 and next位置没有走过 then
            	if next=出发点 then 不同走法总数加1
            	else begin
                	标记next已经走过了;
                	search(next);
                	取消位置next的标记;
            end;
        end;
    end;
```

* 棋盘用坐标表示，点P(x,y)表示棋盘上任一个点，x,y的范围是：1<=x<=4，1<=y<=5。
* 从P(x,y)出发，下一步最多有8个位置，记为P1，P2，……,P8，若用k表示这8个方向，则k=1,2,…,8。即马从P点出发，首先沿k=1的方向行进，当在此方向走完所有的不同走法后，就进行回溯，改变k=2方向继续行进……

* 各点坐标的计算。设P点坐标为(x,y)，则能到达点的坐标分别为P1(x+1,y-2)，P2(x+2,y-1)，…，P7(x-2,y-1)，P8(x-1,y-2)。为简化坐标的计算，引入增量数组：
```cpp
direction:array[1..8] of position=
     ((x:1;y:-2),(x:2;y:-1),(x:2;y:1),(x:1;y:2)
	 (x:-1;y:2),(x:-2;y:1),(x:-2;y:-1),(x:-1;y:-2)); 
```

    ![image](https://cloud.githubusercontent.com/assets/7693440/11372699/dad6b358-9309-11e5-8998-91af54ec3e44.png)

则按方向k能到达点的坐标是：
`Pk(x+direction[k].x,y+direction[k].y)。`
程序如下：

```cpp
program ex3_2;

type position=record  x,y:integer; end;

const direction:array[1..8] of position=
       ((x:1;y:-2),(x:2;y:-1),(x:2;y:1),(x:1;y:2),
       (x:-1;y:2),(x:-2;y:1),(x:-2;y:-1),(x:-1;y:-2));

var pass:array [1..4,1..5] of integer;

start:position;
total:integer;

procedure search(now:position); {now是当前位置}
    var i:integer;
    	next:position;
    begin
    	for i:=1 to 8 do begin
    		next.x:=now.x + direction[i].x;
    		next.y:=now.y + direction[i].y;
    		if (next.x>=1) and (next.x<=4) and (next.y>=1) and (next.y <= 5) and (pass[next.x,next.y]=0) then
    			if (next.x=start.x) and (next.y=start.y) then
    				inc(total)
    			else begin
    				pass[next.x,next.y]:=1;
    				search(next);
    				pass[next.x,next.y]:=0;
    			end;
    	end;
    end;
    begin
            total:=0;
            fillchar(pass,sizeof(pass),0);
            write('Start position:');
            readln(start.x,start.y);
            search(start);
            writeln('Total=',total);
            readln;
    end.
```

**作业3.1**
Sicily 1152 简单的马周游问题

* 在一个5 * 6的棋盘中的某个位置有一只马，如果它走29步正好经过除起点外的其他位置各一次，这样一种走法则称马的周游路线，试设计一个算法，从给定的起点出发，找出它的一条周游路线。

* 为了便于表示一个棋盘，我们按照从上到下，从左到右对棋盘的方格编号，如下所示：
```cpp
1	 2	 3	 4	 5	 6
7	 8	 9	 10	11	12
13	14	15	16	17	18
19	20	21	22	23	24
25	26	27	28	29	30
```

* 马的走法是“日”字形路线，例如当马在位置15的时候，它可以到达2、4、7、11、19、23、26和28。但是规定马是不能跳出棋盘外的，例如从位置1只能到达9和14。

* [输入] 标准输入stdin

> 输入有若干行。每行一个整数N(1<=N<=30)，表示马的起点。最后一行用-1表示结束，不用处理。

4
8
15
-1

* [输出] 标准输出 stdout
* 对输入的每一个起点，求一条周游线路。对应地输出一行，有30个整数，从起点开始按顺序给出马每次经过的棋盘方格的编号。相邻的数字用一个空格分开。
* 注意：如果起点和输入给定的不同，重复多次经过同一方格或者有的方格没有被经过，都会被认为是错误的

## 3 贪心算法

* 所谓贪心算法是指：在对问题求解时，总是作出在当前看来是最好的选择。也就是说，不从整体最优上加以考虑，它所做出的仅是在某种意义上的局部最优解。
* 贪心算法不是对所有问题都能得到整体最优解，但对范围相当广泛的许多问题它能产生整体最优解或者是整体最优解的近似解。
* 贪心算法时间复杂度较低，算法较易实现。

* 采用贪心算法的基本思路如下：
（1）建立数学模型来描述问题。
（2）把求解的问题分成若干个子问题。
（3）对每一子问题求解，得到子问题的局部最优解。
（4）把子问题的局部最优解合成原求解问题的一个解。

**例3.3.1：**

无向图的最小生成树问题。

设G=[V,E]是一个无向图，如果T=[V,E]是由G的全部顶点及其一部分边组成的子图，T是树，则称T是G的一个生成树。记L（T）为T的长度，即树T的各边之和。求G的所有生成树中L（T）最小的生成树。

图3.3.1无向图G及其生成树：
下面的两棵树都是图G的生成树，其中T2是所有图G的最小的生成树。

![image](https://cloud.githubusercontent.com/assets/7693440/11490466/ecd10fb8-9813-11e5-9073-f139315b6fca.png)

* 最小生成树的算法思路是：由于n个顶点的图，其最小生成树共有n-1条边，因此寻找最小生成树的问题就是选这n-1条边的过程，我们可以把这个过程分解为n-1次的选择，每次选择都选一条边。在每次选边的时候，我们采用贪心的原则：选择一条权值最小而未被选过，且和已选定的边不会构成圈的边。

```cpp
最小生成树的算法如下：
    T=空;
      for i:=1 to n-1 do
    begin
        寻找在图G中选取权值最小，不在T中，
		而且与T中的边不构成圈的边ei;
         把ei加入T中;
    end;
 T就是图G的最小生成树。
```

最小生成树程序实现如下：
```cpp
program ex3_3_1;
var F:Text;
	N,M,i,j:Integer; 	//图G的点数N和边数M
	Selected:Array [1..100] of Integer; //对已选择的边ei,Selected[i]为1,否则为0
	E:Array [1..100,1..2] of Integer;		 //边的起点和终点
	Value:Array [1..100] of Integer; 	//边的权值
	T:Array [1..100] of Integer; //若Vi是生成中的结点,T[i]=1,否则为0
	Min,MinE,ValueT:Integer; //分别是当前选边的权值、选边的编号和树的长度
begin
    //读入图G，图G采用边目录表示法。
    Assign(F,'ex3_3_1.in');
    Reset(F);
    ReadLn(F,N,M);
    for i:=1 to M do ReadLn(F,E[i,1],E[i,2],Value[i]);

    //初始化
    fillchar(Selected,sizeof(Selected),0);
    fillchar(T,sizeof(T),0);
    ValueT:=0;

	//n-1次选边过程
	for i:=1 to N-1 do
        begin
            Min:=Maxint;
            MinE:=0;
            for j:=1 to m do
            	//未被选中
            	if Selected[j]=0 then
            		//不构成圈
           			if ((T[E[j,1]]=0) xor (T[E[j,2]]=0)) or (i=1) then
						//权值最小
                		if Value[j]<Min then begin
                        	Min:=Value[j];
                        	MinE:=j;
                		end;
                		//做选中的标记
                		Selected[MinE]:=1;
                		T[E[MinE,1]]:=1;
                		T[E[MinE,2]]:=1;
                		ValueT:=ValueT+Min;
        end;
    WriteLn('T:','':10,'Length=',ValueT);
    for i:=1 to m do
        if Selected[i]=1 then begin
            WriteLn('(',E[i,1],',',E[i,2],')');
        end;
    Close(F);
    ReadLn;
end.
```

测试数据如下（即例子中的图）：
```cpp
	6 7
	1 2 3
	1 6 2
	2 3 5
	2 5 2
	3 4 1
	4 5 4
	5 6 1
```
程序运行结果如下：
```cpp
	T:          Length=10
	(1,6)
	(2,5)
	(3,4)
	(4,5)
	(5,6)
```

* 贪心算法适用范围：
	* 整个问题求解过程有明显阶段性。经一次贪心后原问题变成相似的但规模更小的问题；
	* 最优性：即一个最优解的子集也是相应子问题的最优解。

## 4 递归和分治算法

* 递归是一种重要的思想，如果一个问题可以转化成一个结构相同、规模更小的问题，则用递归来解决。
* 递归典型例子：Hanoi Tower问题（见第一章）
* 分治算法，是指将一个规模较大的问题分解为若干个规模较小的部分（这些小问题的难度应该比原问题小），求出各部分的解，然后再把各部分的解组合成整个问题的解。

**基本思路：**
（1）对求解建立数学模型和问题规模描述。
（2）建立把一个规模较大的问题划分为规模较小问题的途径。
（3）定义可以立即解决（规模最小）的问题的解决方法。
（4）建立把若干个小问题的解合成大问题的方法。

**例3.4.1：**

求正整数集合（a1,a2,...,an）的最大值和最小值。

建立数学模型和问题规模的描述：题目本身有很强的数学背景，数学模型应该是该问题的一般数学解释。我们可以定义问题（f，t）表示求集合（af,af+1,...,at）中的最大值和最小值。我们需要解决的问题是（1，n）

* 当需要求解问题（f，t）（共t-f+1个元素），我们可以把这个集合（af,af+1,...,at）分成两半，即设m=f+(f-t)/2，集合分为（af,...,am）和（am+1,...,at）两个集合;
* 这两个集合中只含有(f-t)/2或者(f-t)/2+1个元素。
* 将问题（f，t）划分成两个规模较小的问题（f，m）和（m+1，t）。

* 显然，当集合中只有一个元素时，问题立刻有解，集合的最大值和最小值都是集合中唯一的元素。
* 建立把若干个小问题的解合成大问题的方法
	* 问题（f，m）的最大值和问题（m+1，t）的最大值中的大者就是问题（f，t）的最大值；
	* 问题（f，m）的最小值和问题（m+1，t）的最小值中的小者就是问题（f，t）的最小值。

**主要算法描述:**

```cpp
program ex3_4_1;

var
	a:array [1..10000] of Integer;

procedure MaxMin(f,t:Integer;var rMax,rMin:Integer);
    var
        m:Integer;
        Max1,Max2,Min1,Min2:Integer;
    begin
        if f=t then begin
            rMax:=a[f];
            rMin:=a[t];
        end
        else begin
            m:=(t-f) div 2 + f;
            MaxMin(f,m,Max1,Min1);
            MaxMin(m+1,t,Max2,Min2);
            rMax:=Max(Max1,Max2);
            rMin:=Min(Min1,Min2);
        end;
    end;

var Fin:Text;
var i,n,rMax,rMin:Integer;

begin
    Assign(Fin,'ex2_5_1.txt');
    Reset(Fin);
    ReadLn(Fin,n);
    For i:=1 to n do Read(Fin,a[I]);
    Close(Fin);
    MaxMin(1,n,rMax,rMin);
    WriteLn(Format('Max=%d,Min=%d',[rMax,rMin]));
    Readln;
end.
```

**ex_3_4_1.txt测试用例：**
```cpp
7
2 34 32 19 1 39 4
```
**程序运行结果如下：**
```cpp
Max=39,Min=1
```

## 5 数值计算

**3.5.1 精度计算**

计算机精确计算的范围是有限的，例如,整型的精确度为Int64时，值域是[-2^63－2^63-1]如果需要精度更高的计算，就需要编程实现。在本节中，主要介绍正整数的高精度计算（加，减，乘和除），至于整数，有理数乃至实数的高精度运算，这一部分所介绍的方法和技巧还是很有参考价值的。

* 正整数高精度加法
* 加法和减法都是最基本的运算，乘除法运算是建立在加减法之上的。

### 5.1 加法算法

![image](https://cloud.githubusercontent.com/assets/7693440/11490708/584e0da2-9816-11e5-8fe0-88deaa177e6e.png)

### 5.2 正整数高精度减法

减法和加法的最大区别在于：减法是从高位开始相减，而加法是从低位开始相加。
减法算法如下：

![image](https://cloud.githubusercontent.com/assets/7693440/11490724/7bac77ca-9816-11e5-9145-08c779777af0.png)

### 5.3 正整数高精度乘法

乘法的主要思想是把乘法转化为加法进行运算。请先看下面的等式：

```cpp
12345 * 4 = 12345 + 12345 + 12345 + 12345
12345 * 20 = 123450 * 2
12345 * 24 = 12345 * 20 + 12345 * 4
```

* 等式（1）说明，多位数乘一位数，可以直接使用加法完成。
* 等式（2）说明，多位数乘形如d*10n的数，可以转换成多位数乘一位数来处理。
* 等式（3）说明，多位数乘多位数，可以转换为若干个“多位数乘形如d*10n的数与多位数乘一位数”之和。
* 因此，多位数乘多位数最终可以全部用加法来实现。

**算法描述如下：**
```cpp
function multiply(s1,s2:string):string;
    var i:Integer;
        C:Char;
    begin
        Result:='0';
        //多位数乘多位数，可以转换为若干个“多位数乘形如d*10n的数与多位数乘一位数”之和
        for i:=Length(s2) down to 1 do begin
            //多位数乘一位数，可以直接相加
            for C:='1' to S2[i] do
            Result:=addition(Result,S1);
    		//多位数乘形如d*10n的数转换成多位数乘一位数来处理
            S1:=S1+'0';
        end;
		Result:=Clear(Result);
		multiply:=Result;
	end;
```
** 例如12*12，算法执行过程如下（多位数乘一位数看成是一步完成）**

![image](https://cloud.githubusercontent.com/assets/7693440/11490855/8e736336-9817-11e5-8d5f-99510cca9397.png)

### 5.4 正整数高精度除法

* 高精度除法是基于精度减法的，主要的思想是“试商”，模仿笔算除法的方法。

**算法描述如下：**

```cpp
function division(s1,s2:string):string;
    begin
        //Result中存放的是商
        Result:='';
        //S中存放的是余数，S1是被除数，S2是除数
        S:='';
        //逐位试商
        for i:=1 to Length(S1) do begin
        	S:=S+S1[i];
    		//先试商0
        	Result:=Result+'0';
        	//然后从1开始不断往上试
            While Bigger(S,S2) do begin
                Inc(Result[Length(Result)]);
                S:=Subtraction(S,S2);
            end;
        end;
        //删除多余的0
        Result:=Clear(Result);
        division:=Result;
    end;
```

* 例如，144/12算法执行如下：

![image](https://cloud.githubusercontent.com/assets/7693440/11490894/f0faca3a-9817-11e5-96d2-63ea9e759aa3.png)
![image](https://cloud.githubusercontent.com/assets/7693440/11490935/41c91250-9818-11e5-87d8-3093041d2def.png)

### 5.5 实现正整数高精度运算

```cpp
program ex3_5_1;
//清除整数前面多余的0
function clear(s:string):string;
    begin
        if s='' then s:='0';
        while (length(s)>0) and (s[1]='0') do delete(s,1,1);
        if s='' then s:='0';
        clear:=s;
    end;

//比较两个数的大小，如果S1>=S2，结果返回为真。
function bigger(s1,s2:string):boolean;
    begin
        bigger:=true;
        if length(s1)>length(s2) then exit;
        if (length(s1)=length(s2)) and (s1>=s2) then exit;
        bigger:=false;
    end;

//加法
function addition(s1,s2:string):string;
    var i:integer;
    begin
        //对位
        while Length(S1)<Length(S2) do S1:='0'+S1;
        while Length(S2)<Length(S1) do S2:='0'+S2;
       //考虑到首位可能进位，在首位中增加一个0
        S1:='0'+S1;S2:='0'+S2;

        for i:=Length(S1) down to 1 do begin
            //逐位相加
            S1[i]= S1[i]+ S2[i];
            //处理进位
            if S1[i]>'9' then begin
            	S1[i]= S1[i]-10;
            	S1[i-1]= S1[i-1]+1;
            end;
        end;

        Result:=Clear(S1);addition:=Result;
    end;

//减法
//这里假设S1>=S2，如果不满足这个条件，
//函数返回结果不正确
function Subtraction(s1,s2:string):string;
    var i:integer;
    begin
    //对位
    while Length(S1)<Length(S2) do S1:='0'+S1;
    while Length(S2)<Length(S1) do S2:='0'+S2;
    //逐位相减,从高位开始减
	        For i:=1 to Length(S1) do
	        If S1[i]>=S2[i] then S1[i]= S1[i]-S2[i])
	        else        //有借位的情况
	        begin
	                S1[i]= S1[i]+10 -S2[i];
	                S1[i-1]= S1[i-1]-1;
	        end;
	        Result:=Clear(S1);Subtraction:=Result;
	end;

//乘法
function multiply(s1,s2:string):string;
    var i:Integer;C:Char;
    begin
        Result:='0';
        for i:=Length(s2) downto 1 do
        begin
            for C:='1' to S2[i] do
            Result:=addition(Result,S1);
            S1:=S1+'0';
        end;
        Result:=Clear(Result);
        multiply:=Result;
    end;
//除法
//这里假设除数不为0，如果除数为0，函数进入死循环。
function division(s1,s2:string):string;
    var i:integer;
        s:String;
    begin
        Result:='';
        S:='';
        for i:=1 to Length(S1) do begin
            S:=S+S1[i];
            Result:=Result+'0';
            While Bigger(S,S2) do begin
                Result[Length(Result)]=Result[Length(Result)]+1;
                S:=Subtraction(S,S2);
       		end;
		end;

        Result:=Clear(Result);division:=Result;
	end;

begin
    WriteLn(Addition('999','1'));
    WriteLn(Subtraction('890','99'));
    WriteLn(Multiply('99','99'));
    WriteLn(Division('9899','99'));
    ReadLn;
end.
```

**程序运行结果：**
```cpp
	1000
	791
	9801
	99
```

* 特别说明，上面的程序中的减法和除法没有判断是否够减和除数为0，如果对于一般问题，调用减法和除法之前应该做检查，如下例所示：
```cpp
	//判断够减（结果不出现负数）
	if Bigger(s1,s2) then Result:=Subtraction(s1,s2);
	//判断除数不为0
	if Clear(s2)<>’0’ then Result:=Division(s1,s2);
```
### 5.6 线性方程组

**3.5.2 求解线性方程组**

* 解线性方程组是一类常用的基础问题。例如，在计算几何中，需要求直线的交点，在列出直线方程后，就直接转化为解线性方程组问题了；又如线性规划问题，解线性方程组也是其中的一个基础子问题。

* 解线性方程组的方法很多，例如Gauss消元法，LU法，求逆阵法，Gauss-Seidel(迭代)法等等，其中Gauss消元法需要的数学背景知识最少，而且比较容易实现，下面主要介绍使用Gauss消元法求解线性方程组问题。

**下面简单介绍一下关于线性方程组的一些背景知识：**

* a1x1+...+anxn=b线性方程式(Linearequation)，其中a1,...,an为系数，x1,...,xn为未知数或变量(unknowns)，b为常数。

* n元m次联立方程式：
![image](https://cloud.githubusercontent.com/assets/7693440/11491087/9294a540-9819-11e5-96f2-3a9768f49280.png)

* 上式有m个方程式及n个未知元所形成的线性方程組。
![image](https://cloud.githubusercontent.com/assets/7693440/11491102/b8e92bda-9819-11e5-8058-892d362d12bf.png)

* 系数矩阵
![image](https://cloud.githubusercontent.com/assets/7693440/11491106/c8cb9cfe-9819-11e5-8081-6a01e75761b9.png)

* 未知向量
![image](https://cloud.githubusercontent.com/assets/7693440/11491108/dc9c476a-9819-11e5-88a8-58301deb430c.png)

* 常数向量
![image](https://cloud.githubusercontent.com/assets/7693440/11491112/e83bb79a-9819-11e5-9164-4aea4f3c7c63.png)

**增广的形式**

![image](https://cloud.githubusercontent.com/assets/7693440/11491129/0f72abfc-981a-11e5-9ec6-74fec041e0e2.png)

**Gauss消元法**

主要是基于增广矩阵的变换。算法如下：

* 设所有行都为“未处理行”，然后从第1列到第n列依次扫描矩阵a。
* 当扫描到第k列时，在矩阵a所有未处理过的行中找出第k列中的最大值，和最大值所在行p。
* 如果最大值为0，说明方程组无解或者有无穷多组解。否则，继续下面操作。
* 设置行p为已处理行，同时对其他的每一行，找到一个适当的数，然后把行p乘以这个适当的数加到该行中，使得通过上述变换后，该行第k列的元素为0。显然，对第i行，这个适当的数为-a[i,k]/a[p,k]。
* 经过上面的从第1列到第n列的扫描后，矩阵a中每行仅又一个非0值，记第i行的非0值为a[i,j]，则有x[j]:=b[i]/a[i,j]。

**算法举例：**

求解方程：

![image](https://cloud.githubusercontent.com/assets/7693440/11491166/4ddc0af0-981a-11e5-88d3-f417f5007ce8.png)

* 在第1列中，最大值为a[2,1]，把第2行乘以-1/3后加到第一行，同时把第2行乘以-2/3后加到第三行;
```cpp
0.00    2.33    2.00 |    3.33
3.00   -1.00   -3.00 |   -1.00
0.00    3.67    3.00 |    4.67
```

* 在第2列中，最大值为a[3,2]，把第3行乘以-2.33/3.67后加到第一行，同时把第3行乘以1/3.67后加到第二行
```cpp
0.00    0.00    0.09 |    0.36
3.00    0.00   -2.18 |    0.27
0.00    3.67    3.00 |    4.67
```

* 在第3列中，最大值为a[1,3]（因为此时未处理行只有第一行），类似上面的做法处理。
```cpp
0.00    0.00    0.09 |    0.36
3.00    0.00    0.00 |    9.00
0.00    3.67    0.00 |   -7.33
```

**最后的结果为：**
```cpp
x[1]= 3.000000    x[2]=-2.000000    x[3]=4.000000
```

**实现Gauss消元法算法描述如下：**
```cpp
program ex3_5_2;

//定义一维向量和二维向量
const
    maxn=100;
type
    tmatrix=array[1..maxn,1..maxn] of real;
    tvector=array[1..maxn] of real;
begin
    fillchar(q,sizeof(q),0);
    for k:=1 to n do begin
  		//选出第k列中，绝对值最大值对应的（p）
        p:=0;max:=0;
        for i:=1 to n do
        	if (q[i]=0) and (max+1e-10<abs(a[i,k])) then begin
	            max:=abs(a[i,k]);
	            p:=i;
	        end;

	        //如果绝对值最大为0，说明方程组无解或者有无穷多组解。
        	if p=0 then begin
	            Result:=False;
	            exit;
	        end
	 		//做上处理过的标记
	        else q[p]:=1;

            //把p行乘上一个适当的系数后加到其他行上，使第k列中只有一个非0值
	        for i:=1 to n do if i<>p then begin
	            l:=a[i,k]/a[p,k];
	            for j:=1 to n do a[i,j]:=a[i,j]-l*a[p,j];
	            b[i]:=b[i]-l*b[p];
	        end;
	end;
		//求解x
    for i:=1 to n do for j:=1 to n do
    	if abs(a[i,j])>1e-10 then x[j]:=b[i]/a[i,j];
	    Result:=True;
end;
```

## 6 计算几何

* 计算几何是计算机科学中新的分支，它的形成和发展与计算机图形学、超大规模集成电路设计、计算机辅助设计和机器人等学科的发展都有密切的联系。

**3.6.1 线段问题**

* 两条线段的交点问题
* 关于平面上的线段的若干性质。

已知A（x1，y1）和B（x2，y2）是平面上任意两点，则线段AB上的任意一点P（x，y），存在实数a(0≤a≤1)，满足：
`x=ax1+(1-a)x2，y=ay1+(1-a)y2`

![image](https://cloud.githubusercontent.com/assets/7693440/11491294/8d9252de-981b-11e5-93f2-1ffa5ef1eef2.png)

* 下面就正式转入如何判断两条线段AB和CD是否相交和求线段的交点。
* 假设AB和CD交于P点，那么下面的方程组：
```cpp
x=d1xA+(1-d1)xB
y=d1yA+(1-d1)yB
x=d2xC+(1-d2)xD
y=d2yC+(1-d2)yD
```
* 如果线段相交当且仅当方程组有解，而且0≤d1,d2≤1。接下来的工作就是解上面的四元齐次方程组了（解方程组的算法可以参考上节“求解线性方程组”部分，当然也可以手工先求解方程组）。

**程序如下：**

```cpp
program ex3_6_1;
type TPoint=record x,y:real end;
//by rei
//判断线段[s1,e1]和[s2,e2]是否相交
//Input: 线段[s1,e1]和[s2,e2]
//Output: Intersect = false 线段[s1,e1]和[s2,e2]不相交
// true  线段[s1,e1]和[s2,e2]相交，交点用全局参数d1,d2给出
// 交点坐标(x,y)的计算: x=s1.x+d1*(s2.x-s1.x)
// y=s1.y+d1*(s2.y-s1.y) 
program ex3_6_1;
	type TPoint=record x,y:real end;
	//by rei
	//判断线段[s1,e1]和[s2,e2]是否相交
	//Input: 线段[s1,e1]和[s2,e2]
	//Output: Intersect = false 线段[s1,e1]和[s2,e2]不相交
	// true  线段[s1,e1]和[s2,e2]相交，交点用全局参数d1,d2给出
	// 交点坐标(x,y)的计算: x=s1.x+d1*(s2.x-s1.x)
	// y=s1.y+d1*(s2.y-s1.y) 
if Same(a1*b2,a2*b1) then exit;
  d1:=(c1*b2-c2*b1)/(a1*b2-a2*b1);
  d2:=(c1*a2-c2*a1)/(b1*a2-b2*a1);
  Intersect:=true;
end;
```

**2.8.2 凸包问题**

* 设平面上有一点集S，存在一最小的凸多边形P，使得S中的每一点或在P的边界上或是P的内点。这个多边形P便称为S的凸包。

**下面介绍Grabam扫描法求解凸包问题。**

* Graham扫描法是从凸包的一个角点开始，通常选取Pi(xi,yi)(i=1,2,...,n)中yi达到最小的点。不失一般性，令这一点为P1(x1,y1)，而且使得闭n边形P1P2...PnP1满足P1Pi的线段和x轴正向的夹角是一单调递增序列，上面的要求可以通过对倾斜角的排序来实现。
* 然后依次多边形中的顶点，删去不必要的顶点，使得最后留下来的是所求的凸包。
* 什么是不必要的点呢？如下图所示:
	* P4点是一个不必要的点，因为P5P4到P4P1是顺时针的，而其他都是逆时针的。
![image](https://cloud.githubusercontent.com/assets/7693440/11491389/5eb24f68-981c-11e5-9e68-d9f976bf7167.png)

**Graham扫描法算法描述如下：**

* 对点集进行重新排序，满足，P1的y座标最小，而且PiP1的对x轴正向的夹角是单调递增的。
* 把前3个点压入堆栈中。

**实现Graham扫描法的程序如下：**
```cpp
program ex3_6_2;
// by splutter
// 扫描法求凸包
// Input: List=点集数组 Len=点的总数
// Output: List=以逆时针方向给出的凸多边形顶点数组 Len=顶点数目

{$apptype console}
uses sysutils;

const
	maxn=1000;
	type
		tpoint=record
    	x,y:integer
	end;

tarrpoint=array[1..maxn] of tpoint;

var
	top:integer;
	stack:array[1..maxn] of integer;
	//求线段内积，从而可以判断顺时针或者逆时针

function multi(var p1,p2,p0:tpoint):integer;
	begin
	  multi:=(p1.x-p0.x)*(p2.y-p0.y)-(p2.x-p0.x)*(p1.y-p0.y);
	end;

//交换两个点
procedure swap(var a,b:TPoint);
	var
	  t:tpoint;
	begin
	  t:=a; a:=b; b:=t
	end;

procedure scan(var list:tarrpoint; var len:integer);
	//比较两个点的位置关系
	function comp(var p1,p2:tpoint):boolean;
	  var
	    t:integer;
	  begin
	    t:=multi(p1,p2,list[1]);
	    comp:=(t>0) or ((t=0) and ( sqr(p1.x-list[1].x) +sqr(p1.y-list[1].y) <sqr(p2.x-list[1].x) +sqr(p2.y-list[1].y)));
	  end;

//排序（快速排序）
procedure sort(p,r:integer);
	var
		i,j:integer;
    	x:tpoint;
	begin
		if r-p+1<5 then begin
			for j:=p+1 to r do begin
	        	i:=j;
	        	while (i>1) and (comp(list[i],list[i-1])) do begin
	          		swap(list[i],list[i-1]);
                	dec(i);
				end;
     		end;
		end
        else begin
			x:=list[p+random(r-p+1)];
            i:=p;j:=r;
			repeat
	        	while comp(list[i],x) do inc(i);
	        	while comp(x,list[j]) do dec(j);
            	if i<j then swap(list[i],list[j]);
			until i>=j;
			sort(p,j);
			sort(j+1,r);
		end;
	end;

var
	i:integer;
	t:tarrpoint;
begin
	//(1)对点集重新排序
	for i:=1 to len do begin
		if (list[i].y<list[1].y) or ((list[i].y=list[1].y) and (list[i].x<list[1].x)) then
        swap(List[1],List[i]);
	end;

	sort(2,len);
	//(2)把前3个点压入堆栈中
	for i:=1 to 3 do stack[i]:=i;
	top:=3;
	//(3)对点Pi(i>3)依次检查。
	for i:=4 to len do begin
	//弹出不必要的点
		while multi(list[i],list[stack[top]],list[stack[top-1]])>0 do dec(top);
		//inc(top);
	    //(4)把Pi压入栈中
	    stack[top]:=i;
	end;
	//(5)最后留在栈中的点就是凸包的顶点
	t:=list;
	for i:=1 to top do list[i]:=t[stack[i]];
	len:=top;
end;
```

## 7 模拟题解法

* 模拟题是从实际工程应用中提取出来的一些核心问题，或者本身就是某个工程的简化模型。解答模拟题特别需要有良好的理解能力、分析能力和规划能力。模拟题的算法一般都不太复杂，关键是所有条件都不能遗漏并要把条件分析清楚，求解模拟题一般都比较繁，编程前一定要预先规划好各个模块的功能和结构，以免具体编程时注意了局部而遗漏了某些重要的方面。
* 解答模拟题通常的步骤可以是：
	* 认真仔细地读懂题目。模拟题的描述通常都比较详细，篇幅一般都比较长，你应该边阅读边将有关的条件一条条地记录下来，阅读完后要反复核对，绝对不能有错漏；
	* 建立各个条件之间的关系，最好用一些简明的表格列出，例如，可以用下表建立各项条件之间的关系
![image](https://cloud.githubusercontent.com/assets/7693440/11491441/cd9b9498-981c-11e5-9fbf-915c9b498c8b.png)

* 认真分析这些关系，并建立这些关系的数学模型；
* 规划各个模块的结构，用相应的语言采用逐步求精的方法描述具体的算法；
* 用你所熟悉的程序设计语言编写程序，调试并运行；
* 检查题目给出的样例能否通过。ACM/ICPC这类竞赛题目中都会给出输入输出样例，让你检查程序的输入输出格式是否正确，但这些样例往往会比竞赛时评判所用的测试数据简单，所以你一定不能满足通过这些样例，还要自拟更复杂、更全面的测试数据来检查程序的正确性。经过反复的调试、检查，才算完成该题。

## 8 作业

```cpp
1152    简单的马周游问题
1153    马周游问题,要求写解题报告
1093	枚举
1134	贪心:从小到大排序
1140	贪心:砍不大于n/2个节点的最大树枝
1438	排序，隔三求和
1028	梵塔问题 -> 分治，归纳 -> 题目有意思但要留意其数据规模较大
1029	递推高精度加法
1381	a*b 高精度
1152    简单的马周游问题
1153    马周游问题,要求写解题报告
1093	枚举
1134	贪心:从小到大排序
1140	贪心:砍不大于n/2个节点的最大树枝
1438	排序，隔三求和
1028	梵塔问题 -> 分治，归纳 -> 题目有意思但要留意其数据规模较大
1029	递推高精度加法
1381	a*b 高精度
1003	模拟题
1018	模拟题
1052	简单模拟题
1041	中等模拟题
1211	分治，求两点间L步到达的方法数
1071	分治
1082	数据结构题
```
