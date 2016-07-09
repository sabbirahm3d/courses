#!/bin/sh

cd DS-DC-13
echo "Synchronizing class repo..."

if git pull | grep 'Already up-to-date.'; then
   true
fi
# else
cd ..
cp -r -n DS-DC-13/* copy/
git add -A
cd Heat-Replay
# fi

# cd ../Heat-Replay
echo "Synchronizing project..."

if git pull | grep 'Already up-to-date.'; then
   true
fi
# else
cd ..
git add -A
git status
# fi
