# 第二章 算法设计中常用到的数据结构

## 1 数组与下标

* 规律：当被处理对象之间符合线性表特征时使用顺序表，（数组）存储线性表元素时，对数据元素的加工处理算法，很大程度取决于数据元素的下标变化规律

**例2.1**

输入一串字符，以”?”结束,统计其中每个字符出现的次数.

1. 考虑数据结构:用一维数组存放每个字母出现的次数,定义一个由26个字母组成的数组：
    `Num:array[‘a’..’z’]of integer`
    * 用Num [‘a’]记录字母a出现次数，……
    * 用Num [‘z’]记录字母z出现次数;

2. 算法：
```cpp
    1）将数组元素清0；
    2）读入第1个字符；
    3）WHILE 读入字符不等于‘？’ DO
    BEGIN
      4）IF ch 是字母 THEN
      	相应字母计数加1
      5）读入下一个字符
    END
    6）输出每个字母出现的次数。
```

3. 要求上机编程，用C++完成上述程序，并自行在机上运行，检测程序的正确性。
4. 将题目改成从文件读入，输出到文件中。要求有5组测试数据，文件输入：
    1）第一组：10个字符；
    2）第二组：100个字符；
    3）第三组：1000个字符；
    4）第四组：10000个字符；
    5）第五组：10万个字符；
    数据随机产生。
    自行完成，不用交。

**例2.2 **

倒蛇阵填数，任给一个正整数n(n<=20)，将1-n^2^分别填入矩阵，在显示器上输出如下格式的矩阵

