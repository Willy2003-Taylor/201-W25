#!/bin/bash

x=$1

while [ $x -gt 0 ]; do
  echo $x
  x=$((x-1))
done
