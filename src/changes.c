#include <stdio.h>

#include "mud.h"
#include "changes.h"

CHANGE_DATA* first_change;
CHANGE_DATA* last_change;

void do_changes(CHAR_DATA* ch, const char* argument)
{
    CHANGE_DATA* change;
    int count = 0;

    set_char_color(AT_WHITE, ch);
    send_to_char("Ref #     Date        Title\n\r", ch);

    for (change = first_change; change != NULL; change = change->next)
    {
        ch_printf(ch, "%d%s%s", change->vnum, NULL, change->title);


        count++;
    }

    if (count == 0)
    {
        set_char_color(AT_YELLOW, ch);
        send_to_char("No changes have been documented.");
    }    
}

CHANGE_DATA* get_change(const char* argument)
{
    return NULL;
}

void do_changeedit(CHAR_DATA* ch, const char* argument)
{
    CHANGE_DATA* change;

    if (ch->desc == NULL)
    {
        send_to_char("You have no descriptor.\n\r", ch);
        return;
    }

    if (ch->substate == SUB_CHANGE_DESC)
    {
        return;
    }

    switch (ch->substate)
    {
        default:
            break;
        case SUB_CHANGE_DESC:
            return;
    }

    /*
    * changeedit create <title>
    * changeedit delete <vnum>
    * changeedit edit <vnum> <field>
    * changeedit list
    * changeedit publish
    */

    change = get_change(ch, argument);
    if (change == NULL)
    {
        CREATE(change, CHANGE_DATA, 1);

        //LINK(change, first_change, last_change, next, prev);        
    }

    ch->substate = SUB_CHANGE_DESC;
    ch->dest_buf = change;

    start_editing(ch, change->description);
}

void save_changes()
{

}

void load_change_file(CHANGE_DATA* changes, const char* filename)
{

}

void load_changes(CHANGE_DATA* changes, FILE* file)
{

}