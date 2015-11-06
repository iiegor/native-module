binding = require '../build/Release/mouse.node'

###
@desc Set's mouse position to x: 10 y: 10
###
binding.setPosition(10, 10)

###
@desc Print's mouse position
###
console.log binding.getPosition()