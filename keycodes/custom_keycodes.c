enum custom_keycodes {
  RGB_SLD = EZ_SAFE_RANGE,
  DUMMY,
  BTL_INNER,
  BTR_INNER,
  BTL_OUTER,
  BTR_OUTER,
  PDIR1,
  PDIR2,
  PDIR3,
  PDIR4,
  PDIR5,
  PDIR6,
  PDIR7,
  PDIR8,
  PDIR9,
  PDIR10,
  PDIR11,
  PDIR_LAST,
  PVEL1,
  PVEL2 = PVEL1 + 3,
  PVEL3 = PVEL2 + 6,
  PVEL_LAST = PVEL3 + 10,
};

////Hacker Dvorak below
//
//// Define custom user keycodes:
//enum custom_keycodes {
//    PLACEHOLDER = SAFE_RANGE,  // Can always be here.
//    MY_CUSTOM_MACRO,           // Custom macro example.
//    MY_OTHER_MACRO,            // Custom macro example.
//    DYNAMIC_MACRO_RANGE        // Should always be the last.
//};