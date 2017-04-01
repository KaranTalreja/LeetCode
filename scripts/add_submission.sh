#!/bin/bash

new_submissions=$1

while read LINE; do

percentile=`echo $LINE | awk -F "@@" '{print $1}'`
src_dir=`echo $LINE | awk -F "@@" '{print $2}' | awk -F '/' '{print $(NF-1)}'`
if [ ! -d src/$src_dir ]; then
  # Control will enter here if $DIRECTORY exists.
 mkdir src/$src_dir
 touch src/$src_dir/solution.cpp
 echo $percentile >> src/$src_dir/percentile
 echo "`echo $LINE | awk -F "@@" '{print $2}'`" >> data/solved_problems.txt
fi

done < $new_submissions

./scripts/gen_index.sh data/solved_problems.txt
