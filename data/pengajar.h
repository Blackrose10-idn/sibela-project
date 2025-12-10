#ifndef pengajar
#define pengajar

#include <stdio.h>
#include <stdlib.h>

#include <unistd.h>
#include "../model/model.h"
#include "../libs/utils.h"
#include "../types/dbTypes.h"

Pengajar findPengajarbyPhoneNum(char PhoneNum[], SQLHDBC *dbConn);

#endif