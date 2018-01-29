#!/bin/bash

if [ -d basefiles ]; then
	echo -n
else
	mkdir basefiles
fi

curLine=0

while [ $(wc -l pages.txt | cut -d" " -f1) -gt $curLine ]; do
	curLine=$(($curLine+1))
	l=$(head pages.txt --lines=$curLine | tail --lines=1)
	
	if [ -z "$l" ]; then
		continue;
	fi
	
	echo Downloading $l
	wget -O redohtml/input.html -q $l
	cd redohtml
	./generatepage.sh
	cd ..
	mv redohtml/output.html basefiles/$curLine.html
done

echo Coping bg.svg...
cp redohtml/bg.svg basefiles/bg.svg