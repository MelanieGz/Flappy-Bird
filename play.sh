#! /bin/sh
echo "Pulling latest code"
git pull origin master
echo "Building files"
cmake .
make
echo "Running tests"
./runtests
echo "Running game"
./play
