#!/bin/sh

cd DS-DC-13
echo "Synchronizing class repo..."

if git pull | grep 'Already up-to-date.'; then
   true
fi

cd ..

cp -r -n DS-DC-13/* copy/

git add -A

cd Heat-Replay

echo "Synchronizing project..."

if git pull | grep 'Already up-to-date.'; then
   true
fi

cd ..

git add -A
git status
