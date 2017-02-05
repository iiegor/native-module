# node-mouse

This is a node native-module created to provide cross-platform mouse utilities :smiley:

:warning: This is currently under extremely active development, and you probably shouldn't use it unless you like broken software.

## Installing
```bash
$ npm install iiegor/node-mouse
```

## Building
```bash
$ grunt
```

## API

#### ``setPosition(x, y)``

```javascript
mouse.setPosition(300, 250)
```

#### ``getPosition()``

```javascript
mouse.getPosition() //=> {x, y}
```

#### ``registerIdleHandler(time, callback)``

```javascript
// Will be called after 6 seconds of inactivity
mouse.registerIdleHandler(6000, (type) => {
  console.log(type) //=> idle
})
```

#### ``click(type)``

```javascript
mouse.click(1) //=> left click
mouse.click(2) //=> right click
```
