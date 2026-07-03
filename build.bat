@echo off
setlocal

REM Load Emscripten environment
call C:\Users\abiga\emsdk\emsdk_env.bat

REM Go to this script's folder
cd /d %~dp0

REM Compile C++ engine to WebAssembly
em++ wasm_bindings.cpp engine/SatzmaschineEngine.cpp engine/generation/Sentence.cpp engine/parsing/Utility.cpp engine/words/Pronoun.cpp engine/words/Verb.cpp engine/words/Noun.cpp engine/words/PersonNoun.cpp engine/words/Adjective.cpp engine/words/Adverb.cpp engine/words/StartNoun.cpp engine/words/NounStartingVerb.cpp ^
  -o web/satzmaschine.js ^
  --bind ^
  --preload-file web\data@data ^
  -s MODULARIZE=1 ^
  -s EXPORT_NAME=createSatzmaschineModule

if %ERRORLEVEL% neq 0 (
    echo.
    echo Build failed.
    pause
    exit /b %ERRORLEVEL%
)

echo.
echo Build succeeded!
pause