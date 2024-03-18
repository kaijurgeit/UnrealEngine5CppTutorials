echo 'Cleaning'
powershell.exe -NoExit -ExecutionPolicy -Bypass -Command "ls -Recurse -Include Build, Intermediate, Binaries, *.sln, .vs | rmdir -Force -Recurse;"