#include "drawView.h"

void drawRootView(windowModel *windowM)
{
    ClearBackground(TERTIARY);
    switch (windowM->currWindow)
    {
    case STAFHOME:
        // drawHeader();
        drawHome(windowM);
        break;
    case LOGINSTAFF:
        drawHeader(windowM);
        drawLogin(windowM);
        break;
    case LOGINPENGAJAR:
        drawHeader(windowM);
        drawLogin(windowM);
        break;
    case LOGINMURID:
        drawHeader(windowM);
        drawLogin(windowM);
        break;
    case ADMINSTUDENT:
        break;
    case LANDINGPAGE:
        drawHeader(windowM);
        drawLandingPage(windowM);
        break;

    case CONTRIBPAGE:
        drawMemberPage(windowM);
        break;
    }
}