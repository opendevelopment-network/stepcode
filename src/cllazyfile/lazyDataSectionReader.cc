#include "lazyDataSectionReader.h"
#include "lazyFileReader.h"
#include "lazyInstMgr.h"
#include <iostream>

lazyDataSectionReader::lazyDataSectionReader( lazyFileReader * parent, std::ifstream & file,
                                              std::streampos start, sectionID sid ):
                                        sectionReader( parent, file, start, sid ) {
    _sectionIdentifier = ""; //FIXME set _sectionIdentifier from the data section identifier, if present
    _error = false;
}
