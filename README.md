# node-mouse
This is a node native-module created (for learning purposes) to provide native utilities for cursor :smiley:

## Installing
```bash
$ npm install node-mouse
```

## Building
```bash
$ npm install
$ grunt coffee
```

## API
``setPosition(x, y)`` *Set cursor position*

``getPosition()`` *Get cursor position*

``registerIdleHandler(time, callback)`` *Handle mouse ``EVENT_IDLE``*
