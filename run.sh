#!/bin/bash
build_dir=build
makefile_path=$build_dir/Makefile
exec_name=NandLogic

if [ -a  $makefile_path ] ; then
    echo "Makefile exist"
    make -C build/
    ./${build_dir}/${exec_name}
else
    echo "Makefile does not exist, try building project."
fi
