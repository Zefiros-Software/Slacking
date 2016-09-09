set -e

cd test/

premake5 install-package --allow-install --allow-module
premake5 gmake --allow-install

make 

./bin/Test/Slacking