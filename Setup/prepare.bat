
set VCINSTALLDIR=C:\Program Files (x86)\Microsoft Visual Studio 14.0\VC
set windeployqt="C:\Qt\Qt5.9.9\5.9.9\msvc2015_64\bin\windeployqt.exe"
set src="..\Build_x64\release"
set lib=%src%\lib
%windeployqt% --libdir %lib% %src%