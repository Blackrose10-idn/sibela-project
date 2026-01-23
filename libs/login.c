#include "login.h"

void loginFunction(windowModel *windowM)
{
    bool invalid = false;
    char email[100];
    char pass[100];
    char phoneNum[100];

    switch (windowM->currWindow)
    {
    case LOGINSTAFF:

        strcpy(email, windowM->loginData.email.text);
        strcpy(pass, windowM->loginData.password.text);

        if (strcspn(email, "@") == strlen(email) || strcspn(email, ".") == strlen(email))
        {
            windowM->loginData.email.validation.isInputInvalid = true;
            strcpy(windowM->loginData.email.validation.errMessage, "Email tidak valid!");

            invalid = true;
        }
        if (strlen(pass) <= 1)
        {
            windowM->loginData.password.validation.isInputInvalid = true;
            strcpy(windowM->loginData.password.validation.errMessage, "Kata sandi tidak valid!");

            invalid = true;
        }

        if (invalid)
            return;

        Staf loginStaf = findStafbyEmail(windowM->loginData.email.text, windowM->dbConn);

        if (loginStaf.id_num == -1)
        {
            showToast(&windowM->toast, "Kredensial salah!", "Email/Kata Sandi salah!");

            return;
        }

        if (strcmp(loginStaf.password, windowM->loginData.password.text) == 0)
        {

            strcpy(windowM->loginData.email.text, "\0");
            strcpy(windowM->loginData.password.text, "\0");
            windowM->loginData.password.charLen = 0;
            windowM->loginData.email.charLen = 0;
            windowM->loginData.phoneNumber.charLen = 0;
            strcpy(windowM->loginData.phoneNumber.text, "\0");
            windowM->loginData.activeInput = 0;

            strcpy(windowM->authUser.id, loginStaf.id_staff);
            strcpy(windowM->authUser.nama, loginStaf.nama);
            strcpy(windowM->authUser.role, loginStaf.role);
            windowM->currWindow = STAFHOME;
        }
        else
        {
            showToast(&windowM->toast, "Kredensial salah!", "Email/Kata Sandi salah!");
            return;
        }
        break;
    case LOGINMURID:
        strcpy(phoneNum, windowM->loginData.phoneNumber.text);
        strcpy(pass, windowM->loginData.password.text);

        if (strcspn(phoneNum, "0") != 0 || strlen(phoneNum) <= 10)
        {
            windowM->loginData.phoneNumber.validation.isInputInvalid = true;
            strcpy(windowM->loginData.phoneNumber.validation.errMessage, "No. Telp tidak valid!");

            invalid = true;
        }
        if (strlen(pass) <= 1)
        {
            windowM->loginData.password.validation.isInputInvalid = true;
            strcpy(windowM->loginData.password.validation.errMessage, "Kata Sandi tidak valid!");

            invalid = true;
        }
        if (invalid)
            return;

        Murid loginMurid = findMuridbyPhoneNum(windowM->loginData.phoneNumber.text, windowM->dbConn);

        if (loginMurid.id_num == -1)
        {
            showToast(&windowM->toast, "Kredensial salah!", "No. Telpon/Kata sandi salah!");

            return;
        }

        if (strcmp(loginMurid.password, windowM->loginData.password.text) == 0)
        {

            strcpy(windowM->loginData.email.text, "\0");
            strcpy(windowM->loginData.password.text, "\0");
            windowM->loginData.password.charLen = 0;
            windowM->loginData.email.charLen = 0;
            windowM->loginData.phoneNumber.charLen = 0;
            strcpy(windowM->loginData.phoneNumber.text, "\0");
            windowM->loginData.activeInput = 0;

            strcpy(windowM->authUser.id, loginMurid.id_murid);
            strcpy(windowM->authUser.nama, loginMurid.nama);
            strcpy(windowM->authUser.role, "MURID");
            windowM->currWindow = MURIDHOME;
        }
        else
        {
            showToast(&windowM->toast, "Kredensial salah!", "No. Telpon/Kata sandi salah!");

            return;
        }
        break;
    case LOGINPENGAJAR:
        strcpy(phoneNum, windowM->loginData.phoneNumber.text);
        strcpy(pass, windowM->loginData.password.text);

        if (strcspn(phoneNum, "0") != 0 || strlen(phoneNum) <= 10)
        {
            windowM->loginData.phoneNumber.validation.isInputInvalid = true;
            strcpy(windowM->loginData.phoneNumber.validation.errMessage, "No. Telp tidak valid!");

            invalid = true;
        }
        if (strlen(pass) <= 1)
        {
            windowM->loginData.password.validation.isInputInvalid = true;
            strcpy(windowM->loginData.password.validation.errMessage, "Kata sandi tidak valid!");

            invalid = true;
        }
        if (invalid)
            return;

        Pengajar loginpengajar = findPengajarbyPhoneNum(windowM->loginData.phoneNumber.text, windowM->dbConn);

        if (loginpengajar.id_num == -1)
        {
            showToast(&windowM->toast, "Kredensial salah!", "No. Telpon/Kata sandi salah!");

            return;
        }
        // printf("loginaw: %d\n", strcmp(loginpengajar.password, windowM->loginData.password.text));

        if (strcmp(loginpengajar.password, windowM->loginData.password.text) == 0)
        {

            strcpy(windowM->loginData.email.text, "\0");
            strcpy(windowM->loginData.password.text, "\0");
            windowM->loginData.password.charLen = 0;
            windowM->loginData.email.charLen = 0;
            windowM->loginData.phoneNumber.charLen = 0;
            strcpy(windowM->loginData.phoneNumber.text, "\0");
            windowM->loginData.activeInput = 0;

            strcpy(windowM->authUser.id, loginpengajar.id_pengajar);
            strcpy(windowM->authUser.nama, loginpengajar.nama);
            strcpy(windowM->authUser.role, "PENGAJAR");
            windowM->currWindow = PENGAJARHOME;
        }
        else
        {
            showToast(&windowM->toast, "Kredensial salah!", "No. Telpon/Kata sandi salah!");
            return;
        }
        break;
    }
}

void logoutFunction(windowModel *windowM)
{
    windowM->curPos = 0;
    windowM->currWindow = LANDINGPAGE;
    strcpy(windowM->authUser.id, "\0");
    strcpy(windowM->authUser.nama, "\0");
    strcpy(windowM->authUser.role, "\0");
}