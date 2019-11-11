/* ******************************************************************************
 *                        LCDMenu (LCDML)
 * ******************************************************************************
 */

#include "LCDMenu_menu.h"
#include "LCDMenu_typedef.h"


/* ******************************************************************** */
LCDMenu_menu::LCDMenu_menu(uint8_t p_id, uint8_t p_param, uint8_t p_configuration, LCDML_FuncPtr_pu8 p_callback_function, LCDML_FuncPtr_rb p_condition_function)
/* ******************************************************************** */
{
    parent  = NULL;
    sibling = NULL;
    child   = NULL;
    id      = p_id;        // element name
    param   = p_param;     // element configuration
    configuration= p_configuration;
    cb_function = p_callback_function;
    cb_condition = p_condition_function;
}

/* ******************************************************************** */
void LCDMenu_menu::setParent(LCDMenu_menu &p)
/* ******************************************************************** */
{
    parent = &p;
}

/* ******************************************************************** */
void LCDMenu_menu::addSibling(LCDMenu_menu &s,LCDMenu_menu &p)
/* ******************************************************************** */
{
    if (sibling)
    { // add sibling if sibling exists
        sibling->addSibling(s,p);
    }
    else
    { // add sibling and parent
        sibling =& s;
        sibling->setParent(p);
    }
}

/* ******************************************************************** */
void LCDMenu_menu::addChild(LCDMenu_menu &c)
/* ******************************************************************** */
{
    if (child)
    { // add sibling if child exists
        child->addSibling(c,*this);
    }
    else
    { // add child  and parent
        child=&c;
        child->setParent(*this);
    }
}

/* ******************************************************************** */
LCDMenu_menu * LCDMenu_menu::getChild(uint8_t which)
/* ******************************************************************** */
{
    if (child)
    { // return child if exists
        return child->getSibling(which);
    }
    else
    { // this menu item has no children
        return NULL;
    }
}

/* ******************************************************************** */
LCDMenu_menu * LCDMenu_menu::getSibling(uint8_t howfar)
/* ******************************************************************** */
{
    if (howfar == 0)
    { // this sibling
        return this;
    }
    else if (sibling)
    {    // get next sibling
        return sibling->getSibling(howfar - 1);
    }
    else
    { // asking for a nonexistent sibling
        return NULL;
    }
}

/* ******************************************************************** */
LCDMenu_menu * LCDMenu_menu::getParent()
/* ******************************************************************** */
{
    if (parent)
    { // get parent if exists
        return parent;
    }
    else
    { // root menu
        return this;
    }
}

/* ******************************************************************** */
uint8_t LCDMenu_menu::getID()
/* ******************************************************************** */
{
    return id;
}

/* ******************************************************************** */
boolean LCDMenu_menu::checkCondition()
/* ******************************************************************** */
{
    if(cb_condition != NULL)
    {
        return cb_condition();
    }
    else
    {
        return true;
    }
}

/* ******************************************************************** */
LCDML_FuncPtr_pu8 LCDMenu_menu::getCbFunction()
/* ******************************************************************** */
{
    return cb_function;
}

/* ******************************************************************** */
uint8_t LCDMenu_menu::getParam()
/* ******************************************************************** */
{
    return param;
}

/* ******************************************************************** */
void LCDMenu_menu::callback(uint8_t p)
/* ******************************************************************** */
{
    if(cb_function != NULL)
    {
        cb_function(p);
    }
}

/* ******************************************************************** */
boolean LCDMenu_menu::checkCallback()
/* ******************************************************************** */
{
    if(cb_function == NULL)
    {
        return false;
    }
    else
    {
        return true;
    }
}

/* ******************************************************************** */
boolean LCDMenu_menu::checkType_menu()
/* ******************************************************************** */
{
    if(bitRead(configuration, _LCDML_menu_default))
    {
        return true;
    }
    else
    {
        return false;
    }
}

/* ******************************************************************** */
boolean LCDMenu_menu::checkType_dynParam()
/* ******************************************************************** */
{
    if(bitRead(configuration, _LCDML_menu_dynParam))
    {
        return true;
    }
    else
    {
        return false;
    }
}
