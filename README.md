# KB LAYOUT ----------------------------------------------------

# reduce firmware size

https://thomasbaart.nl/2018/12/01/reducing-firmware-size-in-qmk/

---

# debugging

1. use this to create log statements
   #ifdef CONSOLE_ENABLE
   uprintf("set direction");
   #endif
2. run `./hid_listen.mac` in commandline to start logging

# flash

1. build
2. flash
3. reset

# todo ---------------------------------------------------------

- add new modular file from which I import functions that I can use with marcus.

  import new mouse function?

- custom syntax / prettier ?
  ignore syntax between comments??? so that I can structure my layers freely.

- VIM TABULAR >>> can I use this to more easilly manage the qmk syntax in code???

- key > turn off rgb lights

* add / to numpad!!!

* switch disc/cont.

* add a repeat button > that makes it possible to repeat a char without double hitting it.

* mirror mouse mode for right hand.

* why are the steps of the mouse pointer not linear.

* `_BAS` add symbols to bottom layer.

* Index_finger layer?

* mod keys in all layers

* spacing keys
  enter, space, backspace, tab

* where put `RESET`

* add show mouse key >> make moure spin in cicles.

* reverse repeat.

  ---

# general thoughts and todos

- how should I do with the CMD key

  - dual with SPACE and ENTER?
  - add it to the outermost thumb keys?

## THUMBCLUSTER

- tap dance in combination with hold
  main kc, tap kc, and hold down kc.
  this will make the thumb clusters into monsters

# RNDM

the best thing about the reset button is that it allows you to learn much better.
since you can test every scenario as many times as you want.
