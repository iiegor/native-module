{EventEmitter} = require 'events'
binding = require '../build/Release/mouse.node'

class Mouse extends EventEmitter
  setPosition: binding.setPosition
  getPosition: binding.getPosition
  setCallback: binding.setCallback

  registerIdleHandler: (time, cb) ->
    binding.setCallback(cb)
    binding.watch(time)

module.exports = new Mouse