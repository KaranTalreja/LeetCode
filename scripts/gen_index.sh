#!/bin/bash

links=$1
INDEX_FILE="html/index.html"
rm $INDEX_FILE
touch $INDEX_FILE
echo "<!DOCTYPE html>" >> $INDEX_FILE
echo "<html>" >> $INDEX_FILE
echo "<body>">> $INDEX_FILE
echo "<table id="myTable2" style=\"width:100%\"> ">> $INDEX_FILE
echo "  <tr> ">> $INDEX_FILE
echo "    <th onclick=\"sortTable(0)\">Id</th>">> $INDEX_FILE
echo "    <th onclick=\"sortTable(1)\">Link</th>">> $INDEX_FILE
echo "    <th onclick=\"sortTable(2)\">Percentile</th>">> $INDEX_FILE  
echo "  </tr>">> $INDEX_FILE
id=0
while read LINE; do

src_dir=`echo $LINE | awk -F '/' '{print $(NF-1)}'`
let id++
echo "  <tr>">> $INDEX_FILE
echo "    <td>$(printf %03d $id)</td>">> $INDEX_FILE
echo "    <td><p><a href=\"$LINE\">$src_dir</a></td>">> $INDEX_FILE
percentilenumber=`cat src/$src_dir/percentile | awk -F'.' '{print $1}'`
percentileprecision=`cat src/$src_dir/percentile | awk -F'.' '{print $2}'`
format="$(printf %02d $percentilenumber)"".""$(printf %02d $percentileprecision)%, "
echo "    <td>$format<a href=\"https://github.com/KaranTalreja/LeetCode/blob/master/src/$src_dir/solution.cpp\">[solution]</a></td>">> $INDEX_FILE  
echo "  </tr>">> $INDEX_FILE

done < $1
echo "{::nomarkdown} ">>$INDEX_FILE

echo " <script>" >> $INDEX_FILE
echo " function sortTable(n) {">> $INDEX_FILE
echo "   var table, rows, switching, i, x, y, shouldSwitch, dir, switchcount = 0;">> $INDEX_FILE
echo "   table = document.getElementById(\"myTable2\");">> $INDEX_FILE
echo "   switching = true;">> $INDEX_FILE
echo "   //Set the sorting direction to ascending:">> $INDEX_FILE
echo "   dir = \"asc\";">> $INDEX_FILE  
echo "   /*Make a loop that will continue until">> $INDEX_FILE
echo "   no switching has been done:*/">> $INDEX_FILE
echo "   while (switching) {">> $INDEX_FILE
echo "     //start by saying: no switching is done:">> $INDEX_FILE
echo "     switching = false;">> $INDEX_FILE
echo "     rows = table.getElementsByTagName(\"TR\");">> $INDEX_FILE
echo "     /*Loop through all table rows (except the">> $INDEX_FILE
echo "     first, which contains table headers):*/">> $INDEX_FILE
echo "     for (i = 1; i < (rows.length - 1); i++) {">> $INDEX_FILE
echo "       //start by saying there should be no switching:">> $INDEX_FILE
echo "       shouldSwitch = false;">> $INDEX_FILE
echo "       /*Get the two elements you want to compare,">> $INDEX_FILE
echo "       one from current row and one from the next:*/">> $INDEX_FILE
echo "       x = rows[i].getElementsByTagName(\"TD\")[n];">> $INDEX_FILE
echo "       y = rows[i + 1].getElementsByTagName(\"TD\")[n];">> $INDEX_FILE
echo "       /*check if the two rows should switch place,">> $INDEX_FILE
echo "       based on the direction, asc or desc:*/">> $INDEX_FILE
echo "       if (dir == \"asc\") {">> $INDEX_FILE
echo "         if (x.innerHTML.toLowerCase() > y.innerHTML.toLowerCase()) {">> $INDEX_FILE
echo "           //if so, mark as a switch and break the loop:">> $INDEX_FILE
echo "           shouldSwitch= true;">> $INDEX_FILE
echo "           break;">> $INDEX_FILE
echo "         }">> $INDEX_FILE
echo "       } else if (dir == \"desc\") {">> $INDEX_FILE
echo "         if (x.innerHTML.toLowerCase() < y.innerHTML.toLowerCase()) {">> $INDEX_FILE
echo "           //if so, mark as a switch and break the loop:">> $INDEX_FILE
echo "           shouldSwitch= true;">> $INDEX_FILE
echo "           break;">> $INDEX_FILE
echo "         }">> $INDEX_FILE
echo "       }">> $INDEX_FILE
echo "     }">> $INDEX_FILE
echo "     if (shouldSwitch) {">> $INDEX_FILE
echo "       /*If a switch has been marked, make the switch">> $INDEX_FILE
echo "       and mark that a switch has been done:*/">> $INDEX_FILE
echo "       rows[i].parentNode.insertBefore(rows[i + 1], rows[i]);">> $INDEX_FILE
echo "       switching = true;">> $INDEX_FILE
echo "       //Each time a switch is done, increase this count by 1:">> $INDEX_FILE
echo "       switchcount ++; ">> $INDEX_FILE
echo "     } else {">> $INDEX_FILE
echo "       /*If no switching has been done AND the direction is \"asc\",">> $INDEX_FILE
echo "       set the direction to \"desc\" and run the while loop again.*/">> $INDEX_FILE
echo "       if (switchcount == 0 && dir == \"asc\") {">> $INDEX_FILE
echo "         dir = \"desc\";">> $INDEX_FILE
echo "         switching = true;">> $INDEX_FILE
echo "       }">> $INDEX_FILE
echo "     }">> $INDEX_FILE
echo "   }">> $INDEX_FILE
echo " }">> $INDEX_FILE
echo " </script>" >> $INDEX_FILE
echo "{:/} " >> $INDEX_FILE
echo "</table>">> $INDEX_FILE
echo "</body>">> $INDEX_FILE
echo "</html>">> $INDEX_FILE
