# ChaiScript
To use [Slacking](https://github.com/coin-au-carre/slacking) in [ZPM](http://zpm.zefiros.eu), just use:

# Status
OS          | Status
----------- | -------
Linux & OSX | [![Build Status](https://travis-ci.org/Zefiros-Software/Slacking.svg?branch=master)](https://travis-ci.org/Zefiros-Software/Slacking)
Windows     | [![Build status](https://ci.appveyor.com/api/projects/status/3vmi3jrsqekggi46?svg=true)](https://ci.appveyor.com/project/PaulVisscher/slacking)

# [ZPM](http://zpm.zefiros.eu) Installation
In `.package.json`
```json
"requires": [
		{
			"name": "Zefiros-Software/Slacking",
			"version": "@head"
		}
]
```

In `premake5.lua`
```lua
zpm.uses "Zefiros-Software/Slacking"
```