![image](https://cloud.githubusercontent.com/assets/7693440/11368110/c63c64a4-92f2-11e5-9cec-dc09144679e8.png)

* 关键问题：线性表元素值与下标i,j之间的关系
* 算法设计：每圈四条边，顺序为右上->右下，右下->左下，左下->左上，左上->右上
* 第1圈四边
```cpp
    A[1,n]->A[n,n]，
    A[n,n-1]->A[n,1]，
    A[n-1,1]->A[1,1],
    A[1,2]->A[1,n-1]

    第i圈四边
    A[i,n+1-i]->A[n+1-i,n+1-i]，
    A[n+1-i,n-i]->A[n+1-i,i]，
    A[n-i,i]->A[i,i],
    A[i,i+1]->A[i,n-i]
```
```cpp
    i=1开始赋值
    当i<n+1-i，构成圈
    当i>n+1-i，结束
    i=n+1-i则A[i，i]=n2结束(最后填入的元素位)
    如n=4，
    i=1，n+1-i=4，为第一圈
    i=2，n+1-i=3，为第二圈
    i=3，n+1-i=2，A[2，2]=n2=16结束
```

**算法描述**
```cpp
R:=1;
i:=1;

While i<(n+1-i) do begin
	for j:=i to n+1-i do begin
    	a[j,n+1-i]:=R;
		R:=R+1;
	end;
    
    for j:=n-i downto i do begin
    	a[n+1-i,j]:=R;
    	R:=R+1;
    end;
    
    for j:=n-i downto i do begin
    	a[j,i]:=R;
    	R:=R+1;
    end;
    
    for j:=i+1 to n-i do begin
    	a[i,j]:=R;
    	R:=R+1;
    end;
	i:=i+1;
end; //end of while

If (i=n+1-i) then a[i,i]:=R;
```

## 2 栈与回溯

* 栈：线性表（加了后进先出的限制）
* 穷举时用栈回溯过程，如穷举时无法找到所需，则退回继续穷举
* 使用栈能使穷举过程能回溯到所要位置继续在所在层次上往下穷举所有可能的解（穷举也常被称为搜索，遍历）。

**例2.3**

求从A到B可能的道路

![image](https://cloud.githubusercontent.com/assets/7693440/11368315/1736916c-92f4-11e5-878f-d0ec238e9c30.png)

**例2.4**

N皇后问题N*N棋盘上，N个皇后不能在同行，同列及同一个对角线上

![image](https://cloud.githubusercontent.com/assets/7693440/11368338/364b34ea-92f4-11e5-92d7-5ad4165d3d23.png)

![image](https://cloud.githubusercontent.com/assets/7693440/11368352/4caf4b4a-92f4-11e5-9195-8557e0b8f704.png)

![image](https://cloud.githubusercontent.com/assets/7693440/11368363/5e516f72-92f4-11e5-8868-1fc071a04699.png)

* 第k个皇后的安置（x[k]的值），需x[k]与x[i]（i=1,2,..,k-1）的人一个都不在同一列，同一对角线上，这一判定工作可模块化为一个布尔型函数，其值为TRUE表示可安置。
```cpp
    Function PLACE(k:1..n):boolean; //参数为行号
    Begin
        i:=1;
        While (n<k) do begin
            if (x[i]=x[k]) {第k个皇后与第i个皇后同一列} or (abs(x[i]-x[k])=abs(i-k)) { 在同一个对角线上} then begin 
                PLACE:=false; exit;
            end;
            i:=i+1;
        end;
        PLACE:=true;
    end;
```

* 求解n皇后安置方案算法：
```cpp
    L:=1; // 解编号
    X[1]:=0; // 每次穷举取下一列进行
    k:=1;     // 从第1行开始

    While (k>0) do begin // 行号>0 回溯
    	x[k]:=x[k]+1;   // 穷举第k行皇后位置
    	while (x[k]<=n) and (not PLACE(k)) do
    		x[k]:=x[k+1];             // 穷举皇后位置
    		if (x[k]<=n) then
    			if (k=n) then begin
    				for j:=0 to n do write(x[j],’ ‘); // 输出所有位置
    				writeln(‘Result No.=‘,L);       // 输出组号
    				L:=L+1;
    			end
                else begin
                    k:=k+1;
                    x[k]:=0;
                end { if k=n}
    		else // 回溯到上一个皇后穷举
    			k:=k-1;
    End; { while k>0}
    Writeln(‘Program end.’);
```

## 3 队列与搜索

* 队列是线性表的特殊情况，线性表+先进先出(FIFO)的限制=队列
* 队列有头尾指针，用数组存放队列，队列应用归结为数组下标的活用

![image](https://cloud.githubusercontent.com/assets/7693440/11368816/bdfb8aa0-92f6-11e5-852a-41bb7bf8b6d7.png)

![image](https://cloud.githubusercontent.com/assets/7693440/11368840/dbcc03a2-92f6-11e5-8ab0-6292da2c0ee8.png)

![image](https://cloud.githubusercontent.com/assets/7693440/11368854/f97783ea-92f6-11e5-944d-189b2ebe067c.png)

![image](https://cloud.githubusercontent.com/assets/7693440/11368894/24c66b92-92f7-11e5-91ee-747f23c50a25.png)

![image](https://cloud.githubusercontent.com/assets/7693440/11368949/721516a0-92f7-11e5-91ae-1a07def1a570.png)

![image](https://cloud.githubusercontent.com/assets/7693440/11368958/82b75ec8-92f7-11e5-8742-005683254330.png)

![image](https://cloud.githubusercontent.com/assets/7693440/11368972/91fa265e-92f7-11e5-8bb0-fd1aebf6af31.png)

**4.重复上述过程直到队列的x，y值与目标态相同**
**5.寻找到目标态后，根据Pre值进行回溯获从初态到目标态最短操作序列。**

```cpp
变量及过程设置
qm队列，fp、rp队列头尾指针，sop栈，用于记录回溯步骤，Flag为True时表示未达目标态
五个过程 
OPA：对Fp指示结点状态进行A操作
OPB：对Fp指示结点状态进行B操作
OPC：对Fp指示结点状态进行C操作
Comp：判操作结果是否在队列出现过，如未，完成将结果入队的操作
Printop：完成对队列回溯并顺序记录操作序列
```

```cpp
Const max=8100;

Type qt=record
    x,y:integer;
    op:char;
    pre:integer;
end;

Var
    …,m,n,fp,rp:integer;
    qm:array[1..max] of qt;
    sop:array[1..300] of char;
	flag:boolean;

A、B、C操作的数学方法:

A操作（结果存入m，n变量中）
	m:=qm[fp].y; n=qm[fp].x;
B操作
	m:=(qm[fp].x mod 10) *1000+(qm[fp].x div 10)
   n:=(qm[fp].y mod 10) *1000+(qm[fp].y div 10)
C操作：
    i:=(qm[fp].x div 1000)*1000;
    j:=qm[fp].x-i; a:=j div 100;
    b:=(j-a*100)div 10;
    i1:=(qm[fp].y div 1000)*1000；
    j1:=qm[fp].y-i1;
    c:=j1 div 100;
    d:=(j1-c*100)div 10;
    m:=i+c*100+a*10+(qm[fp].x mod 10);
    n:=i1+d*100+b*10+(qm[fp].y mod 10);
```

* 执行A、B、C操作，qm[fp]状态都可能会达目标态，故OPA，OPB，OPC过程调用必须Flag=True才继续执行

**Printop过程算法：**
```cpp
Begin
    j:=1;
    i:=qm[rp].pre;
    sop[j]:=qm[rp].op;
    while (i<>0) do begin
    	j:=j+1;
    	sop[j]:=qm[i].op;
    	i:=qm[i].pre;
    end;
    write(‘Command=‘,j-1);
    for i:=j down to 1 do write(sop[i]:2);
End;
```

**Comp过程算法**
```cpp
Begin
    fp:=True;
    for i:=1 to rp do
    if (m=qm[i].x) and (n=qm[i].y)
     then fp:=False;
    if fg then
    begin
      rp:=rp+1;
      qm[rp].x:=m;qm[rp].y:=n;
      qm[rp].op:=opx;qm[rp].pre:=fp;
      writeln(‘rp=‘,rp);
      if (m=k) and (n=L)  then flag:=false;
    End;
End;
```

**本算法过程：**

充分利用队列特性来记录供回溯用的信息，采用A、B、C操作，由队列尾指针控制入队，由队列头指针控制向前搜索过程。

## 4 链表

* 例如当我们用数组来存储时，数据之间相互关连可归纳为处理数组下标的关系
* 我们学过的排序算法如：冒泡排序，选择排序，快速排序等都是运用对有存储数据的位置进行各次交换来实现
* 能够不用交换数据位置的办法来达到排序的目的，通常采用指针的方法来实现

![image](https://cloud.githubusercontent.com/assets/7693440/11369629/f5c5258c-92fa-11e5-82a6-3424d40d2273.png)

**程序**

```cpp
Program e05;
Type link=^node;
node=record
    data:integer;
    next:link;
end;
Var  p:link; 
    n:integer;

Procedure sortp(nx:integer)
Var
    q,r:link;
Begin
     q:=p;
    while q^.data<nx do
   begin
      q:=q^next;
   end;
   new(r); r^:=q^; q^.data:=nx;q^.next:=r;
End;

Procedure list;
Var
   q:link;
Begin
  q:=p; writeln;
  if q^.next <>nil then
    repeat
       write(q^.data,’ ‘); q:=q^.next;
   until q^.next=nil;
End;
```

## 5 作业

```cpp
1. 完成例2.1
2. 作业2.2 :简单魔板(sicily1150)
3. 1151 魔板B，要求写解题报告
4. 1515 魔板C
5. 1007 数组与下标（二维数组） 简单
6. 1036 数组与下标（二维数组） 简单
7. 1006 栈与回溯 简单  5!搜索
8. 1009 梅森素数
9. 1050 回溯， DFS求5个数可否运算得到目标数, 否则输出可得到的小于目标数的最大数.
10. 1443 基本队列操作
11. 1156 深优 指针 简单树的遍历
12. 1063 排序后递推
13. 1024树的遍历
```

