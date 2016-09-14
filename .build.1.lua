
project "Slacking"

    kind "Utility"

    if _ACTION == "xcode4" then
            kind "StaticLib"
    end

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
