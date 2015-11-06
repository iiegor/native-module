{EventEmitter} = require 'events'
binding = require '../build/Release/mouse.node'

class Mouse extends EventEmitter
  setPosition: binding.setPosition
  getPosition: binding.getPosition
  setCallback: binding.setCallback
  watch: binding.watch

  registerIdleHandler: (time, cb) ->
    @setCallback(cb)
    @watch(time)

module.exports = new Mouse