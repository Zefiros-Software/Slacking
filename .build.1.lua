
project "Slacking"

    filter "platforms:Windows"
        kind "Utility"

    filter "platforms:Unix"
        kind "StaticLib"

    filter "platforms:Mac"
        kind "StaticLib"

    filter {}

    zpm.uses {
        "Zefiros-Software/cURL"
    }

    zpm.export [[
        includedirs "include/"
        flags "C++11"
        defines {
            "NOMINMAX"
        }
    ]]
