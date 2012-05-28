/*********************************************************************//**
 * \file sc_hash.cc
 * Update STEPcode's hash implementation - gut it and use the C++ STL.
 *
 * Original was largely based on code written by ejp@ausmelb.oz:
 * Dynamic hashing, after CACM April 1988 pp 446-457, by Per-Ake Larson.
 * Coded into C, with minor code improvements, and with hsearch(3) interface,
 * by ejp@ausmelb.oz, Jul 26, 1988: 13:16;
 * also, hcreate/hdestroy routines added to simulate hsearch(3).
 *
 ***********************************************************************/

#include "sc_hash.h"
#include <vector>
#include <map>
#include <string>

/** not used outside of hash files
GLOBAL SCL_BASE_EXPORT struct freelist_head HASH_Table_fl;
GLOBAL SCL_BASE_EXPORT struct freelist_head HASH_Element_fl;

#define HASH_Table_new()    (struct Hash_Table_ *)MEM_new(&HASH_Table_fl)
#define HASH_Table_destroy(x)   MEM_destroy(&HASH_Table_fl,(Freelist *)(Generic)x)
#define HASH_Element_new()  (struct Element_ *)MEM_new(&HASH_Element_fl)
#define HASH_Element_destroy(x) MEM_destroy(&HASH_Element_fl,(Freelist *)(char *)x)
*/

//typedefs:
// * Element
// * Segment
// * Hash_Table
// Hash_Entry

//enum Action

///unused extern  Hash_Table HASHcopy ( Hash_Table oldtable );

typedef std::map< std::string, void * > HashTable;
std::vector< HashTable > HashTables; //NOTE Hash_Table, when passed, is always one larger than the index of the referenced table. This is so that 0 can still be used for errors.

void HASHinitialize () {
    HashTables.clear();
}

//create a hash table, return the id. count was initial size; don't bother?
Hash_Table HASHcreate ( unsigned int count ) {
    HashTable * h = new HashTable;
    HashTables.push_back(*h);
    return HashTables.size(); //this is one larger than the index. this way, zero can be returned on error.
}

//delete one hashtable
void HASHdestroy ( Hash_Table table ) {
    HashTables.erase(HashTables.begin()+table-1);
}

Element HASHsearch ( Hash_Table table, Element item, Action action) {
    //TODO
    switch( action ) {
        case HASH_FIND:
            return HASHfind( table, item );
        case HASH_INSERT:
            return HASHinsert( table, item );
        case HASH_DELETE:
            return HASHdelete( table, item );
        default:
            exit( 0 );
    }
}

/**
 * initialize pointer to beginning of hash table so we can
 * step through it on repeated calls to HASHlist - DEL
 */
void HASHlistinit ( Hash_Table table, HashEntry * he ) {
    //TODO
}

void HASHlistinit_by_type ( Hash_Table table, HashEntry * he, char type) {
    //TODO
}

/* provide a way to step through the hash */
Element HASHlist ( HashEntry * he) { ///result must be stored in he.e!
    //TODO
}
