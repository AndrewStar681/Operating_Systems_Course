touch _ex1.txt
echo "Andrey Starodumov" > _ex1.txt
ln _ex1.txt _ex1_1.txt
ln _ex1.txt _ex1_2.txt
ls -i _ex1.txt _ex1_1.txt _ex1_2.txt > ex1.txt
cat ex1.txt
