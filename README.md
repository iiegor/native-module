# node-mouse
This is a node native-module created (for learning purposes) to provide native utilities for cursor :smiley:

:warning: This is currently under extremely active development, and you probably shouldn't use it unless you like broken software.

## Installing
```bash
$ npm install iiegor/node-mouse
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

``click(type)`` *Mouse click*
