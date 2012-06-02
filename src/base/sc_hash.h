#ifndef HASH_H
#define HASH_H

/*********************************************************************//**
 * \file sc_chash.h
 * Update STEPcode's hash implementation - gut it and use a standard
 * c++ implementation.
 * 
 * Original was largely based on code written by ejp@ausmelb.oz:
 * Dynamic hashing, after CACM April 1988 pp 446-457, by Per-Ake Larson.
 * Coded into C, with minor code improvements, and with hsearch(3) interface,
 * by ejp@ausmelb.oz, Jul 26, 1988: 13:16;
 * also, hcreate/hdestroy routines added to simulate hsearch(3).
 *
 ***********************************************************************/

//basic.h looks like a kludge
//#include "basic.h"  /* get basic definitions */

#include <scl_export.h>

#include "memory.h" //really necessary?

/************/
/* typedefs */
/************/

typedef enum { HASH_FIND, HASH_INSERT, HASH_DELETE } Action;


/****************/
/* abstractions */
/****************/

typedef struct Element_ {
    //char    *    key;
    char    *    data;
    //struct Element_ * next;
    Symbol  *  symbol; /**< for debugging hash conflicts */
    char       type;   /**< user-supplied type */
} * Element;

typedef Element * Segment;

// typedef struct Hash_Table_ {
// #if 0
//     int     in_use;     /**< If someone is traversing the hash table */
// #endif
//     unsigned int    p;      /**< Next bucket to be split  */
//     unsigned int    maxp;   /**< upper bound on p during expansion    */
//     long    KeyCount;       /**< current # keys   */
//     unsigned int    SegmentCount;   /**< current # segments   */
//     unsigned int    MinLoadFactor;
//     unsigned int    MaxLoadFactor;
//     Segment Directory[DIRECTORY_SIZE];
// } * Hash_Table;

typedef unsigned long int Hash_Table; //NOTE replaces the struct above

typedef struct {
//     unsigned int i;  /**< segment index (i think) */
//     unsigned int j;  /**< key index in segment (ditto) */
//     Element p;       /**< usually the next element to be returned */
    Hash_Table table;
    unsigned int pos;  ///< marks position within the table

    char search_type;  ///< used when searching for a specific type, otherwise '*'
    Element e;  /**< originally thought of as a place for
                 * the caller of HASHlist to temporarily stash the return value
                 * to allow the caller (i.e., DICTdo) to be macroized, but now
                 * conveniently used by HASHlist, which both stores the ultimate
                 * value here as well as returns it via the return value of HASHlist
                 */
} HashEntry;


/***********************/
/* function prototypes */
/***********************/
#ifdef __cplusplus
extern "C" {
#endif

 SCL_BASE_EXPORT void       HASHinitialize ( void );
 SCL_BASE_EXPORT Hash_Table HASHcreate ( unsigned int count );
///unused extern SCL_BASE_EXPORT Hash_Table HASHcopy ( Hash_Table oldtable );
 SCL_BASE_EXPORT void       HASHdestroy ( Hash_Table table );
 SCL_BASE_EXPORT Element    HASHsearch ( Hash_Table table, Element item, Action action);
 SCL_BASE_EXPORT void       HASHlistinit ( Hash_Table table, HashEntry * he );
 SCL_BASE_EXPORT void       HASHlistinit_by_type ( Hash_Table table, HashEntry * he, char type);
 SCL_BASE_EXPORT Element    HASHlist ( HashEntry * he); ///result must be stored in he.e!
 
#ifdef __cplusplus
}
#endif

#endif /*HASH_H*/
