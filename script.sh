#!/bin/sh
echo $1
rm -rf ../../printf/*
rm .DS_Store
rm .*.swp
rm srcs/.DS_Store
rm srcs/.*.swp
rm srcs/a.out
rm includes/.DS_Store
rm includes/.*.swp
rm libs/.DS_Store
rm libs/.*.swp
cp -R * ../../printf
cd ~/Desktop/printf
git add *
git status
now=$1
git commit -m "$now"
git status
git push
git log
echo "pushed"
