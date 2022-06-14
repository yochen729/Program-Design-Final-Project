# Program Design Final Project - The Simple Bank System Simulator

## How to execute our program

###  1. Get the source code
  >Clone or download source code from Github. You can download it directly, 
  >or use a tool like Git-bash, tortoise git... ,
  >or download the release .exe file.
    
###  2. Go to our final_program_new_version folder
 >Open the terminal and use cd command to change direction to final_program_new_version folder.
    
###  3. Compile the source code
 >Notice: Make sure you are using windows operating system, because in our program we have the <conio.h> and <windows.h>.
 >Use terminal and type "gcc *c -o bank"
 >then press enter to get a file.
    
####  4. Run the code
 >Use ./bank to start our program.

## 銀行系統模擬

### 功能：

#### 1.建立帳戶
    -建立多個帳戶(引入CSV檔)
    -建立單一帳戶(stdin)

#### 2.刪除帳戶(需輸入密碼)
    -是否輸出(刪除帳號的)檔案資料

#### 3.檢視已有帳戶
    -檢視資料(不輸出檔案)
    -輸出檔案資料

#### 4.排序帳戶
    -依照名字
    -依照剩餘金額
    -依照開戶日期

#### 5.帳戶交易(需輸入密碼)
    -存款
    -提款
    -轉帳
    -投資
        -RANDOM EVENT

#### 6.借貸(需輸入密碼)
    -借錢
    -還錢

#### 7.管理帳戶(需輸入密碼)
    -檢視帳戶個人信息
    -列出帳戶所有交易紀錄
    -修改個人信息
