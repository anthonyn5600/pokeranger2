@echo off
rem Start the PC port with its own renderer; the log goes to pokeranger2.log next to it
cd /d "%~dp0"
set NTRGFX=1
set PC_AUDIO_LOG=1
set PC_FPS_LOG=1
pokeranger2.exe > pokeranger2.log 2>&1
