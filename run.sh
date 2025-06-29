#!/bin/bash
build_dir=build
makefile_path=$build_dir/Makefile
exec_name=NandLogic
exec_path=$build_dir/$exec_name

if [ -a $exec_path ] ; then
    rm $exec_path
fi

if [ -a  $makefile_path ] ; then
    echo "Makefile exist"
    make -C build/
    ./${build_dir}/${exec_name}
else
    echo "Makefile does not exist, try building project."
fi
