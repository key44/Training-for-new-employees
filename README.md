# 1, Arduino IDEのインストール  
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
  

# 2, Arduino IDEの初期設定  
IDEを起動したら、ボードマネージャから「M5」を検索しINSTALLする。  
![image3](image/m5add.png?raw=true)  
  
M5stack本体 をUSBでパソコンに接続し、下図のドロップダウンをクリックして「Sekect other ~ 」をクリック  
![image4](image/selectp.png?raw=true)  
  
検索欄に「m5stack」と入力し「M5stack-Core_ES... -M5Stack」を選択して、COM~ Serial Port(USB)をクリックして「OK」を押す。  
*COM[数字]は、使用するパソコンによって変わるので「(USB)」と書かれているものを選択する。  
![image4](image/boards.png?raw=true)  

