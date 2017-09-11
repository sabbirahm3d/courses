#!/bin/sh

class=DS-DC-13
project=Heat-Replay

git_pull() {
    cd $1
    echo "Synchronizing $1"
    if git pull | grep 'Already up-to-date.'; then
        true
    fi
    cd ..
}

git_pull $class
git_pull $project

cp -r -n $class/* copy/
git add -A
git status
