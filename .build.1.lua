
project "Slacking"

    kind "Utility"

    zpm.uses {
        "Zefiros-Software/cURL"
    }

    zpm.export [[
        includedirs "include/"

        defines {
            "NOMINMAX"
        }
    ]]