#ifndef  SCHEMA_CC
#define  SCHEMA_CC
// This file was generated by fedex_plus.  You probably don't want to edit
// it since your modifications will be lost if fedex_plus is used to
// regenerate it.
/* $Id$  */
#include <schema.h>
class Registry;

void
SchemaInit( Registry & reg ) {
    extern void InitSchemasAndEnts( Registry & r );
    InitSchemasAndEnts( reg );
    extern void SdaiEXAMPLE_SCHEMAInit( Registry & r );
    SdaiEXAMPLE_SCHEMAInit( reg );
    reg.SetCompCollect( gencomplex() );
}

// Generate a function to be called by Model to help it
// create the necessary Model_contents without the
// dictionary (Registry) handle since it doesn't have a
// predetermined way to access to the handle.

SCLP23( Model_contents_ptr ) GetModelContents( char * schemaName ) {
    if( !strcmp( schemaName, "example_schema" ) ) {
        return ( SCLP23( Model_contents_ptr ) ) new SdaiModel_contents_example_schema;
    }
}
#endif
