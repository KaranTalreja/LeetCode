#!/bin/bash

links=$1
INDEX_FILE="html/index.md"
rm $INDEX_FILE
touch $INDEX_FILE
echo "<!DOCTYPE html>" >> $INDEX_FILE
echo "<html>" >> $INDEX_FILE
echo "<body>">> $INDEX_FILE
echo "<table style=\"width:100%\"> ">> $INDEX_FILE
echo "  <tr> ">> $INDEX_FILE
echo "    <th>Id</th>">> $INDEX_FILE
echo "    <th>Link</th>">> $INDEX_FILE
echo "    <th>Percentile</th>">> $INDEX_FILE  
echo "  </tr>">> $INDEX_FILE
id=0
while read LINE; do

src_dir=`echo $LINE | awk -F '/' '{print $(NF-1)}'`
let id++
echo "  <tr>">> $INDEX_FILE
echo "    <td>$id</td>">> $INDEX_FILE
echo "    <td><p><a href=\"$LINE\">$src_dir</a></td>">> $INDEX_FILE
echo "    <td><a href=\"https://github.com/KaranTalreja/LeetCode/blob/master/src/$src_dir/solution.cpp\">`cat src/$src_dir/percentile`%</a></td>">> $INDEX_FILE  
echo "  </tr>">> $INDEX_FILE

done < $1

echo "</table>">> $INDEX_FILE
echo "</body>">> $INDEX_FILE
echo "</html>">> $INDEX_FILE
