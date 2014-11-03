#!/bin/sh

#如果找不到符号xdr_reference的定义
#会从/usr/lib中每个函数库中使用nm浏览所有的符号，从中寻找丢失的符号
cd /usr/lib
for i in ./lib?*
do
  echo $i
  nm $i | grep xdr_refrence | grep -v UNDEF
done

