mkdir ../week01
touch ../week01/file.txt
echo "Andrey Starodumov" > ../week01/file.txt
ln ../week01/file.txt _ex2.txt
echo "All found links in current direction to the file.txt:" >> ex2.txt
find . -inum $(ls -i ../week01/file.txt | awk '{print $1}') >> ex2.txt
echo >> ex2.txt
echo "Remove all links to the file.txt:" >> ex2.txt
find . -inum $(ls -i ../week01/file.txt | awk '{print $1}') -exec rm {} \; >> ex2.txt
echo >> ex2.txt
echo "Check if there are links to the file.txt:" >> ex2.txt
find . -inum $(ls -i ../week01/file.txt | awk '{print $1}') >> ex2.txt
