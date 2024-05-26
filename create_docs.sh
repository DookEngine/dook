#!/usr/bin/env sh

src_root=$1
first_gen=0
echo "Generating docs under $1/docs"

cd $1
if [ ! -d "venv" ]; then
    first_gen=0
    python -m venv venv
fi

source ./venv/bin/activate

# Install deps if not installed already.
if [ first_gen -eq 0 ]; then
    pip install -r requirements.txt
fi

# Build doxygen and feed it to sphinx.
doxygen Doxyfile
sphinx-build -M html ./source ./build  -Dbreathe_projects.Dook=../xml
deactivate