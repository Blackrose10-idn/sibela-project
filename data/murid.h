#ifndef murid
#define murid

#include <stdio.h>
#include <stdlib.h>

#include <unistd.h>
#include "../model/model.h"
#include "../libs/utils.h"
#include "../types/dbTypes.h"

Murid findMuridbyPhoneNum(char PhoneNum[], SQLHDBC *dbConn);

#endif