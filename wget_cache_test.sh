#!/bin/bash

TEST_URL=https://ftp.gnu.org/gnu/wget/wget-1.9.1.tar.gz.sig
CACHE_DIR=/home/sebastian/.cached_wget

mkdir -p test_data
cd test_data

echo '<<< TEST >>> DOWNLOAD FROM STANDARD URL'
../src/wget $TEST_URL

echo '<<< TEST >>> DOWNLOAD WITH CACHE'
../src/wget $TEST_URL

echo '<<< TEST >>> REMOVE FROM CACHE'
rm $CACHE_DIR/193576213b968f1fc0f8c0216d2fafaa/wget-1.9.1.tar.gz.sig

echo '<<< TEST >>> DOWNLOAD WITH OUTPUT NAME'
../src/wget $TEST_URL -O new_name.tar.gz.sig

echo '<<< TEST >>> DOWNLOAD WITH OUTPUT NAME (COPY FROM CACHE)'
../src/wget $TEST_URL -O new_name.tar.gz.sig

echo '<<< TEST >>> REMOVE FROM CACHE'
rm $CACHE_DIR/193576213b968f1fc0f8c0216d2fafaa/wget-1.9.1.tar.gz.sig

echo '<<< TEST >>> DOWNLOAD WITH OPTION --spider (do not download anything)'
../src/wget --spider $TEST_URL

echo '<<< TEST >>> DOWNLOAD WITH OPTION "-" INSTEAD OF FILE NAME'
../src/wget  $TEST_URL -O-
