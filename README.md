================================================
KB LAYOUT
================================================


debugging
================================================

1. use this to create log statements
  #ifdef CONSOLE_ENABLE
      uprintf("set direction");
  #endif
2. run `./hid_listen.mac` in commandline to start logging




todo
================================================

- move continuous pointer function to its own file for reference. so i don't forget
- make LSY och RNU into one layer
- move high pinky to outer most keys
    conflict w/ ESC
- add reset state to ESC?
    can this be done easily?
- add layer on index finger
- add all mod keys for symbol/numpad layer.
- add more keys to top row on base layer
  replace numbers since I cannot reach all keys easilly
- remove as much stuff as possible

# types of buttons that I need to configure

  - modifier keys
      need access to mod keys in each layer -> for komplex key commands and mods + mouse

  - navigation
      mouse hard switch
      put mouse buttons on left outer keys?
        and use thumb clusters for more important stuff
      put nav buttons on LOWEST row in BASE layer

  - spacing keys
      enter, space, backspace, tab


# general thoughts and todos

- how should I do with the CMD key
    * dual with SPACE and ENTER?
    * add it to the outermost thumb keys?
    *

- REAL ESTATE layer switches
    use the LT layer switch to create a layer switching router.
      I don't know how useful this would be but this would make it possible to access all other layers
        by a 2-step sequence.

## THUMBCLUSTER
  - tap dance in combination with hold
      main kc, tap kc, and hold down kc.
        this will make the thumb clusters into monsters


RNDM
====================================


