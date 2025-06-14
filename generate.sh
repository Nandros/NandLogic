# !/bin/bash
build_dir="build"

if [ -d $build_dir ] ; then
    echo "${build_dir} dir exist"
else
    echo "Create ${build_dir} directory"
fi

cmake -B${build_dir} .
