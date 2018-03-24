for file in *.sh
do
	cp $file ${file%%sh}bash
done
