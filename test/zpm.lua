
workspace "Slacking"
   configurations { "Test" }
   
   architecture "x86_64"
   
   startproject "Slacking"

    project "Slacking"
        kind "ConsoleApp"
        files "main.cpp"

        zpm.uses {
            "Zefiros-Software/Slacking"
        }