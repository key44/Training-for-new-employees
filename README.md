# 新入社員向けプログラム講習会
## 1, Arduino IDEのインストール  
下記のリンクからアプリのダウンロードを行います。今回はWindows10版のMSIインストーラを使用します。  
[https://www.arduino.cc/en/software](https://www.arduino.cc/en/software)  
![image1](image/install.png?raw=true)  
just DOWNLOAD をクリック。
![image2](image/just.png?raw=true)
ダウンロードしたファイルをクリックして実行。  

インストールが完了すると下図のようなアイコンが出るのダブルクリックする。  
![image2](image/rogo.png?raw=true)  
初回起動時は、ファイアウォールの許可が求められるので全てに「はい」を選択。  
*初回起動時は、しばらく時間がかかるので待機。  
  

## 2, Arduino IDEの初期設定  
IDEを起動したら、ボードマネージャから「M5」を検索しINSTALLする。  
![image3](image/m5add.png?raw=true)  
  
M5stack本体 をUSBでパソコンに接続し、下図のドロップダウンをクリックして「Sekect other ~ 」をクリック  
![image4](image/selectp.png?raw=true)  
  
検索欄に「m5stack」と入力し「M5stack-Core_ES... -M5Stack」を選択して、COM~ Serial Port(USB)をクリックして「OK」を押す。  
*COM[数字]は、使用するパソコンによって変わるので「(USB)」と書かれているものを選択する。  
![image4](image/boards.png?raw=true)  
  
IDEでM5Stackのプログラムを実行させるためにインクルードする。
Library Managerから「M5stack」と検索をかけて、しばらくスクロールすると「M5Stack by M5stack」が出てくるのでインストールする。  
![image4](image/incl.png?raw=true)  
  
  
## 3, プログラム課題  
### 課題1 「Hello World」  
    
まずはじめに、M5Stackのディスプレイへ「Hello World」と表示させてみる。  

```cpp
#include <M5Stack.h>

void setup() {
  M5.begin();
  M5.Lcd.setTextSize(3);
  M5.Lcd.printf("Hello World");
}

void loop() {

}
```  
上記プログラムの解説をすると。  
    
<br>  

```cpp
#include <M5Stack.h>  
```
M5Stackを簡単に操作するプログラムを別なところから呼び寄せる  
<br>

```cpp
M5.begin();  
```
M5Stackの初期化  
<br>  
```cpp
M5.Lcd.setTextSize(3);  
```
M5Stackの画面に表示させる文字の大きさを「3」にセット。  
*数字は1~7の間で可変可能なので、時間があれば試してみてください。    

### 課題2 「カウントアップ」   
M5Stackの画面に数字をカウントアップさせ表示させる。  

``` cpp
#include <M5Stack.h>

void setup() {
  M5.begin();
  M5.Lcd.setTextSize(7); 
}

void loop() {
  for (int i = 0; i < 11; i++)
  {
    M5.Lcd.setCursor(145, 100);
    M5.Lcd.print(i);
    delay(1000);
    M5.Lcd.clear();
  }
  
}
```
課題１で説明していない部分も含め解説をします。  
<br>  
`void setup()`とは、プログラムを実行したときに１度だけM5Stackが読み込む部分を{ }内に書きます。   
1度だけ読み込むため、様々なプログラムでは主に初期設定を書くことが多いです。  

```cpp
void setup() {

} 
```  
`void loop()`は、{ }内に書かれているものを無限に繰り返してM5Stackは、実行し続けます。  
産業機器やIoTなどで使われるコンピューターは、基本的に決められた動作を繰り返し行うようにプログラムしているものがほとんどです。  
```cpp
void loop() {

} 
```  
<br>
先程までは、一つの命令に対して１行のプログラムという形でM5Stackへ命令を出してきましたが、プログラムには「for文」という概念があります。  
「for文」とは、指定された回数繰り返し処理をするというプログラムです。  

``` cpp
for (int i = 0; i < 11; i++) {

}
```  
( )の中を少し解説します。
<br>  
「i = 0」は、数学的な考え方と同じで「i」は0と同じ、つまりプログラム上では、変数「i」に0を代入せよ。と命令を出しています。  
残りの「int」は、「i」を整数でしか扱いませんという宣言になります。  
整数「int」の他に小数点「float」、文字列「srg」...などたくさんあり、何を代入して計算させるかによってまちまちです。
``` cpp
int i =0;  
```
「i < 11」は、変数「i」が11未満の場合for文を繰り返しするよ。という意味となります。  
``` cpp
i < 11;
```  
「i++」は、変数「i」を「for文」で繰り返すたびに、 「i」に1を足し続けます。という意味です。
``` cpp
i++
```  
従って、`for (int i = 0; i < 11; i++)`とは、  
「変数iに0を代入し、ここではiは整数でしか使いません。for文は、iが11未満のときのみ繰り返します。iは、繰り返す度に1ずつ増えます。従って、iが11になったらこのfor文を抜けて次に進みます。」  
と書いてある事になります。  
<br>
出力される文字の位置を移動する場合は、`setCursor(x,y)`でx座標とy座標を指定することが出来ます。  

```cpp
M5.Lcd.setCursor(145, 100);
```  
プログラムは秒間に何百回・何千回とループを繰り返していますが、あまりに早すぎると、たくさんの電力を無駄に消費してしまったり、目にも留まらぬ速さで、ディスプレイなどに表示してしまうと見にくかったりしてしまう場合は`delay()`を噛まして、計算を指定時間止めることが出来ます。  
`delay()`は、ミリ秒で指定します。1秒=1000ミリ秒。  

``` cpp
delay(1000);
```  

`M5.Lcd.clear();`で全画面を非表示にさせます。これを行わないと、文字や数字が重なって表示されてしまいます。  

``` cpp
M5.Lcd.clear();
```  

### 課題3 「ボタン」 
M5Stackのボタンを操作して、ボタンを押したら何かを表示させるプログラムを作りましょう。
  
今まで行ってきた課題を済ませているなら課題3は、とてもシンプルです。
``` cpp
#include <M5Stack.h>

void setup() {
  M5.begin();
  M5.Lcd.setTextSize(7);
}

void loop() {
  M5.update();
  M5.Lcd.setCursor(140, 100);
  if(M5.BtnA.isPressed())
  {
    M5.Lcd.clear(); 
    M5.Lcd.print("A!");
    delay(1000);
  }
  if(M5.BtnB.isPressed())
  {
    M5.Lcd.clear(); 
    M5.Lcd.print("B!");
    delay(1000);
  }
  if(M5.BtnC.isPressed())
  {
    M5.Lcd.clear(); 
    M5.Lcd.print("C!");
    delay(1000);
  } 
}
```  
「もしボタンを押したら」など、何かの条件を満たしたら実行させる場合は、「if文」を使います。  
``` cpp  
if(M5.BtnA.isPressed()){

}
```  
ここでは、「もし」M5StackのAボタンを押したら、{  }内のプログラムを実行する。という意味です。  

