{EventEmitter} = require 'events'
binding = require '../build/Release/mouse.node'

class Mouse extends EventEmitter
  setPosition: binding.setPosition
  getPosition: binding.getPosition

module.exports = new Mouse