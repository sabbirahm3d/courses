#!/bin/sh

cd DS-DC-13
echo "Attempting git pull..."

if git pull | grep 'Already up-to-date.'; then
   true

else
    cd ..
    git add -A
    git status

fi