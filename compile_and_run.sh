#!/bin/sh

echo "generating libpubsub.so library.."
g++ -shared -fPIC *.h subscriber.cpp subscriberlist.cpp publisher.cpp -o libpubsub.so
echo "compiling sample application.."
g++ main.cpp -L $PWD -o app -lpubsub -lpthread
echo "updating LD_LIBRARY_PATH.."
export LD_LIBRARY_PATH=$PWD:$LD_LIBRARY_PATH
echo "running application.."
echo "subscriber 1 & 2 is receiving messages from publisher-1"
echo "subscriber 3 & 4 is receiving messages from publisher-2"
echo "--------------------------------------------------------"
./app