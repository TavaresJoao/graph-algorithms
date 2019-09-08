#!/bin/bash
CUR_PATH=$(pwd)

for x in Instances/*
do
  #echo "$CUR_PATH/$x";
  ./bin/main.out "$CUR_PATH/$x"
done
