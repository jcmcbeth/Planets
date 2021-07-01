#ifndef _CHANGES_H_
#define _CHANGES_H_

#include <time.h>

/**
 * @brief Information about a code/feature change made to the MUD.
 */
typedef struct change_data
{
    /**
     * @brief Virtual number for uniquely identifying the change.
     */
    int vnum;

    /**
     * @brief Next change in the list of changes.
     */
    CHANGE_DATA* next;

    /**
     * @brief Previous change in the list of changes.
     */
    CHANGE_DATA* prev;

    /**
     * @brief Date the change was made.
     */
    time_t date;

    /**
     * @brief Title summarizing the change.
     */
    char* title;

    /**
     * @brief Description of the change.
     */
    char* description;

    /**
     * @brief If the changes are published for everyone to view. 
     */
    bool is_published;
} CHANGE_DATA;

void do_changes(CHAR_DATA* ch, const char* argument);
void do_changeedit(CHAR_DATA* ch, const char* argument);

#endif