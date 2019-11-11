/* ******************************************************************************
 *                        LCDMenu (LCDML)
 * ******************************************************************************
 */

#ifndef LCDMenu_menu_h
#   define LCDMenu_menu_h

#   include "Arduino.h"
#   include "LCDMenu_typedef.h"

    #define _LCDML_menu_f7          7
    #define _LCDML_menu_f6          6
    #define _LCDML_menu_f5          5
    #define _LCDML_menu_f4          4
    #define _LCDML_menu_f3          3
    #define _LCDML_menu_f2          2
    #define _LCDML_menu_dynParam    1
    #define _LCDML_menu_default     0


    class LCDMenu_menu
    {
        private:
            LCDMenu_menu * parent;                               // Parent menu, NULL if this is the top
            LCDMenu_menu * child;                                // First child menu, NULL if no children
            LCDMenu_menu * sibling;                              // Next sibling menu, NULL if this is the last sibling

            LCDML_FuncPtr_pu8 cb_function;                          // Menu Function callback
            LCDML_FuncPtr_rb  cb_condition;                         // Menu Condition callback

            void setParent(LCDMenu_menu &p);                     // Sets the menu's parent to p
            void addSibling(LCDMenu_menu &s,LCDMenu_menu &p); // Adds a sibling s with parent p.  If the menu already has a sibling, ask that sibling to add it

            uint8_t id;                                             // Name of this menu
            uint8_t param;
            uint8_t configuration;

        public:
             // Constructs the menu with a name and a NULL use function (be careful calling it)
            LCDMenu_menu(uint8_t p_id, uint8_t p_param, uint8_t p_configuration, LCDML_FuncPtr_pu8 p_callback_function, LCDML_FuncPtr_rb p_condition_function);

            LCDML_FuncPtr_pu8 getCbFunction();

            void addChild(LCDMenu_menu &c);                      // Adds the child c to the menu.
                                                                    // If the menu already has a child, ask the child to add it as a sibling
            LCDMenu_menu * getChild(uint8_t which);              // Returns a pointer to the which'th child of this menu
            LCDMenu_menu * getSibling(uint8_t howfar);           // Returns a pointer to the sibling how far siblings away from this menu
            LCDMenu_menu * getParent();                          // Returns this menu's parent menu.  If no parent, returns itself

            uint8_t getID();                                        // return the id of a menu element
            boolean checkCondition();                                 // check menu display condition
            uint8_t getParam();                                     // return a parameter which is set on the initialization
            boolean checkType_menu();
            boolean checkType_dynParam();

            void callback(uint8_t p);                                        // call menu callback
            boolean checkCallback();                                  // check if callback can called
    };
#endif
