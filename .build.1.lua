
project "Slacking"

    kind "Utility"

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