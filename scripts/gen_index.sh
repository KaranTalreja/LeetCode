#!/bin/bash

links=$1
INDEX_FILE="html/index.md"
rm $INDEX_FILE
touch $INDEX_FILE
echo "<!DOCTYPE html>" >> $INDEX_FILE
echo "<html>" >> $INDEX_FILE
echo "<body>">> $INDEX_FILE
while read LINE; do

src_dir=`echo $LINE | awk -F '/' '{print $(NF-1)}'`
echo "<p><a href=\"$LINE\">$src_dir</a>" beats `cat src/$src_dir/percentile`% submissions"</p>">> $INDEX_FILE

done < $1

echo "</body>">> $INDEX_FILE
echo "</html>">> $INDEX_FILE
