#include "./dateRange.h"
#include "../../libs/headers/raygui.h"

void dateRangeSelector(windowModel *windowM, Vector2 position)
{
    struct tm *now = localtime(&windowM->time);
    char fromText[] = "Dari:";
    char toText[] = "Ke:";
    Vector2 fromTextlen = MeasureTextEx(windowM->fontStyle.regular, fromText, 32, 0);

    Rectangle fromMonth = {.height = 40, .width = 60, .x = position.x + fromTextlen.x + 5, .y = position.y};

    DrawTextEx(windowM->fontStyle.regular, fromText, (Vector2){position.x, position.y + 5}, 32, 0, SIBELAWHITE);
    DrawTextEx(windowM->fontStyle.regular, toText, (Vector2){position.x, position.y + 50 + 5}, 32, 0, SIBELAWHITE);

    if (GuiButton(fromMonth, TextFormat("%d", windowM->datas.dateRange.monthFrom), 0))
    {
        if (windowM->datas.dateRange.yearFrom <= now->tm_year + 1900)
        {
            if (windowM->datas.dateRange.monthFrom < 12)
                windowM->datas.dateRange.monthFrom++;
            else
                windowM->datas.dateRange.monthFrom = 1;
        }
        else
        {
            if (windowM->datas.dateRange.monthFrom < now->tm_mon + 1)
                windowM->datas.dateRange.monthFrom++;
            else
                windowM->datas.dateRange.monthFrom = 1;
        }
        windowM->dataFetchers.staffPage[windowM->selectedPage](&windowM->datas, &windowM->datas.totalPages, windowM->dbConn, &windowM->authUser);
    }
    Rectangle fromYearMin = {.height = 40, .width = 40, .x = fromMonth.x + fromMonth.width + 10, .y = position.y};
    if (GuiButton(fromYearMin, "-", 0))
    {
        windowM->datas.dateRange.yearFrom--;
        windowM->dataFetchers.staffPage[windowM->selectedPage](&windowM->datas, &windowM->datas.totalPages, windowM->dbConn, &windowM->authUser);
    }
    Rectangle fromYear = {.height = 40, .width = 100, .x = fromYearMin.x + fromYearMin.width + 5, .y = position.y};
    if (GuiButton(fromYear, TextFormat("%d", windowM->datas.dateRange.yearFrom), 0))
    {
    }
    Rectangle fromYearPlus = {.height = 40, .width = 40, .x = fromYear.x + fromYear.width + 5, .y = position.y};
    if (GuiButton(fromYearPlus, "+", 0))
    {
        if (windowM->datas.dateRange.yearFrom < now->tm_year + 1900)
            windowM->datas.dateRange.yearFrom++;

        windowM->dataFetchers.staffPage[windowM->selectedPage](&windowM->datas, &windowM->datas.totalPages, windowM->dbConn, &windowM->authUser);
    }

    Rectangle toMonth = {.height = 40, .width = 60, .x = position.x + fromTextlen.x + 5, .y = position.y + 50};
    if (GuiButton(toMonth, TextFormat("%d", windowM->datas.dateRange.monthTo), 0))
    {
        if (windowM->datas.dateRange.yearFrom <= now->tm_year + 1900)
        {
            if (windowM->datas.dateRange.monthTo < 12)
                windowM->datas.dateRange.monthTo++;
            else
                windowM->datas.dateRange.monthTo = 1;
        }
        else
        {
            if (windowM->datas.dateRange.monthTo < now->tm_mon + 1)
                windowM->datas.dateRange.monthTo++;
            else
                windowM->datas.dateRange.monthTo = 1;
        }
        windowM->dataFetchers.staffPage[windowM->selectedPage](&windowM->datas, &windowM->datas.totalPages, windowM->dbConn, &windowM->authUser);
    }
    Rectangle toyearMin = {.height = 40, .width = 40, .x = toMonth.x + toMonth.width + 10, .y = position.y + 50};
    if (GuiButton(toyearMin, "-", 0))
    {
        if (windowM->datas.dateRange.yearFrom < windowM->datas.dateRange.yearTo)
            windowM->datas.dateRange.yearTo--;
        windowM->dataFetchers.staffPage[windowM->selectedPage](&windowM->datas, &windowM->datas.totalPages, windowM->dbConn, &windowM->authUser);
    }
    Rectangle toYear = {.height = 40, .width = 100, .x = toyearMin.x + toyearMin.width + 5, .y = position.y + 50};
    if (GuiButton(toYear, TextFormat("%d", windowM->datas.dateRange.yearTo), 0))
    {
    }
    Rectangle toYearPlus = {.height = 40, .width = 40, .x = toYear.x + toYear.width + 5, .y = position.y + 50};
    if (GuiButton(toYearPlus, "+", 0))
    {
        if (windowM->datas.dateRange.yearTo < now->tm_year + 1900)
            windowM->datas.dateRange.yearTo++;
        windowM->dataFetchers.staffPage[windowM->selectedPage](&windowM->datas, &windowM->datas.totalPages, windowM->dbConn, &windowM->authUser);
    }
}