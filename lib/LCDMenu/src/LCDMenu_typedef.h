/* ******************************************************************************
 *                        LCDMenu (LCDML)
 * ******************************************************************************
 */

#ifndef _LCDML_typedef_h
    #define _LCDML_typedef_h

    typedef void    (* LCDML_FuncPtr)       ();
    typedef void    (* LCDML_FuncPtr_pu8)   (uint8_t);  // with parameter u8
    typedef boolean (* LCDML_FuncPtr_rb)    ();         // with return value boolean

#endif
