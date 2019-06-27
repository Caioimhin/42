cpt = 100000
while ((cpt<10000000))
do
	echo "$cpt : "
	./rush-02 $cpt
	echo "\n"
	((cpt+=1))
done
exit 0

