binding = require '../build/Release/mouse.node'

###
@spec Object {command: string, exitCode: int}
###
console.log binding.mouse('detectMouseMovement')