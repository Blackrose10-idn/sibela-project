#include "murid.h"
#include <windows.h>
#include <sql.h>
#include <sqlext.h>
#include <sqltypes.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

Murid findMuridbyPhoneNum(char PhoneNum[], SQLHDBC *dbConn)
{
    Murid foundRecord;
    SQLHSTMT stmt;
    SQLRETURN ret;
    char dateBuff[50];
    SQLUSMALLINT rowStatus[100];
    foundRecord.id_num = -1;

    SQLAllocHandle(SQL_HANDLE_STMT, *dbConn, &stmt);

    SQLPrepare(stmt, (SQLCHAR *)"SELECT * FROM murid WHERE no_hp = ?", SQL_NTS);
    SQLBindParameter(stmt, 1, SQL_PARAM_INPUT, SQL_C_CHAR, SQL_VARCHAR, strlen(PhoneNum), 0, PhoneNum, 0, NULL);
    ret = SQLExecute(stmt);

    if (SQL_SUCCEEDED(ret))
    {
        ret = SQLFetch(stmt);

        switch (ret)
        {
        case SQL_NO_DATA:
            foundRecord.id_num = -1;
            break;

        default:
            SQLGetData(stmt, 1, SQL_C_LONG,
                       &foundRecord.id_num, sizeof(foundRecord.id_num), NULL);
            SQLGetData(stmt, 2, SQL_C_CHAR,
                       &foundRecord.id_murid, sizeof(foundRecord.id_murid), NULL);
            SQLGetData(stmt, 3, SQL_C_CHAR,
                       &foundRecord.nama, sizeof(foundRecord.nama), NULL);
            SQLGetData(stmt, 4, SQL_C_CHAR,
                       dateBuff, sizeof(dateBuff), NULL);
            foundRecord.tanggal_lahir = parseDate(dateBuff);
            SQLGetData(stmt, 5, SQL_C_LONG,
                       &foundRecord.tingkat, sizeof(foundRecord.tingkat), NULL);
            SQLGetData(stmt, 6, SQL_C_CHAR,
                       dateBuff, sizeof(dateBuff), NULL);
            foundRecord.tanggal_masuk = parseDate(dateBuff);
            SQLGetData(stmt, 7, SQL_C_CHAR,
                       &foundRecord.no_hp, sizeof(foundRecord.no_hp), NULL);
            SQLGetData(stmt, 8, SQL_C_CHAR,
                       &foundRecord.password, sizeof(foundRecord.password), NULL);
            
        }
    }
    SQLFreeHandle(SQL_HANDLE_STMT, *dbConn);

    return foundRecord;
}
