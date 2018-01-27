#!/bin/bash

if [ -d tmp ]; then
	echo -n
else
	mkdir tmp
fi

if [ -d basefiles ]; then
	echo -n
else
	mkdir basefiles
fi

cat pages.txt > tmp/lines
curLine=0

#cd tmp
while [ $(wc -l tmp/lines | cut -d" " -f1) -gt $curLine ]; do
	curLine=$(($curLine+1))
	l=$(head tmp/lines --lines=$curLine | tail --lines=1)
	
	if [ -z "$l" ]; then
		continue;
	fi
	
	wget -O redohtml/input.html $l
	cd redohtml
	./generatepage.sh
	cd ..
	mv redohtml/output.html basefiles/$curLine.html
done

echo Coping bg.svg...
cp redohtml/bg.svg basefiles/bg.svg