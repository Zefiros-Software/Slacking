
project "Slacking"

    filter { "action:not xcode4" }
            kind "Utility"

    filter { "action:xcode4" }
            kind "StaticLib"

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
