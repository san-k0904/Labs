#echo enter directory path: ;read path
#ls $path/*.[a-z]

#echo "Number of users `who | wc -l`"

#echo "Number of "
#echo "1
#2
#3
#7">file1.txt
#echo "2
#4
#5
#9">file2.txt
#sort -nu file1.txt file2.txt > output.txt
#echo Merged output:
#cat output.txt

find . -type f -name "$1" -exec cp {} "$2" \;