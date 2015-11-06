# node-mouse
This is a node native-module created (for learning purposes) to provide native utilities for cursor :smiley:

## Building
```bash
$ npm install
$ grunt coffee
```

## API
``setPosition(x, y)`` *Set cursor position*

``getPosition()`` *Get cursor position*

``registerIdleHandler(time, callback)`` *Handles mouse ``EVENT_IDLE``*
