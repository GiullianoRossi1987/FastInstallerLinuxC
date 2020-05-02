#!/bin/bash

# create all the files ignored by git

for i in $(cat .gitignore); do
	touch $i
done

echo "SETUP COMPLETE"
