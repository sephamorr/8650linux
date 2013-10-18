#!/bin/bash
./pullfromsd.sh
umount /dev/sdb1
umount /dev/sdb2
git add partial_test2
git commit -a
git push
