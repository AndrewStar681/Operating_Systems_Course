touch _ex3.txt
echo "Andrey Starodumov" >> _ex3.txt
echo "Let's add execute permission to everyone:" >> ex3.txt
chmod a+x _ex3.txt >> ex3.txt
ls -l _ex3.txt >> ex3.txt
echo >> ex3.txt
echo "Let's remove exexute permission from everyone:" >> ex3.txt
chmod a-x _ex3.txt >> ex3.txt
ls -l _ex3.txt >> ex3.txt
echo >> ex3.txt
echo "Grant all permissons to user and others:" >> ex3.txt
chmod uo=rwx _ex3.txt >> ex3.txt
ls -l _ex3.txt >> ex3.txt
echo >> ex3.txt
echo "Group permissions are equal to user:" >> ex3.txt
chmod g=u _ex3.txt >> ex3.txt
ls -l _ex3.txt >> ex3.txt
echo >> ex3.txt
echo "What does 660 mean for ex3.txt?" >> ex3.txt
echo "  user  : can Read and Write" >> ex3.txt
echo "  group : can Read and Write" >> ex3.txt
echo "  others: can do nothing:" >> ex3.txt
echo >> ex3.txt
echo "What does 775 mean for ex3.txt?" >> ex3.txt
echo "  user  : can do all - Read, Write, Execute" >> ex3.txt
echo "  group : can do all - Read, Write, Execute" >> ex3.txt
echo "  others: can Read and Execute" >> ex3.txt
echo >> ex3.txt
echo "What does 777 mean for ex3.txt?" >> ex3.txt
echo "  user  : can do all - Read, Write, Execute" >> ex3.txt
echo "  group : can do all - Read, Write, Execute" >> ex3.txt
echo "  others: can do all - Read, Write, Execute" >> ex3.txt
