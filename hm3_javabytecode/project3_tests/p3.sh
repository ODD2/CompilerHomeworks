#!/bin/bash
#program:
#Demo compiler project3
#History:
#2019/06/12 Jacky Ho revised 
#2019/05/23 Gary First Release

read -p "Please input your executable filename: " filename
read -p "Redirect(需要 < 嗎)(0: 不用, 1: 需要): " Redirect
read -p "輸出的class 名字是否同輸入檔名(0: 否, 1: 是):" same_name
if [ "${same_name}" == "0" ]; then
	read -p "請輸入class name: " name
fi	
read -p "是否有自訂輸出檔案名稱(0: 否, 1: 是): " output01
if [ "${output01}" == "1" ]; then
	read -p "請輸入檔名 .jasm:" output
else
	output="temp.jasm"
fi

array=("Example Sigma fib a01 a02 a03 a04 a05 a06 a07 a08 a09 a10 a11 a12 a13 a14 a15 a16 a17 a18 Bonus1 Bonus2 Bonus3 Bonus4 Bonus5 Bonus6 Bonus7 Bonus8")
ans=( -15	55	2	-28	3	-72	6	-36	-22	-10	10	-6	6	-50	99	75	31	120	120	551	441 "BONUS" "Bonus2 is here." "3.14" "6.28" 52 45 "read" "BO\"NUS")
x=0
for i in ${array}
do
	if [ "${Redirect}" == "1" ];then
		if [ "${output01}" == "1" ]; then
			./${filename} < $i.modula > $output
		else 
			./${filename} < $i.modula
			output=$i.jasm
		fi
	else
		if [ "${output01}" == "1" ]; then
			./${filename} $i.modula > $output
		else 
			./${filename} $i.modula
			output=$i.jasm
		fi
	fi
	echo $output
	./javaa $output
	echo 檔案名稱 $i
	echo 你的答案
	if [ "${same_name}" == "1" ]; then
		name=$i
	fi
	echo $name
	java $name 
	echo 正確答案
	echo ${ans[$x]}
	x=$x+1
	read
done
