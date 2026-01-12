#ifndef ABSENSI_H
#define ABSENSI_H

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include <unistd.h>

#include "../model/model.h"
// #include "../libs/utils.h"
#include "../types/dbTypes.h"
#include "../types/form.h"

void getMuridsbyJadwalPertemuan(data *datas, int *nPage, SQLHDBC *dbConn, JadwalPertemuanWithDetails *jadwal);
QUERYSTATUS createAbsensi(MuridAbsensi murids[], int nMurid, char id_pert[], SQLHDBC *dbConn, user authUser);

#endif