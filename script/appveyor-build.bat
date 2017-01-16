cd test/
zpm install-package --allow-install --allow-module  || exit /b 1
zpm vs2015 --allow-install || exit /b 1

msbuild Slacking.sln /property:Configuration=Test /property:Platform=x64 || exit /b 1

.\bin\Test\Slacking.exe || exit /b 1