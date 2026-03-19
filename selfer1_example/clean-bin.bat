REM --------------------------------------
REM clean-bin.bat
REM --------------------------------------
DEL /S /Q /F UpgradeLog*.XML
DEL /S /Q /F *.ncb
DEL /S /Q /F *.suo
DEL /S /Q /F *.sdf
DEL /S /Q /F *.ilk
DEL /S /Q /F *.pdb
REM ------------------
REM bin
REM ------------------
RMDIR /S /Q .\bin\Debug\obj
RMDIR /S /Q .\bin\Release\obj
REM --------------------------------------
