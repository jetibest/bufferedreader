#!/bin/bash

if ! ./compile.sh
then
    echo "Compilation error, did not install."
    exit 1
fi
sudo cp -n ./build/bufferedreader /bin/bufferedreader || echo "File /bin/bufferedreader already exists."
sudo ln -s /bin/bufferedreader /bin/br

